#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010

using namespace std;

double cross(double x1,double y1,double x2,double y2){
  return x1*y2-x2*y1;
}
double a[N],x[N],d,ans;
int n;
int st[N],tp;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%lf",&n,&d);
  For(i,n){
    scanf("%lf%lf",&a[i],&x[i]);
    a[i]+=a[i-1];
    while(tp>1 && cross(i*d-st[tp]*d,a[i-1]-a[st[tp]-1],
                        st[tp]*d-st[tp-1]*d,a[st[tp]-1]-a[st[tp-1]-1])>0)tp--;
    st[++tp]=i;
    int lo=1,hi=tp;
    while(lo<hi){
      int mi=(lo+hi)>>1;
      if(mi<tp && cross(x[i]+i*d-st[mi]*d,a[i]-a[st[mi]-1],
                        x[i]+i*d-st[mi+1]*d,a[i]-a[st[mi+1]-1])>0)lo=mi+1;
      else hi=mi;
    }
    ans+=(a[i]-a[st[lo]-1])/(x[i]+i*d-st[lo]*d);
  }
  printf("%.0f\n",ans);
  return 0;
}
