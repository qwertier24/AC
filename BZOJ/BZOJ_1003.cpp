#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define T 100
#define N 20
#define M 1000
#define INF (1<<28)
using namespace std;

int n,m,K,t;

int last_edge[N+10]={0},ev[M],ed[M],pre_edge[M],ecnt=0;
void addEdge(int u,int v,int d){
	ecnt++;
	pre_edge[ecnt]=last_edge[u];
	last_edge[u]=ecnt;
	ev[ecnt]=v;
	ed[ecnt]=d;
}

struct Edge{
	int u,v,d;
}edges[M];

int disable[N+10][T+10]={0};
bool check(int p,int l,int r){
	return disable[p][l-1]==disable[p][r];
}

int inq[M+10],dist[M+10];
int spfa(int l,int r){
	queue<int> q;
	For(i,n)dist[i]=INF;
	memset(inq,0,sizeof(inq));
	q.push(1);
	dist[1]=0;
	inq[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=last_edge[u]; i; i=pre_edge[i]){
			int v=ev[i],d=ed[i];
			if(check(v,l,r)){
				if(dist[v]>dist[u]+d){
					dist[v]=dist[u]+d;
					if(!inq[v]){
						inq[v]=1;
						q.push(v);
					}
				}
			}
		}
	}
	return dist[n];
}

int dp[N+10];
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.txt","r",stdin);
#endif
	scanf("%d%d%d%d",&t,&n,&K,&m);
	For(i,m){
	 	scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].d);
	 	addEdge(edges[i].u,edges[i].v,edges[i].d);
	 	addEdge(edges[i].v,edges[i].u,edges[i].d);
	}

	int n2;
	scanf("%d",&n2);
	while(n2--){
		int p,l,r;
		scanf("%d%d%d",&p,&l,&r);
		for(int j=l; j<=r; j++)
			disable[p][j]=1;
	}

	For(i,n)
		For(j,t){
			disable[i][j]+=disable[i][j-1];
		}

	dp[0]=0;
	For(i,t){
		dp[i]=INF;
		for(int j=i-1; j>=0; j--){
			int min_d=spfa(j+1,i);
			if(min_d==INF)
				break;
			dp[i]=min(dp[i],dp[j]+min_d*(i-j)+K);
		}
	}

	printf("%d",dp[t]-K);
}
