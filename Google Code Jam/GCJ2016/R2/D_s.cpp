#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<bitset>
#include<iostream>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 30

int n;

int count(int S){
    int ret = 0;
    while(S){
        ret += S&1;
        S>>=1;
    }
    return ret;
}

int mark[N];
bitset<N> st[N], can[N];
int sz[N], pa[N];
int findset(int u){
    if(pa[u] != u)
        pa[u] = findset(pa[u]);
    return pa[u];
}
bool check(int S){
    memset(mark, 0, sizeof(mark));
    //cout<<S<<endl;
    REP(i,n){
        REP(j,n){
            if((S>>(i*n+j))&1)
                mark[j]  =1;
            can[i][j] = (S>>(i*n+j)) & 1;
        }
        //cout<<can[i].to_string()<<endl;
    }
    REP(i,n)
        if(!mark[i])
            return false;
    REP(i,n)
        pa[i] = i, sz[i] = 1;
    REP(i,n)REP(j,n)
        if((can[i] & can[j]).count()){
            if(findset(i) == findset(j))
                continue;
            if(can[i] != can[j])
                return false;
            sz[pa[i]] += sz[pa[j]];
            pa[pa[j]] = pa[i];
        }
    //cout<<can[0].count()<<' '<<sz[0]<<endl;
    REP(i,n)
        if(can[findset(i)].count() != sz[findset(i)])
            return false;
    return true;
}
int main(){
#ifdef QWERTIER
  freopen("D_s.in","r",stdin);
  freopen("D_s.out","w",stdout);
#endif 
  int T;
  scanf("%d",&T);
  FOR(kase,T){
      printf("Case #%d: ",kase);
      scanf("%d",&n);
      int tot = 0;
      REP(i,n){
          can[i].reset();
          char s[20];
          scanf("%s",s);
          REP(j,n){
              //can[i][j] = s[j]-'0';
              tot += (s[j]-'0')<<(i*n+j);
          }
      }
      /*
      REP(i,n)
          st[i] = can[i], pa[i] = i;
      REP(i,n)REP(j,n)
          if(can[i] | can[j]){
              if(findset(i) == findset(j))
                  continue;
              st[pa[i]] |= st[pa[j]];
              pa[pa[j]] = pa[i];
          }
      */
      int ans = 1<<20;
      REP(S,(1<<(n*n))){
          if((S&tot) == tot && check(S)){
              ans = min(ans, count(S) - count(tot));
          }
      }
      printf("%d\n",ans);
  }
  return 0;
}
