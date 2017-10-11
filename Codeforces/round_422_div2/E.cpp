#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
#define FI first
#define SE second
#define VI vector<int>
#define CLR(x) memset(x, 0, sizeof(x))
#define SZ(x) (x.size())
#ifdef QWERTIER
#define err(x) cerr<<x<<endl;
#else
#define err(x)
#endif

int n, m, x;
#define N 200010
char s[N];
namespace SA{
  int len, sigma;
  int sa[N], cnt[N], *x = new int[N], *y = new int[N];
  inline bool eq(int i,int j){
    return (i>=len && j>=len)||(i<len && j<len && y[i]==y[j]);
  }
  void calc_sa(){
    memset(cnt, 0, sizeof(int)*sigma);
    REP(i,len)cnt[x[i]=s[i]-'a']++;
    FOR(i,sigma-1)cnt[i]+=cnt[i-1];
    for(int i=len-1; i>=0; i--)sa[--cnt[x[i]]]=i;
    for(int k=1; k<=len; k<<=1){
      int p=0;
      for(int i=len-k; i<len; i++)y[p++]=i;
      REP(i,len)if(sa[i]>=k)y[p++]=sa[i]-k;

      REP(i,sigma)cnt[i]=0;
      REP(i,len)cnt[x[y[i]]]++;
      FOR(i,sigma-1)cnt[i]+=cnt[i-1];
      for(int i=len-1; i>=0; i--)sa[--cnt[x[y[i]]]]=y[i];

      swap(x,y);
      x[sa[0]]=0;
      p=1;
      FOR(i,len-1)
        x[sa[i]]=eq(sa[i],sa[i-1])&&eq(sa[i]+k,sa[i-1]+k)?p-1:p++;
      if(p>=len)break;
      sigma=p;
    }
  }
  int h[N];
  void calc_hi(){
    int j,k=0;
    REP(i,len){
      if(x[i]==0){k=0;continue;}
      if(k)k--;
      j=sa[x[i]-1];
      while(s[i+k]==s[j+k])k++;
      h[x[i]]=k;
    }
  }
  void test() {
    REP (i, len) {
      printf("%s %d\n", s+sa[i], h[i]);
    }
  }
  #define L 20
  int minv[N][L];
  void init_lcp() {
    REP (i, len) {
      minv[i][0] = h[i];
    }
    for (int j = 1; j < L; j++) {
      for (int i = 0; i+(1<<j)-1 < len; i++) {
        minv[i][j] = min(minv[i][j-1], minv[i+(1<<(j-1))][j-1]);
      }
    }
  }
  int lcp(int i, int j) {

    // printf("%d %d\n",i, j);
    i = x[i], j = x[j];
    int x = min(i, j),
      y = max(i, j);
    i = x, j = y;
    i++;

    int l = 0;
    while ((1<<(l+1)) <= j-i+1)
      l++;
    // printf("%d\n", min(minv[j-(1<<l)+1][l], minv[i][l]));
    return min(minv[j-(1<<l)+1][l], minv[i][l]);
  }
}

int dp[N][32];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  scanf("%s", s);
  s[n] = 'a' + 26;

  scanf("%d", &m);
  scanf("%s", s+n+1);

  scanf("%d", &x);

  SA::len = n+m+1;
  SA::sigma = 27;
  SA::calc_sa();
  SA::calc_hi();
  SA::init_lcp();
  // SA::test();


  REP (i, n) {
    REP (j, x+1) {
      // printf("%d %d %d ", i, j, dp[i][j]);
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      if (dp[i][j] < m) {
        int l = SA::lcp(i, dp[i][j]+n+1);
        // printf("%d", l);
        dp[i+l][j+1] = max(dp[i+l][j+1], dp[i][j]+l);
      }
      // puts("");
    }
  }
  REP (j, x+1)
    if (dp[n][j] == m) {
      puts("YES");
      return 0;
    }
  puts("NO");
  return 0;
}
