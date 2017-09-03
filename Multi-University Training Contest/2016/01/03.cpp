#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
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

#define N 1010

int n, m;
int g[N][N];
char s[N];
LL sum[N], cnt[N], row[N], col[N], curc[N], curs[N], colt[N];

int calc2(int flag) {
  int ret = 0;
  for (int i = 1; i <= n; ) {
    int j = i;
    if (!row[i]) {
      i++;
      continue;
    }
    int s = 0;
    while (j <= n && row[j] != 0 && (j == i || row[j] > row[j-1])) {
      s += row[j] - 1;
      //printf("%d %d %d\n", j, m-row[j], s);
      if (flag) {
        ret += 2 * (m-row[j]) * s;
      } else {
        ret += 2 * (m-row[j]) * (s - row[j] + 1);
      }
      j++;
    }
    i = j;
  }
  err(ret);
  return ret;
}
int calc() {
  int ret = 0;
  ret += calc2(0);
  FOR (i, n) {
    if (row[i]) 
      row[i] = m - row[i] + 1;
  }
  ret += calc2(1);
  FOR (i, n) {
    if (row[i])
      row[i] = m - row[i] + 1;
  }
  return ret;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    FOR (i, n) {
      scanf("%s", s+1);
      FOR (j, m) {
        g[i][j] = (s[j] == 'G');
      }
    }
    FOR (i, n) {
      FOR (j, m) {
        if (g[i][j]) {
          row[i] = j;
        }
      }
    }
    FOR (j, m) {
      FOR (i, n) {
        if (g[i][j]) {
          col[j] = i;
        }
      }
    }
    LL ans = 0;
    memset(sum, 0, sizeof(sum));
    memset(cnt, 0, sizeof(cnt));
    FOR (i, n) {
      memset(curs, 0, sizeof(LL)*(m+2));
      memset(curc, 0, sizeof(LL)*(m+2));
      FOR (j, m) {
        curs[j] = curs[j-1] + (!g[i][j]?i+j:0);
        curc[j] = curc[j-1] + (!g[i][j]);
        sum[j] += curs[j];
        cnt[j] += curc[j];
        if (!g[i][j]) {
          ans += cnt[j] * (i+j) - sum[j];
        }
      }
    }
    int ans_cnt = cnt[m];
    err(ans_cnt);
    memset(sum, 0, sizeof(sum));
    memset(cnt, 0, sizeof(cnt));
    FOR (i, n) {
      memset(curs, 0, sizeof(LL)*(m+2));
      memset(curc, 0, sizeof(LL)*(m+2));
      FOR (j, m) {
        if (!g[i][j]) {
          ans += cnt[j+1] * (i-j) - sum[j+1];
        }
      }
      for (int j = m; j >= 1; j--) {
        curs[j] = curs[j+1] + (!g[i][j]?i-j:0);
        curc[j] = curc[j+1] + (!g[i][j]);
        sum[j] += curs[j];
        cnt[j] += curc[j];
      }
    }
    /*
    int tmp = 0;
    FOR (x, n) {
      FOR (y, m) {
        FOR (i, n) {
          FOR (j, m) {
            if (!g[x][y] && !g[i][j]) {
              tmp += abs(x-i) + abs(y-j);
            }
          }
        }
      }
    }
    err(ans);
    err(tmp);
    */
    
    REP (k, 2) {
      ans += calc();
      FOR (i, n) {
        colt[n-i+1] = row[i];
      }
      FOR (i, m) {
        if (col[i]) 
          row[i] = n - col[i] + 1;
        else
          row[i] = 0;
      }
      FOR (i, n) {
        col[i] = colt[i];
      }
      swap(n, m);
    }
    err(ans);
    printf("%.4f\n", ans*2/(double)(ans_cnt*(LL)ans_cnt));
  }
  return 0;
}
