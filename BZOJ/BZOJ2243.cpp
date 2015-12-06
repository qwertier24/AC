#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB
#define N 100010
#define For(i,n) for(int i=1; i<=n; i++)
using namespace std;

int n;

int le[N],pe[N<<1],ev[N<<1],ecnt;
void addEdge(int u,int v){
	ecnt++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ev[ecnt]=v;
}

int ori[N],a[N];

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
int cl[N<<2],cr[N<<2],sumv[N<<2],setv[N<<2],L,R,setc;
inline void maintain(int o){
	cl[o]=cl[lc];
	cr[o]=cr[rc];
	sumv[o]=sumv[lc]+sumv[rc]-(cr[lc]==cl[rc]);
}
inline void pushdown(int o){
	if(setv[o]!=-1){
		cl[lc]=cr[lc]=setv[lc]=setv[o];
		sumv[lc]=1;
		cl[rc]=cr[rc]=setv[rc]=setv[o];
		sumv[rc]=1;
		setv[o]=-1;
	}
}
void build(int o=1,int l=1,int r=n){
	if(l==r){
		cl[o]=cr[o]=a[l];
		sumv[o]=1;
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	maintain(o);
}
void update(int o=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		cl[o]=cr[o]=setv[o]=setc;
		sumv[o]=1;
		return;
	}
	pushdown(o);
	if(L<=mid)update(lc,l,mid);
	if(R>mid)update(rc,mid+1,r);
	maintain(o);
}
struct ANS{
	int cl,cr,sumv;
	ANS(int a,int b,int c):cl(a),cr(b),sumv(c){}
	ANS operator+(const ANS& r){
		return ANS(cl,r.cr,sumv+r.sumv-(cr==r.cl));
	}
};
ANS query(int o=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return ANS(cl[o],cr[o],sumv[o]);
	pushdown(o);
	if(R<=mid)return query(lc,l,mid);
	if(L>mid)return query(rc,mid+1,r);
	return query(lc,l,mid)+query(rc,mid+1,r);
}

int fa[N],sz[N],hson[N],dep[N];
void dfs1(int u){
	sz[u]=1;
	for(int i=le[u]; i; i=pe[i]){
		int &v=ev[i];
		if(v==fa[u])continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[hson[u]])hson[u]=v;
	}
}
int dfs_clock,top[N],id[N];
void dfs2(int u){
	id[u]=++dfs_clock;
	//printf("id[%d]=%d\n",u,id[u]);
	if(hson[u]){
		top[hson[u]]=top[u];
		dfs2(hson[u]);
	}
	for(int i=le[u]; i; i=pe[i]){
		int &v=ev[i];
		if(v==fa[u] || v==hson[u])continue;
		top[v]=v;
		dfs2(v);
	}
}

int Query(int u,int v){
	ANS ans1(-1,-1,0),ans2(-2,-2,0);
	while(top[u]!=top[v]){
		if(dep[top[u]]>dep[top[v]]){
			L=id[top[u]],R=id[u];
			ANS q=query();
			ans1=q+ans1;
			u=fa[top[u]];
		}else{
			L=id[top[v]],R=id[v];
			ANS q=query();
			ans2=q+ans2;
			v=fa[top[v]];
		}
	}
	if(dep[u]>dep[v]){
		L=id[v],R=id[u];
		ANS q=query();
		swap(ans2.cr,ans2.cl);
		return (ans2+q+ans1).sumv;
	}else{
		L=id[u],R=id[v];
		ANS q=query();
		swap(ans1.cl,ans1.cr);
		return (ans1+q+ans2).sumv;
	}
}
void Modify(int u,int v,int c){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		L=id[top[u]],R=id[u];
		update();
		u=fa[top[u]];
	}
	if(dep[u]<dep[v])swap(u,v);
	L=id[v],R=id[u];
	update();
}
int m;
char op[10];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	For(i,n)scanf("%d",&ori[i]);
	For(i,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	dfs1(1);
	top[1]=1;
	dfs2(1);
	For(i,n)a[id[i]]=ori[i];
	memset(setv,-1,sizeof(setv));
	build();
	while(m--){
		int u,v,c;
		scanf("%s",op);
		if(op[0]=='Q'){
			scanf("%d%d",&u,&v);
			printf("%d\n",Query(u,v));
		}else{
			scanf("%d%d%d",&u,&v,&setc);
			Modify(u,v,c);
		}
	}
	return 0;
}

