#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)

using namespace std;
#define N 2010
#define INF (1<<29)

int n,m,R,L0;
int d[N][N<<1],choi[N][N],a[N],b[N],dis[N],p[N],f[N],mark[N];
int ans1,ans2=INF;
int q[N<<1][N],fr[N<<1],rr[N<<1];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d%d%d",&n,&m,&R,&L0);
  R=min(R,n<<1);
  REP(i,1,n)scanf("%d%d%d%d%d",&a[i],&b[i],&dis[i],&p[i],&f[i]);
  REP(i,1,n){
    REP(j,0,m)d[i][j]=d[i-1][j];
    REP(j,a[i],m){
      if(d[i][j]<d[i-1][j-a[i]]+b[i]){
        choi[i][j]=1;
        d[i][j]=d[i-1][j-a[i]]+b[i];
      }
    }
  }
  int t1=0,t2=0;
  REP(i,0,m)if(d[n][i]>t2){
    t1=i;
    t2=d[n][i];
  }
  ans1=t2;
  for(int i=n; i&&t1; i--)if(d[i][t1]==t2 && choi[i][t1]){
      t1-=a[i];
      t2-=b[i];
      mark[i]=1;
  }
  memset(d,0x3f,sizeof(d));
  memset(rr,-1,sizeof(rr));
  d[0][R]=0;
  q[R][++rr[R]]=0;
  REP(i,1,n){
    if(dis[i]-dis[i-1]>L0){
      puts("Poor Coke!");
      return 0;
    }
    int mind=INF;
    REP(j,0,R){
      while(fr[j+2]<=rr[j+2] && dis[i]-dis[q[j+2][fr[j+2]]]>L0)
        fr[j+2]++;
      int mind2=INF;
      if(fr[j+2]<=rr[j+2])
        mind2=d[q[j+2][fr[j+2]]][j+2]-(j+2)*p[i];
      mind=min(mind,mind2);
      if(p[i])d[i][j]=mind+(j+2)*p[i]+f[i];
      else d[i][j]=mind2+f[i];
      while(fr[j]<=rr[j] && (mark[i] || d[q[j][rr[j]]][j]>d[i][j]))
        rr[j]--;
      q[j][++rr[j]]=i;
      if(i==n)ans2=min(ans2,d[i][j]);
    }
  }
  if(ans2>=INF)puts("Poor Coke!");
  else  printf("%d %d\n",ans1,ans1-ans2);
  return 0;
}
