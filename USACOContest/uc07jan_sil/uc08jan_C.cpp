#include<stdio.h>
#include<vector>
#include<queue>
#include<cstring>
#define INF 1<<30
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
int vis[1010],n,m,k,max_dist,d[1010]={0},q[100010];
struct Edge{
	int v,d;
};
struct HeapNode{
	int u,d;
	bool operator<(const HeapNode& rhs)const{
		return d>rhs.d;
	}
};
vector<Edge> g[1010];
bool check1(){
	int front=0,rear=0,inq[1010]={0},cnt=1;
	For(i,1,n-1)d[i]=INF;
	inq[n]=1;
	q[0]=n;
	while(front<=rear){
		int u=q[front++];
		inq[u]=0;
		cnt--;
		For(i,0,g[u].size()-1){
			int v=g[u][i].v;
			if(d[v]>d[u]+(g[u][i].d>max_dist)){
				d[v]=d[u]+(g[u][i].d>max_dist);
				if(!inq[v]){
					inq[v]=1;
					q[++rear]=v;
					cnt++;
				}
			}
		}
	}
	return d[1]<=k;
}
bool check(){
	priority_queue<HeapNode> pq;
	For(i,1,n-1)d[i]=INF;
	pq.push((HeapNode){n,0});
	int done[1010]={0};
	while(!pq.empty()){
		HeapNode e=pq.top();
		int u=e.u;
		pq.pop();
		if(done[u])
			continue;
		For(i,0,g[u].size()-1){
			int v=g[u][i].v;
			if(d[v]>d[u]+(g[u][i].d>max_dist)){
				d[v]=d[u]+(g[u][i].d>max_dist);
				pq.push((HeapNode){v,d[v]});
			}
		}
	}
	return d[1]<=k;
}
int main(){
	freopen("prob.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,m){
		int f,t,d;
		scanf("%d%d%d",&f,&t,&d);
		g[f].push_back((Edge){t,d});
		g[t].push_back((Edge){f,d});
	}
	int l=0,r=int(1e6)+1;
	while(l<r){
		int m=(l+r)>>1;
		max_dist=m;
		if(check1())r=m;
		else l=m+1;
	}
	if(l==((int)1e6)+1)
		printf("-1");
	else
		printf("%d",l);
	return 0;
}
