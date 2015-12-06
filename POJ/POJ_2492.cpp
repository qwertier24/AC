#include <stdio.h>
#include <algorithm>
#include <cstring>
#define INF -1
using namespace std;
int pa[2010],diff[2010],n,m;
int findset(int u){
	if(pa[u]!=u)pa[u]=findset(pa[u]);
	return pa[u];
}
void Union(int x,int y){
	findset(x);
	findset(y);
	pa[pa[x]]=pa[y];
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	for(int kase=1; kase<=T; kase++){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)pa[i]=i;
		bool flag=true;
		memset(diff,-1,sizeof(diff));
		for(int i=1; i<=m; i++){
			int u,v;
			scanf("%d%d",&u,&v);
			if(!flag)continue;
			findset(u);
			findset(v);
			if(pa[u]==pa[v])
				flag=false;
			else{
				if(diff[pa[u]]==INF)
					diff[pa[u]]=pa[v];
				if(diff[pa[v]]==INF)
					diff[pa[v]]=pa[u];
				Union(u,diff[pa[v]]);
				Union(v,diff[pa[u]]);
			}
		}
		if(flag)printf("Scenario #%d:\nNo suspicious bugs found!\n\n",kase);
		else printf("Scenario #%d:\nSuspicious bugs found!\n\n",kase);
	}
	return 0;
}
