#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#include<math.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 50010

typedef long long LL;
using namespace std;
struct P{
  int x,y;
  bool operator<(const P& r)const{
    return x<r.x || (x==r.x && y<r.y);
  }
  P(int a=0,int b=0):x(a),y(b){}
  P operator-(P& r){
    return P(x-r.x,y-r.y);
  }
}p[N],ch[N];
int n,m;
int Cross(P a,P b){
  return a.x*b.y-a.y*b.x;
}
void getCH(){
  Rep(i,n){
    while(m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)
      m--;
    ch[m++]=p[i];
  }
  
  int mt=m;
  for(int i=n-2; i>=0; i--){
    while(m>mt && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)
      m--;
    ch[m++]=p[i];
  }
  if(n>1)m--;
}
int dist2(P a,P b){
  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int getR(){
  ch[m]=ch[0];
  int p=1,ret=0;
  Rep(i,m){
    while(Cross(ch[i+1]-ch[i],ch[p]-ch[i])<Cross(ch[i+1]-ch[i],ch[p+1]-ch[i])){
      p=(p+1)%m;
    }
    ret=max(ret,max(dist2(ch[i],ch[p]),dist2(ch[i+1],ch[p])));
  }
  return ret;
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  Rep(i,n)scanf("%d%d",&p[i].x,&p[i].y);
  int ans=0;
  sort(p,p+n);
  getCH();
  printf("%d\n",getR());
  return 0;
}
