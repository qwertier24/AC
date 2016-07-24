#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<iomanip>
#define REP(i,n) for(int i = 0; i < n; i++)
#define eps 1e-17
#define zero(a) fabs(a)<eps
#define MAXN 520005
using namespace std;
#define double long double
struct Point{
  double x,y;
}p[MAXN*2];
struct Segment{
  Point s,e;
  double angle;
  void get_angle(){angle=atan2(e.y-s.y,e.x-s.x);}
}seg[MAXN],deq[MAXN];
int m,N;
double L,R,M;
inline double xmul(Point p0,Point p1,Point p2){
  return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
inline Point Get_Intersect(const Segment &s1,const Segment &s2){
  double u=xmul(s1.s,s1.e,s2.s),v=xmul(s1.e,s1.s,s2.e);
  Point t;
  t.x=(s2.s.x*v+s2.e.x*u)/(u+v);t.y=(s2.s.y*v+s2.e.y*u)/(u+v);
  return t;
}
inline bool cmp(const Segment &s1,const Segment &s2){
  if(zero(s1.angle-s2.angle)&&xmul(s2.s,s2.e,s1.e)>0) return true;
  return s1.angle>s2.angle;
}
void print_line(Segment &se){
  //printf("%f %f %f %f %f\n", se.s.x, se.s.y, se.e.x, se.e.y, se.angle);
}
void HalfPlaneIntersect(Segment seg[],int n){
  sort(seg,seg+n,cmp);
  int tmp=1;
  for(int i=1;i<n;i++)
    if(!zero(seg[i].angle-seg[tmp-1].angle))
      seg[tmp++]=seg[i];
  n=tmp;
  REP(i,n)
      print_line(seg[i]);
  deq[0]=seg[0];deq[1]=seg[1];
  int head=0,tail=1;
  for(int i=2;i<n;i++){
    while(head<tail&&xmul(seg[i].s,seg[i].e,Get_Intersect(deq[tail],deq[tail-1]))<=0) tail--;
    while(head<tail&&xmul(seg[i].s,seg[i].e,Get_Intersect(deq[head],deq[head+1]))<0) head++;
    deq[++tail]=seg[i];
  }
  //printf("%d %d %f %f %f %f : %f %f %f %f\n", head, tail, deq[head].s.x,deq[head].s.y,deq[head].e.x,deq[head].e.y, deq[tail].s.x, deq[tail].s.y, deq[tail].e.x, deq[tail].e.y);
  while(head<tail&&xmul(deq[head].s,deq[head].e,Get_Intersect(deq[tail],deq[tail-1]))<=0) tail--;
  while(head<tail&&xmul(deq[tail].s,deq[tail].e,Get_Intersect(deq[head],deq[head+1])) <0) head++;
  m=0;
  if(tail - head <= 1)return;
  for(int i=head;i<tail;i++)
    p[m++]=Get_Intersect(deq[i],deq[i+1]);
  if(tail>head+1)
    p[m++]=Get_Intersect(deq[head],deq[tail]);
}
double Get_area(Point p[],int &n){
  double area=0;
  for(int i=1;i<n;i++)
    area+=xmul(p[0],p[i],p[(i+1)%n]);
  return fabs(area)/2.0;
}
int xc[MAXN], yc[MAXN];
int main(){
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  while(T--){
	scanf("%d",&N);
	REP(i,N){
      scanf("%d%d", &xc[i], &yc[i]);
    }
    REP(i,N){
      seg[i].s.x=xc[(i+1)%N]; seg[i].s.y=yc[(i+1)%N]; seg[i].e.x=xc[i]; seg[i].e.y=yc[i];
      seg[i].get_angle();
	}
#define INF (1e7)
    seg[N].s.x = INF;
    seg[N].s.y = INF;
    seg[N].e.x = -INF;
    seg[N].e.y = INF;
    seg[N].get_angle();
    N++;
    
    seg[N].s.x = INF;
    seg[N].s.y = -INF;
    seg[N].e.x = INF;
    seg[N].e.y = INF;
    seg[N].get_angle();
    N++;
    
    seg[N].s.x = -INF;
    seg[N].s.y = -INF;
    seg[N].e.x = +INF;
    seg[N].e.y = -INF;
    seg[N].get_angle();
    N++;

    seg[N].s.x = -INF;
    seg[N].s.y = +INF;
    seg[N].e.x = -INF;
    seg[N].e.y = -INF;
    seg[N].get_angle();
    N++;
	HalfPlaneIntersect(seg,N);
	double ans=Get_area(p,m),Tmp=4e14;
	cout<<fixed<<setprecision(16)<<ans/Tmp<<endl;
  }
  return 0;
}
