#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

#define N 20010
int le[N],ev[N<<1],ed[N<<1],ecnt,pe[N<<1];
void addEdge(int u,int v,int d){
	ecnt++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ev[ecnt]=v;
	ed[ecnt]=d;
}

int f[N][3],d[N][3];
#define getm(x) (((x)%3+3)%3)
void dfs2(int u,int fa,int dis){
	if(fa){
		for(int i=0; i<3; i++){
			f[u][i]=d[fa][getm(i-dis)]+f[fa][getm(i-dis)]-d[u][getm(i-dis-dis)];
		}
	}
	for(int i=le[u]; i; i=pe[i]){
		int &v=ev[i];
		if(v==fa)continue;
		dfs2(v,u,ed[i]);
	}
}
void dfs(int u,int fa){
	d[u][0]=1;
	for(int i=le[u]; i; i=pe[i]){
		int &v=ev[i];
		if(v==fa)continue;
		dfs(v,u);
		for(int j=0; j<3; j++)d[u][j]+=d[v][getm(j-ed[i])];
	}
}

long long gcd(long long a,long long b){
	long long t;
	while(a){
		t=a;
		a=b%a;
		b=t;
	}
	return b;
}

int n;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		addEdge(u,v,d);
		addEdge(v,u,d);
	}
	dfs(1,0);
	dfs2(1,0,0);
	long long a=0,b=n*(long long)n;
	for(int i=1; i<=n; i++)a+=f[i][0]+d[i][0];
	printf("%lld/%lld",a/gcd(a,b),b/gcd(a,b));
	return 0;
}

