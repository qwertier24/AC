#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB
#define INF (1<<30)
using namespace std;

namespace nf{
#define N 100
#define M 10000
  int le[N],pe[M],ecnt,data[M],ev[M];
  void addEdge(int u,int v,int cap){
    pe[ecnt]=le[u];
    ev[ecnt]=v;
    data[ecnt]=cap;
    le[u]=ecnt++;
    
    pe[ecnt]=le[v];
    ev[ecnt]=u;
    data[ecnt]=cap;
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

int n,a1,a2,an,b1,b2,bn;
char g[100][100];

#define Rep(i,n) for(int i=0; i<n; i++)
#define For(i,n) for(int i=1; i<=n; i++)
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    while(scanf("%d%d%d%d%d%d%d",&n,&a1,&a2,&an,&b1,&b2,&bn)!=EOF){
        an<<=1,bn<<=1;
        nf::init(n,n+1);
        Rep(i,n){
            scanf("%s",g[i]);
            Rep(j,i){
                if(g[i][j]=='O')
                    nf::addEdge(j,i,2);
                else if(g[i][j]=='N')
                    nf::addEdge(j,i,INF);
            }
        }
        nf::addEdge(nf::S,a1,an);
        nf::addEdge(a2,nf::T,an);
        nf::addEdge(nf::S,b1,bn);
        nf::addEdge(b2,nf::T,bn);
        if(nf::maxFlow()!=an+bn){
            puts("No");
            continue;
        }
        
        nf::init(n,n+1);
        swap(b1,b2);
        Rep(i,n){
            Rep(j,i){
                if(g[i][j]=='O')
                    nf::addEdge(j,i,2);
                else if(g[i][j]=='N')
                    nf::addEdge(j,i,INF);
            }
        }
        nf::addEdge(nf::S,a1,an);
        nf::addEdge(a2,nf::T,an);
        nf::addEdge(nf::S,b1,bn);
        nf::addEdge(b2,nf::T,bn);
        if(nf::maxFlow()!=an+bn){
            puts("No");
            continue;
        }
        puts("Yes");
    }
	return 0;
}

