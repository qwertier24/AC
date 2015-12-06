#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define INF (1<<30)
#define N 10010
using namespace std;

int n,m,ans;

int le[N],pe[N<<1],ev[N<<1],ed[N<<1],ecnt;
void addEdge(int u,int v,int d){
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ev[ecnt]=v;
	ed[ecnt]=d;
	ecnt++;
}

int sz[N],mark[N],cur_sz,grav,msz;
void find_grav(int u,int fa){
	int tsz=0;
	sz[u]=1;
	for(int i=le[u]; i!=-1; i=pe[i]){
		if(mark[ev[i]] || ev[i]==fa)continue;
		int &v=ev[i];
		find_grav(v,u);
		sz[u]+=sz[v];
		tsz=max(tsz,sz[v]);
	}
	tsz=max(tsz,cur_sz-sz[u]);
	if(!grav || tsz<msz){
		msz=tsz;
		grav=u;
	}
}

int calc_sz(int u,int fa){
	int ret=1;
	for(int i=le[u]; i!=-1; i=pe[i]){
		int &v=ev[i];
		if(mark[v] || v==fa)continue;
		ret+=calc_sz(v,u);
	}
	return ret;
}

int a[N];
void getv(int u,int fa,int d){
	a[++a[0]]=d;
	for(int i=le[u]; i!=-1; i=pe[i]){
		int &v=ev[i];
		if(mark[v] || v==fa)continue;
		getv(v,u,d+ed[i]);
	}
}
int calc(){
	sort(a+1,a+a[0]+1);
	int l=1,r=a[0],ret=0;
	while(l<r){
		while(r>l && a[l]+a[r]>m)r--;
		ret+=r-l;
		l++;
	}
	return ret;
}

void dfs(int u){
	mark[u]=1;
	for(int i=le[u]; i!=-1; i=pe[i]){
		int &v=ev[i];
		if(mark[v])continue;
		cur_sz=calc_sz(v,u);
		grav=0;
		find_grav(v,u);
		dfs(grav);
	}
	
	a[0]=0;
	getv(u,0,0);
	ans+=calc();
	for(int i=le[u]; i!=-1; i=pe[i]){
		int &v=ev[i];
		if(mark[v])continue;
		a[0]=0;
		getv(v,u,ed[i]);
		ans-=calc();
	}
	mark[u]=0;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(scanf("%d%d",&n,&m) && n){
		memset(le,-1,sizeof(le));
		ecnt=0;
		for(int i=1; i<n; i++){
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			addEdge(u,v,d);
			addEdge(v,u,d);
		}
		cur_sz=n;
		grav=0;
		find_grav(1,0);
		ans=0;
		dfs(grav);
		printf("%d\n",ans);
	}
	return 0;
}

