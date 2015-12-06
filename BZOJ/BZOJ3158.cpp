#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using std::__gcd;
using std::min;
#define gcd __gcd

typedef long long LL;
namespace nf{
#define N 2010
#define M 2200000
#define INF ((~0u)>>1)
  int le[N],pe[M],ecnt,data[M],ev[M];
  void addEdge(int u,int v,int cap){
    pe[ecnt]=le[u];
    ev[ecnt]=v;
    data[ecnt]=cap;
    le[u]=ecnt++;
    
    pe[ecnt]=le[v];
    ev[ecnt]=u;
    data[ecnt]=0;
    le[v]=ecnt++;
  }
  int S,T;
  void init(int s,int t){
    memset(le,-1,sizeof(le));
    ecnt=0;
    S=s,T=t;
  }
  int dist[N],q[N],front,rear;
  int bfs(){
    memset(dist,-1,sizeof(dist));
    front=rear=0;
    q[front]=S;
    dist[S]=0;
    while(front<=rear){
      int u=q[front++];
      for(int i=le[u]; i!=-1; i=pe[i]){
	if(data[i] && dist[ev[i]]==-1){
	  dist[ev[i]]=dist[u]+1;
	  q[++rear]=ev[i];
	}
      }
    }
    return dist[T]!=-1;
  }
  int dfscnt=0,cur[N],mark[N]={0},cnt;
  int dfs(int u,int a){
    cnt++;
    if(u==T || a==0)return a;
    int ret=0,f;
    if(mark[u]!=dfscnt){mark[u]=dfscnt,cur[u]=le[u];}
    for(int &i=cur[u]; i!=-1; i=pe[i]){
      int &v=ev[i];
      if(dist[v]!=dist[u]+1)continue;
      f=dfs(v,min(a,data[i]));
      data[i]-=f;
      data[i^1]+=f;
      a-=f;
      ret+=f;
    }
    return ret;
  }
  int maxFlow(){
    int ret=0;
    dfscnt=0;
    memset(mark,0,sizeof(mark));
    while(bfs()){
      dfscnt++;
      ret+=dfs(S,INF);
    }
    return ret;
  }
}
using namespace nf;

int n,a[N];
inline bool check(LL x,LL y)
{
	if (gcd(x,y)!=1) return false;
	LL l=1,r=2000000;
	while (l<=r)
	{
		LL mid=(l+r)/2;
		if (mid*mid==x*x+y*y) return true;
		if (mid*mid<x*x+y*y) l=mid+1;
		else r=mid-1;
	}
	return false;
}
int ans;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&n);
	init(0,n+1);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=1; i<=n; i++){
		int b;
		scanf("%d",&b);
		ans+=b;
		if(a[i]&1)addEdge(S,i,b);
		else addEdge(i,T,b);
		for(int j=i+1; j<=n; j++)
			if(check(a[i],a[j])&&gcd(a[i],a[j])==1){
				if(a[i]&1)addEdge(i,j,INF);
				else addEdge(j,i,INF);
			}
	}
	printf("%d\n",ans-maxFlow());
	return 0;
}
