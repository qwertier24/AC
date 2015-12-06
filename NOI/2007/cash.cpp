#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define eps 1e-7

using namespace std;
#define N 100010
struct Tran{
  double f,g;
}cash[N],tmp[N];

int id[N],t[N],st[N],tp;
double ans,profit[N],a[N],b[N],ra[N];
void calc(int l,int r){
  if(l==r){
    ans=max(ans,profit[l]);
    cash[l].g=ans/(a[l]*ra[l]+b[l]);
    cash[l].f=cash[l].g*ra[l];
    return;
  }
  int mid=(l+r)>>1,lp=l,rp=mid+1;
  REP(i,l,r){
    if(id[i]<=mid)
      t[lp++]=id[i];
    else
      t[rp++]=id[i];
  }
  memcpy(id+l,t+l,sizeof(int)*(mid-l+1));
  memcpy(id+mid+1,t+mid+1,sizeof(int)*(r-mid));
  calc(l,mid);
  tp=0;
  REP(i,l,mid){
    while(tp>1 && (cash[i].g-cash[st[tp-1]].g)*(cash[st[tp]].f-cash[st[tp-1]].f)>=(cash[st[tp]].g-cash[st[tp-1]].g)*(cash[i].f-cash[st[tp-1]].f))
      tp--;
    st[++tp]=i;
  }
  int bo=1;
  REP(i,mid+1,r){
    while(bo<tp && (cash[st[bo+1]].f*a[id[i]]+cash[st[bo+1]].g*b[id[i]])>=(cash[st[bo]].f*a[id[i]]+cash[st[bo]].g*b[id[i]]))
      bo++;
    profit[id[i]]=max(profit[id[i]],cash[st[bo]].f*a[id[i]]+cash[st[bo]].g*b[id[i]]);
  }
  calc(mid+1,r);
  memcpy(tmp+l,cash+l,sizeof(Tran)*(mid+1-l));
  memcpy(tmp+mid+1,cash+mid+1,sizeof(Tran)*(r-mid));
  lp=l,rp=mid+1;
  REP(i,l,r){
    if(lp<=mid && (rp>r || tmp[lp].f<tmp[rp].f)){
      cash[i]=tmp[lp];
      lp++;
    }else{
      cash[i]=tmp[rp];
      rp++;
    }
  }
}
inline bool cmp(const int& i,const int& j){
  return -a[i]/b[i]>-a[j]/b[j];
}

int n;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%lf",&n,&ans);
  REP(i,1,n){
    id[i]=i;
    scanf("%lf%lf%lf",&a[i],&b[i],&ra[i]);
  }
  
  sort(id+1,id+n+1,cmp);
  calc(1,n);
  printf("%.3f",ans);
  return 0;
}
