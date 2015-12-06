#include<stdio.h>
#include<algorithm>
#include<math.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
using std::min;
using std::max;

#define N 510
#define eps 1e-6
#define eq(t1,t2) ((t1)-(t2)<=eps && (t1)-(t2)>=-eps)
#define sqr(x) ((x)*(x))
int n;
double h[N],r[N],x[N],X1[N],X2[N],Y1[N],Y2[N];

double F(double cur){
  double ret=0;
  REP(i,1,n)
    if(fabs(cur-x[i])<=r[i]+eps)
      ret=max(ret,sqrt(sqr(r[i])-sqr(x[i]-cur)));
  REP(i,1,n)
    if(cur-X1[i]>-eps && X2[i]-cur>-eps)
      ret=max(ret,(Y2[i]-Y1[i])/(X2[i]-X1[i])*(cur-X1[i])+Y1[i]);
  //printf("%f %f\n",cur,ret);
  return ret;
}
inline double simpson(double fl,double fm,double fr,double dx){
  return dx*(fl+4.0*fm+fr)/6.0;
}
double calc(double l,double r,double fl,double fm,double fr){
  double m=(l+r)/2.0,fm1=F((l+m)/2.0),fm2=F((m+r)/2.0);
  double a1=simpson(fl,fm1,fm,m-l),a2=simpson(fm,fm2,fr,r-m),a3=simpson(fl,fm,fr,r-l);
  if(eq(a1+a2,a3))return a3;
  return calc(l,m,fl,fm1,fm)+calc(m,r,fm,fm2,fr);
}
double a;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%lf",&n,&a);
  REP(i,1,n+1){
    scanf("%lf",&h[i]);
    h[i]+=h[i-1];
    x[i]=h[i]/tan(a);
  }
  REP(i,1,n)
    scanf("%lf",&r[i]);
  double lft=x[n+1],rgt=x[n+1];
  REP(i,1,n){
    lft=min(lft,x[i]-r[i]);
    rgt=max(rgt,x[i]+r[i]);
    if(x[i+1]-x[i]-fabs(r[i+1]-r[i])<=eps)continue;
    double ht=r[i]*(r[i]-r[i+1])/(x[i+1]-x[i]);
    X1[i]=x[i]+ht;
    Y1[i]=sqrt(sqr(r[i])-sqr(ht));
    ht=r[i+1]*(r[i]-r[i+1])/(x[i+1]-x[i]);
    X2[i]=x[i+1]+ht;
    Y2[i]=sqrt(sqr(r[i+1])-sqr(ht));
  }
  printf("%.2f\n",calc(lft,rgt,F(lft),F((lft+rgt)/2.0),F(rgt))*2.0);
  return 0;
}
