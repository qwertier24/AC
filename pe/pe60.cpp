#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

const int n=10000;
int m;
vector<int> p;
int len[n+10];
int p10[9]={1e0,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8};
bitset<n> e[n];
int getlen(int n){
  int ret=0;
  while(n){
    n/=10;
    ret++;
  }
  return ret;
}
inline bool is_prime(int n){
  for(int i=2; i*i<=n; i++)
    if(n%i==0)
      return false;
  return true;
}
int ans=1<<30;
void dfs(bitset<n> cur,int st,int cnt,int sum){
  if(cnt==5){
    ans=min(ans,sum);
    return;
  }
  for(int i=st; i<m; i++)
    if(cur[i])
      dfs(cur&e[i],i,cnt+1,sum+p[i]);
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  for(int i=2; i<=n; i++){
    if(is_prime(i))
      p.push_back(i);
  }
  m=p.size();
  REP(i,m)len[i]=getlen(p[i]);
  REP(i,m)REP(j,m)
    if(is_prime(p[i]*p10[len[j]]+p[j]) && is_prime(p[j]*p10[len[i]]+p[i])){
      e[i][j]=1;
      //printf("%d %d\n",p[i],p[j]);
    }
  bitset<n> ini;
  REP(i,m)ini[i]=1;
  dfs(ini,0,0,0);
  printf("%d\n",ans);
  return 0;
}
