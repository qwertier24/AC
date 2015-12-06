#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <math.h>
#include <iostream>
#define PROB
#define For(i,n) for(int i=1; i<=n; i++)
using namespace std;

#define N 510
#define M N*N

long double mat[N][N];
void solve(int n){
	For(i,n){
		int cur=i;
		for(int j=i; j<=n; j++)
			if(fabs(mat[j][i])>fabs(mat[cur][i]))
				cur=j;
		if(cur!=i)for(int j=i; j<=n+1; j++)
			swap(mat[cur][j],mat[i][j]);
		for(int j=i+1; j<=n; j++){
			for(int k=n+1; k>=i; k--)
				mat[j][k]-=mat[i][k]/mat[i][i]*mat[j][i];
		}
	}
	for(int i=n; i; i--){
		for(int j=i+1; j<=n; j++)
			mat[i][n+1]-=mat[i][j]*mat[j][n+1];
		mat[i][n+1]/=mat[i][i];
	}
}

struct Edge{
	int u,v;
	long double ep;
	bool operator<(const Edge& r)const{
		return ep>r.ep;
	}
}e[M];
int deg[N],n,m;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	For(i,m){
		scanf("%d%d",&e[i].u,&e[i].v);
		deg[e[i].u]++;deg[e[i].v]++;
	}
	For(i,n-1)mat[i][i]=1;
	For(i,m){
		if(e[i].u!=n && e[i].v!=n){
			mat[e[i].u][e[i].v]=-1.0/deg[e[i].v];
			mat[e[i].v][e[i].u]=-1.0/deg[e[i].u];
		}
	}
	mat[1][n]=1;
	solve(n-1);
	For(i,m)
		e[i].ep=mat[e[i].u][n]/deg[e[i].u] + mat[e[i].v][n]/deg[e[i].v];
	sort(e+1,e+m+1);
	double ans=0;
	For(i,m)ans+=e[i].ep*i;
	printf("%.3f\n",ans);
	return 0;
}

