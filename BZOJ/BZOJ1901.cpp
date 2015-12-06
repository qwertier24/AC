#include <algorithm>
#include <stdio.h>
#include <string.h>
#define PROB
#define For(i,n) for(int i=1; i<=n; i++)
#define lowbit(x) (x&(-x))
using namespace std;

#define N 10010
int n,m,a[N],b[N<<1];

#define SZ 5000000
#define mid ((l+r)>>1)
int sz,sumv[SZ],lc[SZ],rc[SZ];
void add(int &o,int p,int l,int r,int x){
	o=++sz;
	sumv[o]=sumv[p]+1;
	if(l==r)return;
	if(x<=mid){
		rc[o]=rc[p];
		add(lc[o],lc[p],l,mid,x);
	}else{
		lc[o]=lc[p];
		add(rc[o],rc[p],mid+1,r,x);
	}
}
void update(int &o,int l,int r,int x,int v){
	if(!o)o=++sz;
	sumv[o]+=v;
	if(l==r)return;
	if(x<=mid)update(lc[o],l,mid,x,v);
	else update(rc[o],mid+1,r,x,v);
}

int bit_root[N],root[N];
int plus[N],minus[N];
int query(int l,int r,int k){
	plus[0]=minus[0]=0;
	plus[++plus[0]]=root[r];
	minus[++minus[0]]=root[l-1];
	for(int p=r; p; p-=lowbit(p))
		plus[++plus[0]]=bit_root[p];
	for(int p=l-1; p; p-=lowbit(p))
		minus[++minus[0]]=bit_root[p];
	l=1,r=m;
	while(l<r){
		int cnt=0;
		For(i,plus[0])cnt+=sumv[lc[plus[i]]];
		For(i,minus[0])cnt-=sumv[lc[minus[i]]];
		if(cnt>=k){
			For(i,plus[0])plus[i]=lc[plus[i]];
			For(i,minus[0])minus[i]=lc[minus[i]];
			r=mid;
		}else{
			For(i,plus[0])plus[i]=rc[plus[i]];
			For(i,minus[0])minus[i]=rc[minus[i]];
			k-=cnt;
			l=mid+1;
		}
	}
	return b[l];
}
void modify(int x,int y){
	for(int p=x; p<=n; p+=lowbit(p))
		update(bit_root[p],1,m,a[x],-1);
	a[x]=y;
	for(int p=x; p<=n; p+=lowbit(p))
		update(bit_root[p],1,m,a[x],1);
}

struct OPT{
	int x,y,k,type;
}opt[N];

int q;
char str[10];
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&q);
	For(i,n){
		scanf("%d",&a[i]);
		b[++m]=a[i];
	}
	For(i,q){
		scanf("%s",&str);
		opt[i].type=str[0]=='C';
		if(opt[i].type==0)
			scanf("%d%d%d",&opt[i].x,&opt[i].y,&opt[i].k);
		else{
			scanf("%d%d",&opt[i].x,&opt[i].y);
			b[++m]=opt[i].y;
		}
	}
	sort(b+1,b+m+1);
	m=unique(b+1,b+m+1)-b-1;
	For(i,n){
		a[i]=lower_bound(b+1,b+m+1,a[i])-b;
		add(root[i],root[i-1],1,m,a[i]);
	}
		
	For(i,q){
		if(!opt[i].type){
			printf("%d\n",query(opt[i].x,opt[i].y,opt[i].k));
		}else{
			opt[i].y=lower_bound(b+1,b+m+1,opt[i].y)-b;
			modify(opt[i].x,opt[i].y);
		}
	}
	return 0;
}

