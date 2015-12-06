#include<stdio.h>
#include<algorithm>
#include<cstring>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define INF (1<<29)

using namespace std;

#define N 500010

int m,yc[N];
struct BIT{
#define lowbit(x) ((x)&-(x))
  int minv[N],maxv[N];
  void init(){memset(minv,0x3f,sizeof(minv));memset(maxv,0xcf,sizeof(maxv));}
  void update(int p,int v){
    while(p<=m){
      minv[p]=min(minv[p],v);
      maxv[p]=max(maxv[p],v);
      p+=lowbit(p);
    }
  }
  void query(int p,int &r1,int &r2){
    r1=INF,r2=-INF;
    while(p){
      r1=min(r1,minv[p]);
      r2=max(r2,maxv[p]);
      p-=lowbit(p);
    }
  }
}bit;

typedef pair<int,int> pii;
pii p[N];
#define x first
#define y second
inline bool cmp(const pii &a,const pii &b){
  return a.x<b.x || (a.x==b.x&&a.y>b.y);
}
int n,maxd[N],mind[N];
void calc(){
  bit.init();
  REP(i,1,n){
    int t1,t2;
    bit.query(p[i].y,t1,t2);
    maxd[i]=max(maxd[i],p[i].x+yc[p[i].y]-t1);
    mind[i]=min(mind[i],p[i].x+yc[p[i].y]-t2);
    bit.update(p[i].y,p[i].x+yc[p[i].y]);
    //printf("%d %d:maxd[%d]=%d mind[%d]=%d\n",p[i].x,yc[p[i].y],i,maxd[i],i,mind[i]);
  }
  bit.init();
  RREP(i,n,1){
    int t1,t2;
    bit.query(m-p[i].y+1,t1,t2);
    mind[i]=min(mind[i],t1-p[i].x-yc[p[i].y]);
    maxd[i]=max(maxd[i],t2-p[i].x-yc[p[i].y]);
    bit.update(m-p[i].y+1,p[i].x+yc[p[i].y]);
    //printf("%d %d:maxd[%d]=%d mind[%d]=%d\n",p[i].x,yc[p[i].y],i,maxd[i],i,mind[i]);
  }
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  memset(mind,0x3f,sizeof(mind));
  scanf("%d",&n);
  REP(i,1,n){
    scanf("%d%d",&p[i].x,&p[i].y);
    yc[i]=p[i].y;
  }
  sort(yc+1,yc+n+1);
  m=unique(yc+1,yc+n+1)-yc-1;
  REP(i,1,n)p[i].y=lower_bound(yc+1,yc+m+1,p[i].y)-yc;
  
  sort(p+1,p+n+1);
  calc();
  
  REP(i,1,n)p[i].y=m-p[i].y+1;
  REP(i,1,m)yc[i]=-yc[i];
  reverse(yc+1,yc+m+1);
  sort(p+1,p+n+1,cmp);
  calc();
  int ans=INF;
  REP(i,1,n)ans=min(ans,maxd[i]-mind[i]);
  printf("%d\n",ans);
  return 0;
}
