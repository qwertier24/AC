#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 110
#define M 20010
using namespace std;

int le[N],ev[M],ed[M],pe[M],deg[N],ecnt;
void addEdge(int u,int v,int d){
	ecnt++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ed[ecnt]=d;
	ev[ecnt]=v;
	
}

double mat[N][N];
void calc(int n){
	Rep(i,n){
		int r=i;
		for(int j=i+1; j<n; j++)
			if(fabs(mat[j][i])>fabs(mat[r][i]))
				r=j;
		if(r!=i)for(int j=i; j<=n; j++)
			swap(mat[r][j],mat[i][j]);
		for(int j=i+1; j<n; j++)
			for(int k=n; k>=i; k--)
				mat[j][k]-=mat[j][i]/mat[i][i]*mat[i][k];
	}
	for(int i=n-1; i>=0; i--){
		for(int j=i+1; j<n; j++)
			mat[i][n]-=mat[i][j]*mat[j][n];
		mat[i][n]/=mat[i][i];
	}
	//Rep(i,n)Rep(j,n+1)printf("%f%s",mat[i][j],j==n?"\n":" ");
	//puts("");
}
int n,m;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		u--;v--;
		addEdge(u,v,d);
		deg[u]++;
		if(v!=u){
			deg[v]++;
			addEdge(v,u,d);
		}
	}
	double ans=0;
	Rep(dig,30){
		memset(mat,0,sizeof(mat));
		Rep(u,n-1){
			mat[u][u]=deg[u];
			for(int i=le[u]; i; i=pe[i]){
				int &v=ev[i];
				if((ed[i]>>dig)&1){
					mat[u][n]++;
					mat[u][v]++;
				}else{
					mat[u][v]--;
				}
			}
		}
		mat[n-1][n-1]=1;
		calc(n);
		ans+=double(1<<dig)*mat[0][n];
	}
	printf("%.3f\n",ans);
	return 0;
}

