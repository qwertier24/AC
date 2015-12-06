#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define N 30000
#define INF 1e60
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;

const double PI=3.1415926535897932384626;
int n;
double x[N+1],y[N+10];
bool equal(double a,double b){
  return fabs(a-b)<=1e-5;
}
double getcos(double x1,double y1,double x2,double y2){
  return (x1*x2+y1*y2)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2));
}
int check(){
  double xm=0,ym=0;
  Rep(i,n){
    xm+=x[i];
    ym+=y[i];
  }
  xm/=n;
  ym/=n;
  double mind=INF,maxd=-INF;
  Rep(i,n){
    if(equal(x[i],xm)&&equal(y[i],ym))
      return -1;
    mind=min(mind,sqrt((x[i]-xm)*(x[i]-xm)+(y[i]-ym)*(y[i]-ym)));
    maxd=max(maxd,sqrt((x[i]-xm)*(x[i]-xm)+(y[i]-ym)*(y[i]-ym)));
  }
  if(maxd-mind>maxd/10)return -1;
  double mincos=INF,maxcos=-INF;
  Rep(i,n){
    double t=getcos(x[i]-xm,y[i]-ym,x[(i+1)%n]-xm,y[(i+1)%n]-ym);
    mincos=min(mincos,t);
    maxcos=max(maxcos,t);
  }
  //printf("%f %f\n",mincos,maxcos);
  if(maxcos-mincos<=0.01)return n;
  else return -1;
}
double getk(){
  double xm=0,ym=0,area=0;
  Rep(i,n){
    xm+=x[i];
    ym+=y[i];
  }
  xm/=n;
  ym/=n;
  double maxd=0;
  Rep(i,n){
    maxd=max(maxd,sqrt((x[i]-xm)*(x[i]-xm)+(y[i]-ym)*(y[i]-ym)));
    area+=(x[i]*y[(i+1)%n]-x[(i+1)%n]*y[i])/2;
    //printf("%f\n",(x[(i+1)%n]-x[i])*(y[i]+y[(i+1)%n])/2);
  }
  area=fabs(area);
  double round_area=PI*maxd*maxd;
  //printf("area:%f %f\n",area,round_area);
  return area/round_area;
}
int m;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    int nn=n,mm=m;
    Rep(i,n){
      scanf("%lf%lf",&x[i],&y[i]);
    }
    int f1=check();
    double k1=getk();

    n=m;
    Rep(i,n){
      scanf("%lf%lf",&x[i],&y[i]);
    }
    int f2=check();
    double k2=getk();
    //printf("%f %f %d\n",k1*nn,k2*mm,(k2>k1)+1);
    if(f1!=-1&&f2!=-1){
      printf("%d\n",(f1<f2)+1);
    }else if(f1!=-1&&nn>=mm){
      printf("%d\n",1);
    }else if(f2!=-1&&nn<=mm){
      printf("%d\n",2);
    }else{
      printf("%d\n",(k2>k1)+1);
    }
  }
  return 0;
}
