#include<stdio.h>
#include<string.h>
#include<algorithm>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
typedef long long LL;

namespace nf{
#define N 200000
#define M 2000000
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
  void init(){
    memset(le,-1,sizeof(le));
    ecnt=0;
    S=0;
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

#define mid ((l+r)>>1)
int lc[N],rc[N],sz;
void query(int &o,int l,int r,int &L,int &R,int &u){
	if(L>R || !o)return;
	if(L<=l && r<=R){
		addEdge(o,u,INF);
		return;
	}
	if(L<=mid)query(lc[o],l,mid,L,R,u);
	if(R>mid)query(rc[o],mid+1,r,L,R,u);
}
void insert(int &o,int p,int l,int r,int &x,int &u){
	o=++sz;
	addEdge(u,o,INF);
	if(p)addEdge(p,o,INF);
	if(l==r)return;
	if(x<=mid){
		rc[o]=rc[p];
		insert(lc[o],lc[p],l,mid,x,u);
	}else{
		lc[o]=lc[p];
		insert(rc[o],rc[p],mid+1,r,x,u);
	}
	if(lc[o])addEdge(lc[o],o,INF);
	if(rc[o])addEdge(rc[o],o,INF);
}

int n,m,c[5010];
int a[5010],b[5010],w[5010],l[5010],r[5010],p[5010],id[5010][2],root[5010],ans;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&n);
	nf::init();
	T=++sz;
	REP(i,1,n){
		scanf("%d%d%d%d%d%d",&a[i],&b[i],&w[i],&l[i],&r[i],&p[i]);
		ans+=b[i]+w[i];
		c[i]=a[i];
	}
	sort(c+1,c+n+1);
	m=unique(c+1,c+n+1)-c-1;
	REP(i,1,n){
		a[i]=lower_bound(c+1,c+m+1,a[i])-c;
		l[i]=lower_bound(c+1,c+m+1,l[i])-c;
		r[i]=upper_bound(c+1,c+m+1,r[i])-c-1;
		id[i][0]=++sz;
		query(root[i-1],1,m,l[i],r[i],id[i][0]);
		id[i][1]=++sz;
		insert(root[i],root[i-1],1,m,a[i],id[i][1]);
		addEdge(id[i][0],id[i][1],p[i]);
		addEdge(id[i][1],T,b[i]);
		addEdge(S,id[i][1],w[i]);
	}
	printf("%d\n",ans-maxFlow());
	return 0;
}

