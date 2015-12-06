#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <math.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define PROB
using namespace std;

#define N 10010
#define M 1000010

int s,t;

int le[N],pe[M],ev[M],ecnt;
void addEdge(int u,int v){
	ecnt++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ev[ecnt]=v;
}


vector<int> g[N],inscc[N];
stack<int> st;
int dfs_clock,sccno[N],pre[N],low[N],sccn,goable[N],id[N];
void dfs(int u){
	st.push(u);
	pre[u]=low[u]=++dfs_clock;
	for(int i=le[u]; i; i=pe[i]){
		int &v=ev[i];
		if(!pre[v]){
			dfs(v);
			low[u]=min(low[u],low[v]);
		}else if(!sccno[v])
			low[u]=min(low[u],pre[v]);
	}
	if(low[u]==pre[u]){
		sccn++;
		while(true){
			int v=st.top();
			inscc[sccn].push_back(v);
			sccno[v]=sccn;
			st.pop();
			if(u==v)break;
		}
		sort(inscc[sccn].begin(),inscc[sccn].end());
		Rep(i,inscc[sccn].size())
			id[inscc[sccn][i]]=i;
	}
}

double mat[110][110];
void calc(int n){
	for(int i=0; i<n; i++){
		int r=i;
		double maxle=0;
		for(int j=i+1; j<n; j++){
			if(fabs(mat[j][i])>fabs(mat[r][i]))
				r=j;
			maxle=max(maxle,fabs(mat[j][i]));
		}
		if(maxle<1e-8)continue; 
		if(r!=i)for(int j=i; j<=n; j++)
			swap(mat[r][j],mat[i][j]);
		for(int j=i+1; j<n; j++){
			for(int k=n; k>=i; --k)
				mat[j][k]-=mat[i][k]/mat[i][i]*mat[j][i];
		}
	}
	for(int i=n-1; i>=0; --i){
		for(int j=i+1; j<n; j++)
			mat[i][n]-=mat[j][n]*mat[i][j];
		mat[i][n]/=mat[i][i];
	}
}

int deg[N],vis[N];
double ep[N];
void dp(int u){
	if(vis[u])return;
	vis[u]=1;
	if(g[u].empty() && sccno[t]!=u){
		puts("INF");
		exit(0);
	}
	for(int i=0; i<g[u].size(); i++)
		dp(g[u][i]);
		
	memset(mat,0,sizeof(mat));
	int sz=inscc[u].size();
	for(int i=0; i<sz; i++){
		int &v=inscc[u][i];
		if(v!=t){
			mat[i][i]=deg[v];
			int cnt=0;
			for(int j=le[v]; j; j=pe[j]){
				if(sccno[ev[j]]==u)
					mat[i][id[ev[j]]]--;
				else
					mat[i][sz]+=ep[ev[j]];
			}
			mat[i][sz]+=deg[v];
		}else
			mat[i][i]=1;
	}
	calc(sz);
	for(int i=0; i<sz; i++){
		int &v=inscc[u][i];
		ep[v]=mat[i][sz];
	}
}

int n,m;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d%d%d",&n,&m,&s,&t);
	if(s==t){
		puts("0");
		return 0;
	}
	For(i,m){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		deg[u]++;
	}
	
	For(i,n)if(!pre[i])dfs(i);
	For(u,n){
		for(int j=le[u]; j; j=pe[j]){
			int &v=ev[j];
			if(sccno[v]!=sccno[u] && u!=t)
				g[sccno[u]].push_back(sccno[v]);
		}
	}
	dp(sccno[s]);
	printf("%.3f",ep[s]);
	return 0;
}

