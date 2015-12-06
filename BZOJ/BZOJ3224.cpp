#include<stdio.h>
#define N 100010
#define lc node[o].ch[0]
#define rc node[o].ch[1]
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

int random(){
	static int ranx=123456789;
	ranx+=(ranx<<2)+1;
	return ranx;
}

struct Node{
	int sz,v,r,ch[2];
	inline int cmp(int x){
		if(v==x)return -1;
		return v<x;
	}
	inline bool operator<(const Node& rhs){
		return r<rhs.r;
	}
	inline void maintain();
}node[N];
inline void Node::maintain(){
	sz=node[ch[0]].sz+node[ch[1]].sz+1;
}

int st[N],tp;
int newNode(int v){
	node[st[tp]].r=random();
	node[st[tp]].v=v;
	node[st[tp]].sz=1;
	node[st[tp]].ch[0]=node[st[tp]].ch[1]=0;
	int ret=st[tp];
	tp--;
	return ret;
}

void rotate(int &o,int d){
	int k=node[o].ch[d];
	node[o].ch[d]=node[k].ch[1^d];
	node[k].ch[1^d]=o;
	node[o].maintain();
	node[k].maintain();
	o=k;
}

int x;
void insert(int &o){
	if(!o){
		o=newNode(x);
		return;
	}
	int d=node[o].v<x;
	insert(node[o].ch[d]);
	if(node[o]<node[node[o].ch[d]])
		rotate(o,d);
	node[o].maintain();
}
void erase(int &o){
	int d=node[o].cmp(x);
	if(d==-1){
		if(!node[o].ch[1]){
			int tmp=o;
			o=node[o].ch[0];
			st[++tp]=tmp;
		}else if(!node[o].ch[0]){
			int tmp=o;
			o=node[o].ch[1];
			st[++tp]=tmp;
		}else{
			int d2=node[lc]<node[rc];
			rotate(o,d2);
			erase(node[o].ch[1^d2]);
		}
	}else
		erase(node[o].ch[d]);
	if(o)node[o].maintain();
}

int ans;
int kth(int &o,int k){
	int lsz=node[node[o].ch[0]].sz;
	if(lsz+1==k)return node[o].v;
	if(k<=lsz)return kth(node[o].ch[0],k);
	return kth(node[o].ch[1],k-lsz-1);
}
void rank(int &o,int k){
	if(!o)return;
	int lsz=node[lc].sz;
	if(node[o].v==x){
		ans=min(ans,k+lsz+1);
		rank(lc,k);
	}else if(node[o].v<x){
		rank(rc,k+lsz+1);
	}else{
		rank(lc,k);
	}
}
void pre(int &o){
	if(!o)return;
	if(node[o].v<x){
		ans=max(ans,node[o].v);
		pre(rc);
	}else
		pre(lc);
}
void suf(int &o){
	if(!o)return;
	if(node[o].v>x){
		ans=min(ans,node[o].v);
		suf(lc);
	}else
		suf(rc);
}

int m,root;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	for(int i=1; i<=100000; i++)
		st[++tp]=i;
	scanf("%d",&m);
	while(m--){
		int op;
		scanf("%d%d",&op,&x);
		switch(op){
		case 1:
			insert(root);
			break;
		case 2:
			erase(root);
			break;
		case 3:
			ans=1<<30;
			rank(root,0);
			printf("%d\n",ans);
			break;
		case 4:
			printf("%d\n",kth(root,x));
			break;
		case 5:
			ans=-(1<<30);
			pre(root);
			printf("%d\n",ans);
			break;
		case 6:
			ans=1<<30;
			suf(root);
			printf("%d\n",ans);
			break;
		}
	}
	return 0;
}
