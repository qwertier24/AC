#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

namespace nf{
#define eps 1e-7
#define N 2510
#define M 40000
  int le[N],pe[M],ecnt,ev[M];
  double data[M<<1];
  void addEdge(int u,int v,double cap,double cap2){
    pe[ecnt]=le[u];
    ev[ecnt]=v;
    data[ecnt]=cap;
    le[u]=ecnt++;
    
    pe[ecnt]=le[v];
    ev[ecnt]=u;
    data[ecnt]=cap2;
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
	if(data[i]>eps && dist[ev[i]]==-1){
	  dist[ev[i]]=dist[u]+1;
	  q[++rear]=ev[i];
	}
      }
    }
    return dist[T]!=-1;
  }
  int dfscnt=0,cur[N],mark[N]={0},cnt;
  double dfs(int u,double a){
    cnt++;
    if(u==T || a<=eps)return a;
    double ret=0,f;
    if(mark[u]!=dfscnt){mark[u]=dfscnt,cur[u]=le[u];}
    for(int &i=cur[u]; i!=-1; i=pe[i]){
      int &v=ev[i];
      if(dist[v]!=dist[u]+1)continue;
      f=dfs(v,min(a,data[i]));
      data[i]-=f;
      data[i^1]+=f;
      a-=f;
      ret+=f;
      if(a<eps)break;
    }
    return ret;
  }
  double maxFlow(){
    double ret=0;
    dfscnt=0;
    memset(mark,0,sizeof(mark));
    while(bfs()){
      dfscnt++;
      ret+=dfs(S,1e60);
    }
    return ret;
  }
}
using namespace nf;

int n,m,tot,a[60][60],b[60][60],c[60][60];
bool check(double d){
	init(n*m,n*m+1);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			addEdge(S,i*m+j,a[i][j],0);
	for(int i=0; i<=n; i++)
		for(int j=0; j<m; j++){
			if(i==0)
				addEdge(i*m+j,T,d*b[i][j],0);
			else if(i==n)
				addEdge((i-1)*m+j,T,d*b[i][j],0);
			else
				addEdge((i-1)*m+j,i*m+j,d*b[i][j],d*b[i][j]);
		}
	for(int i=0; i<n; i++)
		for(int j=0; j<=m; j++){
			if(j==0)
				addEdge(i*m+j,T,d*c[i][j],0);
			else if(j==m)
				addEdge(i*m+j-1,T,d*c[i][j],0);
			else
				addEdge(i*m+j-1,i*m+j,d*c[i][j],d*c[i][j]);
		}
	double flow=maxFlow();
	return flow<tot;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			scanf("%d",&a[i][j]);
			tot+=a[i][j];
		}
	for(int i=0; i<=n; i++)
		for(int j=0; j<m; j++)
			scanf("%d",&b[i][j]);
	for(int i=0; i<n; i++)
		for(int j=0; j<=m; j++)
			scanf("%d",&c[i][j]);
	double lo=0,hi=300000;
	while(hi-lo>1e-5){
		double mi=(lo+hi)/2;
		if(check(mi))lo=mi;
		else hi=mi;
	}
	printf("%.3f\n",lo);
	return 0;
}

