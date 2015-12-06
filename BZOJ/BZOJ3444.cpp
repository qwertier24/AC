#include <algorithm>
#include <stdio.h>
#include <string.h>
#define PROB
#define MOD 989381
#define N 500010
#define For(i,n) for(int i=1; i<=n; i++)
using namespace std;

int pa[N],deg[N],n,m,u,v;
int findset(int u){
	if(pa[u]!=u)pa[u]=findset(pa[u]);
	return pa[u];
}

int vis[N],sz[N],f[N][2];
int main(){
	scanf("%d%d",&n,&m);
	For(i,n)pa[i]=i;
	while(m--){
		scanf("%d%d",&u,&v);
		if(v==f[u][0] || v==f[u][1])continue;
		f[u][f[u][0]!=0]=v;
		f[v][f[v][0]!=0]=u;
		deg[u]++;
		deg[v]++;
		if(deg[u]>2 || deg[v]>2){
			puts("0");
			return 0;
		}
		int fa=findset(u),fb=findset(v);
		if(fa==fb){
			puts("0");
			return 0;
		}else{
			pa[fa]=fb;
			sz[fa]+=sz[fb];
		}
	}
	int cnt1=0,cnt2=0;
	For(i,n)sz[findset(i)]++;
	For(i,n)if(!vis[pa[i]]){
		vis[pa[i]]=1;
		cnt1++;
		if(sz[pa[i]]>1)cnt2++;
	}
	int ans=1;
	For(i,cnt1)ans=ans*(long long)i%MOD;
	For(i,cnt2)ans=ans*2%MOD;
	printf("%d\n",ans);
	return 0;
}

