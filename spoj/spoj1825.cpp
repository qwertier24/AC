#include <algorithm>
#include <stdio.h>
#include <string.h>
#define N 200010
using namespace std;

int n,m,ans;

int le[N],pe[N<<1],ev[N<<1],ed[N<<1],ecnt;
void addEdge(int u,int v,int d){
	ev[ecnt]=v;
	ed[ecnt]=d;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ecnt++;
}

int grav,cur_sz,sz[N],msz,del[N];
void find_grav(int u,int fa){
	sz[u]=1;
	int tsz=0;
	for(int i=le[u]; i!=-1; i=pe[i]){
		int &v=ev[i];
		if(del[v] || v==fa)continue;
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
		if(del[v] || v==fa)continue;
		ret+=calc_sz(v,u);
	}
	return ret;
}

int mark[N];
int dep[N];
int calc_dep(int u,int fa,int d){
	int ret=d;
	for(int i=le[u]; i!=-1; i=pe[i]){
		int &v=ev[i];
		if(del[v] || v==fa)continue;
		ret=max(ret,calc_dep(v,u,d+mark[v]));
	}
	return ret;
}

int a[N];
bool cmp(const int& a,const int& b){
	return dep[a]<dep[b];
}

int cur[N],max_dep,dist[N],f[N],fmax;
void calc_f(int u,int fa,int d,int cnt){
	if(cnt>fmax){
		fmax=cnt;
		f[cnt]=d;
	}else
		f[cnt]=max(f[cnt],d);
	for(int i=le[u]; i!=-1; i=pe[i]){
		int &v=ev[i];
		if(del[v] || v==fa)continue;
		calc_f(v,u,d+ed[i],cnt+mark[v]);
	}
}
void dfs(int u){
	del[u]=1;
	for(int i=le[u]; i!=-1; i=pe[i]){
		int &v=ev[i];
		if(del[v])continue;
		cur_sz=calc_sz(v,0);
		grav=0;
		find_grav(v,0);
		//printf("u:%d grav:%d\n",u,grav);
		dfs(grav);
	}
	
	a[0]=0;
	for(int i=le[u]; i!=-1; i=pe[i]){
		int &v=ev[i];
		if(del[v])continue;
		dep[v]=calc_dep(v,0,mark[v]);
		a[++a[0]]=v;
		dist[v]=ed[i];
	}
	sort(a+1,a+a[0]+1,cmp);
	cur[0]=0;
	//printf("cur:%d\n",u);
	max_dep=0;
	for(int i=1; i<=a[0]; i++){
		int &v=a[i];
		fmax=0;
		f[0]=0;
		calc_f(v,0,dist[v],mark[v]);
		for(int j=0; j<=dep[v]; j++)if(m>=j+mark[u]){
			ans=max(ans,cur[min(m-j-mark[u],max_dep)]+f[j]);
			//printf("%d %d %d %d\n",v,j,f[j],min(m-j-mark[u],max_dep));
		}
		for(int j=0; j<=max_dep; j++)
			cur[j]=max(cur[j],f[j]);
		for(int j=max_dep+1; j<=dep[v]; j++)
			cur[j]=f[j];
		max_dep=dep[v];
		for(int j=1; j<=max_dep; j++)
			cur[j]=max(cur[j],cur[j-1]);
	}
	del[u]=0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int k;
	memset(le,-1,sizeof(le));
	scanf("%d%d%d",&n,&m,&k);
	while(k--){
		int t;
		scanf("%d",&t);
		mark[t]=1;
	}
	for(int i=1; i<n; i++){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		addEdge(u,v,d);
		addEdge(v,u,d);
	}
	cur_sz=n;
	grav=0;
	find_grav(1,0);
	dfs(grav);
	printf("%d\n",ans);
	return 0;
}

