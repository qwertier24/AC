#include<stdio.h>
#include<algorithm>
#define N 100010
#define MOD 51061
typedef unsigned int uint;
using std::swap;

struct Node{
	uint mul,add,sum,v,sz;
	int rev;
	int ch[2],fa,path_fa;
	void Add(uint dx){
		add=(add+dx)%MOD;
		sum=(sum+sz*dx)%MOD;
	}
	void Mul(uint dx){
		add=add*dx%MOD;
		mul=mul*dx%MOD;
		sum=sum*dx%MOD;
	}
	inline void maintain();
	inline void pushdown();
}node[N];

inline void Node::maintain(){
	sz=node[ch[0]].sz+node[ch[1]].sz+1;
	sum=(node[ch[0]].sum+node[ch[1]].sum+v)%MOD;
	sum=sum*mul%MOD;
	sum=(sum+add*sz)%MOD;
}
inline void Node::pushdown(){
	v=(v*mul+add)%MOD;
	if(mul!=1){
		node[ch[0]].Mul(mul);
		node[ch[1]].Mul(mul);
	}
	if(add>0){
		node[ch[0]].Add(add);
		node[ch[1]].Add(add);
	}
	mul=1;
	add=0;
	if(rev){
		node[ch[0]].rev^=1;
		node[ch[1]].rev^=1;
		swap(ch[0],ch[1]);
		rev=0;
	}
}

void rotate(int o,int d){
	int k=node[o].ch[d],fa=node[o].fa;
	
	node[node[k].ch[!d]].fa=o;
	node[o].fa=k;
	node[k].fa=fa;
	
	node[o].ch[d]=node[k].ch[!d];
	node[k].ch[!d]=o;
	node[fa].ch[node[fa].ch[1]==o]=k;
	
	node[o].maintain();
	node[k].maintain();
}
int down[N];
void splay(int p){
	int cur=p;
	down[0]=0;
	while(cur){
		down[++down[0]]=cur;
		cur=node[cur].fa;
	}
	for(int i=down[0]; i; i--)
		node[down[i]].pushdown();
	if(down[down[0]]!=p){
		node[p].path_fa=node[down[down[0]]].path_fa;
		node[down[down[0]]].path_fa=0;
	}
	int fa,gfa,d,d2;
	while(node[p].fa){
		fa=node[p].fa;
		gfa=node[fa].fa;
		d=node[fa].ch[1]==p;
		d2=node[gfa].ch[1]==fa;
		if(!gfa)rotate(fa,d);
		else if(d==d2){rotate(gfa,d2);rotate(fa,d);}
		else{rotate(fa,d);rotate(gfa,d2);}
	}
}

void access(int p){
	splay(p);
	node[p].pushdown();
	node[node[p].ch[1]].fa=0;
	node[node[p].ch[1]].path_fa=p;
	node[p].ch[1]=0;
	node[p].maintain();
	for(int q=node[p].path_fa; q; q=node[p].path_fa){
		splay(q);
		node[q].pushdown();
		node[node[q].ch[1]].fa=0;
		node[node[q].ch[1]].path_fa=q;
		node[q].ch[1]=p;
		node[q].maintain();
		node[p].fa=q;
		node[p].path_fa=0;
		p=q;
	}
}

void evert(int p){
	access(p);
	splay(p);
	node[p].rev^=1;
}
void link(int u,int v){
	evert(u);
	splay(u);
	access(v);
	splay(v);
	node[v].pushdown();
	node[v].ch[1]=u;
	node[u].fa=v;
	node[v].maintain();
}
void cut(int u,int v){
	evert(u);
	access(v);
	splay(u);
	node[u].pushdown();
	node[u].ch[1]=0;
	node[v].fa=0;
	node[v].path_fa=0;
	node[u].maintain();
}

int le[N],pe[N<<1],ev[N<<1],ecnt;
void addEdge(int u,int v){
	ecnt++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ev[ecnt]=v;
}
void build(int u,int fa){
	node[u].path_fa=fa;
	node[u].v=node[u].sz=node[u].sum=node[u].mul=1;
	for(int i=le[u]; i; i=pe[i]){
		if(ev[i]==fa)continue;
		build(ev[i],u);
	}
}

int n,q;
char op[10];
int u,v,x;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&q);
	for(int i=1; i<n; i++){
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	build(1,0);
	while(q--){
		scanf("%s",op);
		switch(op[0]){
		case '+':
			scanf("%d%d%d",&u,&v,&x);
			evert(u);
			access(v);
			splay(v);
			node[v].Add(x);
			break;
		case '-':
			scanf("%d%d",&u,&v);
			cut(u,v);
			scanf("%d%d",&u,&v);
			link(u,v);
			break;
		case '*':
			scanf("%d%d%d",&u,&v,&x);
			evert(u);
			access(v);
			splay(v);
			node[v].Mul(x);
			break;
		case '/':
			scanf("%d%d",&u,&v);
			evert(u);
			access(v);
			splay(v);
			printf("%u\n",node[v].sum);
			break;
		}
	}
	return 0;
}
