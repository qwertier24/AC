#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 100010

int L,R;

int le[N],pe[N<<1],ev[N<<1],ed[N<<1],gravity[N<<1],depth[N<<1],ecnt;
double e_dist[N<<1];
void addEdge(int u,int v,int d){
	ecnt++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ev[ecnt]=v;
	ed[ecnt]=d;
}

int del[N];

int calc_sz(int u,int fa){
	int ret=1;
	for(int i=le[u]; i; i=pe[i])
		if(!del[ev[i]] && ev[i]!=fa)
			ret+=calc_sz(ev[i],u);
	return ret;
}
int grav,cur_sz,msz,sz[N];
void calc_grav(int u,int fa){
	sz[u]=1;
	int tsz=0;
	for(int i=le[u]; i; i=pe[i])
		if(!del[ev[i]] && ev[i]!=fa){
			calc_grav(ev[i],u);
			sz[u]+=sz[ev[i]];
			tsz=max(tsz,sz[ev[i]]);
		}
	tsz=max(tsz,cur_sz-sz[u]);
	if(!grav || msz>tsz){
		msz=tsz;
		grav=u;
	}
}

int dep[N];
double dis[N];
int calc_dep(int u,int fa){
	int ret=0;
	for(int i=le[u]; i; i=pe[i])
		if(!del[ev[i]] && ev[i]!=fa)
			ret=max(ret,calc_dep(ev[i],u));
	return ret+1;
}
void find_all_grav(int u){
	del[u]=1;
	for(int i=le[u]; i; i=pe[i])
		if(!del[ev[i]]){
			int &v=ev[i];
			cur_sz=calc_sz(v,0);
			depth[i]=calc_dep(v,0);
			if(cur_sz<L)continue;
			grav=0;
			calc_grav(v,0);
			gravity[i]=grav;
			find_all_grav(gravity[i]);
		}
	del[u]=0;
}

int flag;

int q[N],fr,rr;
inline void calc(double *a,int an,double *b,int bn){
	double ret=-1e60;
	fr=1,rr=0;
	int l=1,r=0;
	for(int i=an; i; i--){
		while(r+1<=bn && r+1<=R-i){
			++r;
			while(fr<=rr && b[q[rr]]<=b[r])
				rr--;
			q[++rr]=r;
		}
		while(fr<=rr && q[fr]<L-i)
			fr++;
		if(fr<=rr && a[i]+b[q[fr]]>-1e-7){
			flag=1;
			return;
		}
	}
}

int a[N];
bool cmp(const int &a,const int& b){
	return dep[a]<dep[b];
}

int maxf;
double f[N];
void calc_f(int u,int fa,int cnt,double d){
	if(maxf<cnt){
		maxf=cnt;
		f[cnt]=d;
	}else
		f[cnt]=max(f[cnt],d);
	for(int i=le[u]; i; i=pe[i])
		if(!del[ev[i]] && ev[i]!=fa)
			calc_f(ev[i],u,cnt+1,d+e_dist[i]);
}
int max_dep;
double g[N];
void dfs(int u){
	del[u]=1;
	for(int i=le[u]; i; i=pe[i])
		if(gravity[i]){
			dfs(gravity[i]);
			if(flag)return;
		}
	a[0]=0;
	for(int i=le[u]; i; i=pe[i]){
		if(del[ev[i]])continue;
		a[++a[0]]=ev[i];
		dis[ev[i]]=e_dist[i];
		dep[ev[i]]=depth[i];
	}
	sort(a+1,a+a[0]+1,cmp);
	max_dep=0;
	g[0]=0;
	for(int i=1; i<=a[0]; i++){
		int &v=a[i];
		maxf=f[0]=0;
		calc_f(v,0,1,dis[v]);
		calc(f,dep[v],g,max_dep);
		if(flag)return;
		for(int j=1; j<=max_dep; j++)
			g[j]=max(g[j],f[j]);
		for(int j=max_dep+1; j<=dep[v]; j++)
			g[j]=f[j];
		max_dep=dep[v];
	}
	del[u]=0;
}

int n;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&L,&R);
	for(int i=1; i<n; i++){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		addEdge(u,v,d);
		addEdge(v,u,d);
	}
	cur_sz=n;
	calc_grav(1,0);
	gravity[0]=grav;
	find_all_grav(gravity[0]);
	
	double t=784077.5;
	for(int i=1; i<=ecnt; i++)
		e_dist[i]=ed[i]-t;
	double lo=0,hi=1e6;
	while(hi-lo>1e-5){
		double mi=(lo+hi)/2.;
		for(int i=1; i<=ecnt; i++)
			e_dist[i]=ed[i]-mi;
		flag=0;
		dfs(gravity[0]);
		if(flag)lo=mi;
		else hi=mi;
	}
	printf("%.3f",lo);
	return 0;
}

