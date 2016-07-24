#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
 
typedef double Type;
const Type eps = 1e-12;
struct point
{
    Type x,y;
	point(){}
	point(Type _x,Type _y){ x=_x,y=_y;}
	friend bool operator < (const point &l, const point &r) {
        return l.y < r.y || (l.y == r.y && l.x < r.x);
    }
};
struct line
{
    point a,b;
	line(){}
	line(point _a,point _b){a = _a,b=_b;}
};
struct poly{
	int n;
	Type area;
	point plist[10];
};
struct circle{  
    point o;  
    double r;  
};  
bool isZero(Type a){
	if(fabs(a) < eps)
		return true;
	else return false;
}
//两点距离
// distance变量名- - 会跟algorithm里面的重复
Type dis(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
//叉积
//  P1
//    \
// .p0 \
//      p2
//  这种情况。返回结果顺时针<0,逆时针>0
Type Multi(point p1, point p2, point p0) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
//通过两条直线所在的线段
//获得两条直线的交点的坐标
//前提是这两条直线不共线,即不平行
point getInterPoint(line &a,line &b){
	Type a1 = a.a.y-a.b.y , b1 = a.b.x-a.a.x,
		   c1 = a.a.x*a.b.y - a.b.x*a.a.y,
		   a2 = b.a.y-b.b.y , b2 = b.b.x - b.a.x,
		   c2 = b.a.x*b.b.y - b.b.x*b.a.y ;
	Type x,y;
	//垂直情况 b1,b2==0
	if(isZero(b1)){
		x = a.a.x;
		y = (a.a.x - b.a.x)*a2/b2+b.a.y;
	}else if(isZero(b2)){
		x = b.a.x;
		y = (b.a.x - a.a.x)*a1/b1+a.a.y;
	}else{
		//非垂直时,计算方法
		x = (b1*c2 - b2*c1)/(a1*b2-a2*b1),
		y = (a2*c1 - a1*c2)/(a1*b2-a2*b1);
	}
	return point(x,y);
}
int dblcmp(double k) {
    if (fabs(k) < eps) return 0;
    return k > 0 ? 1 : -1;
}
// 要注意方向！
// 下面的是顺时针走向
// 如果是逆时针，将 > 与 <互换
bool angle_cmp(int i,int j){
	if(dblcmp(ang[i]-ang[j])==0 && Multi(L[j].a,L[j].b,L[i].a)<0)return true;
	return ang[i]<ang[j];
}
bool Out(int ln1,int ln2,int ln){
	point p = getInterPoint(L[ln1],L[ln2]);
	return dblcmp(Multi(L[ln].a,L[ln].b,p)) > 0;
}
//L是线段数组 , n 是元素 , ret是核心
bool HalfPlaneIntersect(line L[],int n,poly &ret){
	for(int i = 0;i < n;i++){
		ang[i] = atan2(L[i].b.y-L[i].a.y,L[i].b.x-L[i].a.x);
		ord[i] = i;
	}
	sort(ord,ord+n,angle_cmp);
	int nn = 1;
	for(int i = 1;i < n;i++){
		if(dblcmp(ang[ord[i]]-ang[ord[i-1]])!=0)
			ord[nn++]=ord[i];
	}
	int back = 1,front = 0;
	que[0] = ord[0]; que[1]=ord[1];
	for(int i = 2;i < nn;i++){
		while(back > front && Out(que[back-1],que[back],ord[i])) back--;
		while(front< back && Out(que[front+1],que[front],ord[i])) front++;
		que[++back]=ord[i];
	}
	while(back > front && Out(que[back-1],que[back],que[front]))back--;
	while(back > front && Out(que[front+1],que[front],que[back]))front++;
 
	// 判断是否存在核 。通过是否存在点来判断就可以了
	// 用于核是否存在的判定
	return back - front > 1;
 
	//求面积则用下面这些.
	que[++back] = que[front];
	ret.n = 0;
	for(int i = front;i < back;i++){
		ret.plist[ret.n]=getInterPoint(L[que[i]],L[que[i+1]]);
		ret.n++;
	}
	area(ret);
	return ret.area/2.0;
 
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
	HalfPlaneIntersect(seg,N);
	double ans=Get_area(p,m),Tmp=4e14;
	cout<<fixed<<setprecision(20)<<ans/Tmp<<endl;
  }
  return 0;
}

