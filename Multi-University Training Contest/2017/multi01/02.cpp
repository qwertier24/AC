#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))  // Leading zeros
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#ifdef QWERTIER
#define err(x) cerr << #x << " : " << x << endl
#else
#define err(x)
#endif

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 100010
#define MOD (1000000007)

int n;
char *s[N], t[N];
int len[N];
int cnt[26][N+10], id[26], maxc[26];
bool cmp(const int &i, const int &j) {
  for (int k = max(maxc[i], maxc[j]); k >= 0; k--)
    if (cnt[i][k] != cnt[j][k])
      return cnt[i][k] < cnt[j][k];
  return false;
}
bool check(int c) {
  FOR (i, n) {
    if (s[i][0] == 'a' + c && len[i] != 1)
      return false;
  }
  return true;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  while (scanf("%d", &n) != EOF) {
    memset(maxc, 0, sizeof(maxc));
    FOR (i, n) {
      scanf("%s", t);
      len[i] = strlen(t);
      s[i] = new char[len[i] + 10];
      strcpy(s[i], t);
    }
    FOR (i, n) {
      for (int j = len[i] - 1; j >= 0; j--) {
        cnt[s[i][j]-'a'][len[i]-j-1]++;
        maxc[s[i][j]-'a'] = max(maxc[s[i][j]-'a'], len[i]-j-1);
      }
    }
    for (int i = 0; i < 26; i++) {
      id[i] = i;
      for (int j = 0; j <= maxc[i] + 10; j++) {
        if (cnt[i][j] > 0) {
          cnt[i][j+1] += cnt[i][j] / 26;
          cnt[i][j] %= 26;
          // printf("%d %d %d\n", i, j, cnt[i][j]);
          maxc[i] = max(maxc[i], j);
        }
      }
    }
    sort(id, id+26, cmp);
    int ans = 0;
    for (int fc = 0; fc < 26; fc++) {
      int id2[26];
      if (check(id[fc])) {
        id2[0] = id[fc];
        // printf("0;%d\n", id2[0]);
        int tot = 1;
        for (int i = 0; i < 26; i++) {
          if (id[i] != id[fc])
            id2[tot++] = id[i];
        }
        // for (int i = 0; i < 26; i++)
        //   printf("%d\n", id2[i]);
        for (int i0 = 0; i0 < 26; i0++) {
          int i = id2[i0];
          LL p = 1;
          for (int j = 0; j <= maxc[i]; j++) {
            ans = (ans + p * (LL)cnt[i][j] % MOD * (LL)i0 % MOD) % MOD;
            // if (cnt[i][j] > 0) {
            //   printf("%d %d %d\n", i, j, cnt[i][j]);
            // }
            p = p * 26 % MOD;
          }
        }
        break;
      }
    }
    static int kase = 1;
    cout << "Case #" << kase++ << ": " << ans << endl;
    FOR (i, n) {
      delete[] s[i];
    }
    REP (i, 26)
      memset(cnt[i], 0, sizeof(int)*(maxc[i]+5));
  }
  return 0;
}
