#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define N 60
#define M 2010
using std::min;
using std::priority_queue;

int n,m,K;

int le[N],pe[M],ev[M],ed[M],ecnt;
void addEdge(int u,int v,int d){
	ecnt++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ev[ecnt]=v;
	ed[ecnt]=d;
}

struct Node{
	int u,k,d;
	bool operator<(const Node& rhs)const{
		return d>rhs.d;
	}
	Node(int a,int b,int c):u(a),k(b),d(c){}
};
int dist[N][N],mark[N][N];
int DIJ(){
	memset(dist,0x3f,sizeof(dist));
	dist[1][0]=0;
	priority_queue<Node> pq;
	pq.push(Node(1,0,0));
	int u,k;
	while(!pq.empty()){
		Node t=pq.top();
		pq.pop();
		u=t.u,k=t.k;
		if(mark[u][k])continue;
		mark[u][k]=1;
		for(int i=le[u]; i; i=pe[i]){
			int &v=ev[i];
			if(dist[v][k]>dist[u][k]+ed[i]){
				dist[v][k]=dist[u][k]+ed[i];
				pq.push(Node(v,k,dist[v][k]));
			}
			if(k<K && dist[v][k+1]>dist[u][k]+ed[i]/2){
				dist[v][k+1]=dist[u][k]+ed[i]/2;
				pq.push(Node(v,k+1,dist[v][k+1]));
			}
		}
	}
	int ret=1<<30;
	for(int i=0; i<=K; i++)ret=min(ret,dist[n][i]);
	return ret;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&K);
	while(m--){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		addEdge(u,v,d);
		addEdge(v,u,d);
	}
	printf("%d\n",DIJ());
	return 0;
}
