#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,LL> pii;
#define MP make_pair
map<LL,pii> mp;
inline LL cube(LL x){
  return x*x*x;
}
inline LL change(LL x){
  int cnt[10]={0};
  while(x){
    cnt[x%10]++;
    x/=10;
  }
  LL ret=0;
  for(int i=9; i>=0; i--)
    REP(j,cnt[i])
      ret=ret*10+i;
  return ret;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  FOR(i,(1e6)){
    if(!mp.count(change(cube(i))))
      mp[change(cube(i))]=MP(1,cube(i));
    else
      mp[change(cube(i))].first++;
  }
  LL ans=1ll<<60;
  for(map<LL,pii>::iterator it = mp.begin(); it!=mp.end(); ++it){
    pii tmp=it->second;
    if((it->second).first == 5 && ans > (it->second).second){
      ans=(it->second).second;
    }
  }
  printf("%lld\n",ans);
  return 0;
}
