#include<stdio.h>
#include<string.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef unsigned long long ULL;
#define N 10010
const ULL seed=13;
ULL psd[N];

struct Node{
	int val,rval,cnt;
	void modify(int v){
		val=rval=v;
		cnt=1;
	}
	Node operator+(Node t){
		Node ret;
		ret.cnt=cnt+t.cnt;
		ret.val=val*psd[t.cnt]+t.val;
		ret.rval=t.rval*psd[cnt]+rval;
		return ret;
	}
}node[N<<2];

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
void update(int o,int l,int r,int p,int v){
	if(l==r){
		node[o].modify(v);
		return;
	}
	if(p<=mid)update(lc,l,mid,p,v);
	else update(rc,mid+1,r,p,v);
	node[o]=node[lc]+node[rc];
}
Node query(int o,int l,int r,int L,int R){
	if(L<=l && r<=R)
		return node[o];
	if(R<=mid)return query(lc,l,mid,L,R);
	if(L>mid)return query(rc,mid+1,r,L,R);
	return query(lc,l,mid,L,R)+query(rc,mid+1,r,L,R);
}
void init(int o,int l,int r){
	if(l==r){node[o].modify(0);return;}
	init(lc,l,mid);
	init(rc,mid+1,r);
	node[o]=node[lc]+node[rc];
}

#define min(x,y) (x)<(y)?(x):(y)
int n,a[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	psd[0]=1;
	REP(i,1,10000)psd[i]=psd[i-1]*seed;
	while(T--){
		scanf("%d",&n);
		REP(i,1,n)scanf("%d",&a[i]);
		init(1,1,n);
		int flag=0;
		REP(i,1,n){
			int len=min(n-a[i],a[i]-1);
			update(1,1,n,a[i],1);
			if(len<1)continue;
			ULL h1=query(1,1,n,a[i]-len,a[i]-1).val,h2=query(1,1,n,a[i]+1,a[i]+len).rval;
			if(h1!=h2){
				flag=1;
				break;
			}
		}
		puts(flag?"Y":"N");
	}
	return 0;
}

