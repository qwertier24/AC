#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<math.h>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 100010

int n,p,q;
pii pro[N];

LL cross(int x1,int y1,int x2,int y2){
  return x1*(LL)y2 - x2*(LL)y1;
}
double cross2(double x1,double y1,double x2,double y2){
  return x1*y2-x2*y1;
}
bool check(pii c, pii b, pii a){
  return cross(b.first-a.first,b.second-a.second,c.first-b.first,c.second-b.second)>=0;
}
#define eps 1e-9
#define leq(x,y) (y-x>=-eps)

pii st[N];
int tp=-1;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d",&n,&p,&q);
  int maxa=0,maxb=0;
  FOR(i,n){
    scanf("%d%d",&pro[i].first,&pro[i].second);
    maxa=max(maxa,pro[i].first);
    maxb=max(maxb,pro[i].second);
  }
  sort(pro+1,pro+n+1);
  st[++tp]=MP(0,maxb);
  FOR(i,n){
    while(tp>0 && check(pro[i],st[tp],st[tp-1]))
      tp--;
    st[++tp]=pro[i];
  }
  st[++tp]=MP(maxa,0);
  int line;
  REP(i,tp){
    if(leq(atan2(st[i+1].second,st[i+1].first), atan2(q,p)) && leq(atan2(q,p), atan2(st[i].second,st[i].first)))
      line=i;
  }
  double lo=0,hi=1e6;
  while(lo<hi-eps){
    double mi=(lo+hi)/2;
    if(leq(cross2(p/mi-st[line].first,q/mi-st[line].second,p/mi-st[line+1].first,q/mi-st[line+1].second),0))
      hi=mi;
    else
      lo=mi;
  }
  printf("%.10f\n",lo);
  return 0;
}
