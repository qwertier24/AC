#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<iostream>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
#define MP make_pair

#define gcd __gcd
pll reduce(LL x,LL y){
  LL g=gcd(x,y);
  if(g!=0){
    x/=g;
    y/=g;
    if(x<0 || (x==0 && y<0))x*=-1,y*=-1;
  }
  return MP(x,y);
}

#define N 2010
int n;
pii x[N],y[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  FOR(i,n){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    x[i]=MP(a*c,a*a+b*b);
    y[i]=MP(b*c,a*a+b*b);
  }
  LL ans=0;
  FOR(i,n){
    map<pll,int> cnt;
    int zero=0;
    for(int j=i+1; j<=n; j++){
      LL xt = x[j].first*(LL)x[i].second - x[i].first*(LL)x[j].second,
        yt = y[j].first*(LL)y[i].second - y[i].first*(LL)y[j].second;
      pll pt=reduce(xt,yt);
      if(pt.first==0 && pt.second==0){
        ans+=j-i-1;
        zero+=1;
      }else{
        ans+=zero+(cnt[pt]++);
      }
    }
  }
  cout<<ans;
  return 0;
}
