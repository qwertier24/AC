#include<stdio.h>
#define N 100010
typedef long long LL;

int a[N];

LL MOD;

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
LL sum[N<<2],add[N<<2],mul[N<<2];
int L,R;
void build(int o,int l,int r){
	mul[o]=1;
	if(l==r){
		sum[o]=a[l];
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	sum[o]=(sum[lc]+sum[rc])%MOD;
}
inline void Add(int o,int l,int r,LL dx){
	add[o]=(add[o]+dx)%MOD;
	sum[o]=(sum[o]+(r-l+1)*dx)%MOD;
}
inline void Mul(int o,int l,int r,LL dx){
	mul[o]=mul[o]*dx%MOD;
	add[o]=add[o]*dx%MOD;
	sum[o]=sum[o]*dx%MOD;
}
inline void pushdown(int o,int l,int r){
	if(mul[o]!=1)Mul(lc,l,mid,mul[o]);
	if(add[o]>0)Add(lc,l,mid,add[o]);
	if(mul[o]!=1)Mul(rc,mid+1,r,mul[o]);
	if(add[o]>0)Add(rc,mid+1,r,add[o]);
	mul[o]=1;
	add[o]=0;
}
inline void maintain(int o,int l,int r){
	sum[o]=(sum[lc]+sum[rc])%MOD;
	//sum[o]=(sum[o]*mul[o])%MOD;
	//sum[o]=(sum[o]+(r-l+1)*add[o])%MOD;
}
void update(int o,int l,int r,int &op,int &x){
	if(L<=l && r<=R){
		if(op==1)Mul(o,l,r,x);
		else Add(o,l,r,x);
		return;
	}
	pushdown(o,l,r);
	if(L<=mid)update(lc,l,mid,op,x);
	if(R>mid)update(rc,mid+1,r,op,x);
	maintain(o,l,r);
}
LL query(int o,int l,int r){
	if(L<=l && r<=R)return sum[o];
	pushdown(o,l,r);
	if(R<=mid)return query(lc,l,mid);
	if(L>mid)return query(rc,mid+1,r);
	return (query(lc,l,mid)+query(rc,mid+1,r))%MOD;
}

int n,m;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%lld",&n,&MOD);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	while(m--){
		int op,x;
		scanf("%d%d%d",&op,&L,&R);
		if(op<=2){
			scanf("%d",&x);
			update(1,1,n,op,x);
		}else
			printf("%lld\n",query(1,1,n));
	}
	return 0;
}
