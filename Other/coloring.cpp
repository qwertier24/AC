#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#define PROB "coloring"
#define MOD 1000000007
using namespace std;
int sum[5010]={0},d[5010][5010]={0};
int n,m;
vector<int> adj[5010],color[5010];
void dp(int u,int f){
	for(int i=0; i<adj[u].size(); i++)
		if(adj[u][i]!=f)
			dp(adj[u][i],u);
	for(int i=0; i<color[u].size(); i++){
		int c=color[u][i];
		d[u][c]=1;
		//printf("%d %d %d\n",u,c,d[u][c]);
		for(int j=0; j<adj[u].size(); j++)
			if(adj[u][j]!=f){
				int v=adj[u][j];
				d[u][c]=((d[u][c]*((long long)sum[v]-d[v][c]))%MOD+MOD)%MOD;
			}
		sum[u]=(sum[u]+d[u][c])%MOD;
	}
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		int t;
		scanf("%d",&t);
		for(int j=0; j<t; j++){
			int tt;
			scanf("%d",&tt);
			color[i].push_back(tt);
		}
	}
	for(int i=1; i<n; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dp(1,0);
	printf("%d",(sum[1]+MOD)%MOD);
	return 0;
}

