#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 2000
#define M 100000
#define INF 1ll<<40

typedef long long LL;
using namespace std;

void readint(int &x){
  x=0;
  char c=getchar();
  while(!(c>='0'&&c<='9'))
    c=getchar();
  while(c>='0' && c<='9'){
    x=x*10+c-'0';
    c=getchar();
  }
}
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
namespace nf{
  int le[N],pe[M],ecnt,ev[M];
  LL data[M];
  void addEdge(int u,int v,LL cap){
    //printf("%d %lld\n",ecnt,cap);
    pe[ecnt]=le[u];
    ev[ecnt]=v;
    data[ecnt]=cap;
    le[u]=ecnt++;
     
    pe[ecnt]=le[v];
    ev[ecnt]=u;
    data[ecnt]=0;
    le[v]=ecnt++;
  }
  void clear(){
    memset(le,-1,sizeof(le));
    ecnt=0;
  }
  int S,T;
  void init(int s,int t){
    S=s,T=t;
    clear();
  }
  int dist[N],q[N],fr,rr;
  void bfs(){
    Rep(i,T)dist[i]=T+1;
    dist[T]=0;
    fr=rr=0;
    q[fr]=T;
    while(fr<=rr){
      int &u=q[fr++];
      for(int i=le[u]; i!=-1; i=pe[i]){
        if(data[i^1] && dist[ev[i]]>dist[u]+1){
          q[++rr]=ev[i];
          dist[ev[i]]=dist[u]+1;
        }
      }
    }
  }
  int pre[N];
  LL augment(){
    int u=T;
    LL ret=INF;
    while(u!=S){
      ret=min(ret,data[pre[u]]);
      u=ev[pre[u]^1];
      //printf("%d %d %lld\n",u,pre[u],data[pre[u]]);
    }
    //printf("%lld\n",ret);
    u=T;
    while(u!=S){
      data[pre[u]]-=ret;
      data[pre[u]^1]+=ret;
      u=ev[pre[u]^1];
    }
    return ret;
  }
  int cur[N],cnt[N];
  LL maxFlow(){
    LL ret=0;
    bfs();
    int u=S;
    memset(cnt,0,sizeof(cnt));
    Rep(i,T+1)cur[i]=le[i];
    Rep(i,T+1)cnt[dist[i]]++;
    while(dist[S]<=T){
      if(u==T){
        ret+=augment();
        u=S;
      }
      //printf("%lld %d %d %d\n",ret,dist[S],u,dist[u]);
      int flag=0;
      for(int i=cur[u]; i!=-1; i=pe[i]){
        int &v=ev[i];
        if(data[i]&&dist[v]+1==dist[u]){
          flag=1;
          cur[u]=i;
          pre[v]=i;
          u=v;
          break;
        }
      }
      if(flag)continue;
      int mind=T;
      for(int i=le[u]; i!=-1; i=pe[i]){
        int &v=ev[i];
        if(data[i])mind=min(mind,dist[ev[i]]);
      }
      if(--cnt[dist[u]]==0)break;
      ++cnt[dist[u]=mind+1];
      cur[u]=le[u];
      if(u!=S)u=ev[pre[u]^1];
    }
    return ret;
  }
}

LL sum1,sum2,maxa;
int n,m,a[N][N];
LL check(LL x){
  if(x<maxa)return -1;
  nf::clear();
  Rep(i,n)Rep(j,m){
    if((i+j)&1)
      nf::addEdge(i*m+j,nf::T,x-a[i][j]);
    else{
      nf::addEdge(nf::S,i*m+j,x-a[i][j]);
      Rep(k,4)
        if(i+dx[k]>=0&&i+dx[k]<n&&j+dy[k]>=0&&j+dy[k]<m)
          nf::addEdge(i*m+j,(i+dx[k])*m+j+dy[k],INF);
    }
  }
  LL f=nf::maxFlow();
  if(x*n*m-sum1-sum2!=2*f)return -1;
  return f;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
    sum1=sum2=maxa=0;
    readint(n);readint(m);
    nf::init(n*m,n*m+1);
    Rep(i,n)Rep(j,m){
      readint(a[i][j]);
      maxa=max(maxa,(LL)a[i][j]);
      if((i+j)&1)
        sum2+=a[i][j];
      else
        sum1+=a[i][j];
    }
    if((n*m)&1){
      printf("%lld\n",check(sum1-sum2));
    }else{
      if(sum1!=sum2){
        puts("-1");
        continue;
      }
      LL low=maxa,high=INF;
      if(check(high)==-1){
        puts("-1");
        continue;
      }
      while(low<high){
        LL mid=(low+high)>>1;
        if(check(mid)!=-1)high=mid;
        else low=mid+1;
      }
      printf("%lld\n",(low*n*m-sum1-sum2)/2);
    }
  }
  return 0;
}
