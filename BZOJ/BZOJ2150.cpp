#include <algorithm>
#include <stdio.h>
#include <string.h>
#define Rep(i,n) for(int i=0; i<n; i++)
using namespace std;

namespace nf{
#define N 5010
#define M 30000
#define INF (1<<30)
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

int n,m,R,C,dx[2]={1,1},dy[4]={-1,1};
char g[60][60];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d%d%d",&n,&m,&R,&C);
	init(n*m*2,n*m*2+1);
	Rep(i,n)
		scanf("%s",g[i]);
#define x1 (i+dx[k]*R)
#define y1 (j+dy[k]*C)
#define x2 (i+dx[k]*C)
#define y2 (j+dy[k]*R)
	int cnt=0;
	Rep(i,n){
		Rep(j,m)if(g[i][j]=='.'){
			addEdge(S,(i*m+j)<<1,1);
			addEdge((i*m+j)<<1|1,T,1);
			Rep(k,2){
				if(x1>=0 && x1<n && y1>=0 && y1<m && g[x1][y1]=='.')
					addEdge((i*m+j)<<1,(x1*m+y1)<<1|1,1);
				if((x2!=x1 || y2!=y1) && x2>=0 && x2<n && y2>=0 && y2<m && g[x2][y2]=='.')
					addEdge((i*m+j)<<1,(x2*m+y2)<<1|1,1);
			}
			cnt++;
		}
	}
	printf("%d\n",cnt-maxFlow());
	return 0;
}

