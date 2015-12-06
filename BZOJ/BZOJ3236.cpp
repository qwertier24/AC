#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100010
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define lowbit(x) (x&(-x))
using namespace std;

void readint(int &x){
	x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
}

int n,m,a[N],b[N],root[N],bit_root[N];

#define SZ 20000000
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

int plus[N],minus[N];
int query(int p){
	if(p<=0)return 0;
	int l=1,r=m,ret=0;
	while(true){
		if(r<=p){
			For(i,plus[0])ret+=sumv[plus[i]];
			For(i,minus[0])ret-=sumv[minus[i]];
			break;
		}
		if(p<=mid){
			r=mid;
			For(i,plus[0])plus[i]=lc[plus[i]];
			For(i,minus[0])minus[i]=lc[minus[i]];
		}else{
			l=mid+1;
			For(i,plus[0])ret+=sumv[lc[plus[i]]],plus[i]=rc[plus[i]];
			For(i,minus[0])ret-=sumv[lc[minus[i]]],minus[i]=rc[minus[i]];
		}
	}
	return ret;
}

struct Query{
	int l,r,a,b,idx;
	bool operator<(const Query& rhs)const{
		return l<rhs.l;
	}
}Q[N*10];
int ans1[N*10],ans2[N*10],q;
int nxt[N],pos[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	readint(n);readint(q);
	For(i,n){
		readint(a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	For(i,n){
		a[i]=lower_bound(b+1,b+m+1,a[i])-b;
		add(root[i],root[i-1],1,m,a[i]);
	}
	for(int i=n; i; i--){
		nxt[i]=pos[a[i]];
		pos[a[i]]=i;
	}
	For(i,m)
		for(int p=pos[i]; p<=n; p+=lowbit(p))
			update(bit_root[p],1,m,i,1);
	
	For(i,q){
		readint(Q[i].l);readint(Q[i].r);readint(Q[i].a);readint(Q[i].b);
		Q[i].a=lower_bound(b+1,b+m+1,Q[i].a)-b;
		Q[i].b=upper_bound(b+1,b+m+1,Q[i].b)-b-1;
		Q[i].idx=i;
	}
	sort(Q+1,Q+q+1);
	int cur=1;
	For(i,q){
		while(cur<Q[i].l){
			for(int p=cur; p<=n; p+=lowbit(p))
				update(bit_root[p],1,m,a[cur],-1);
			if(!nxt[cur]){++cur;continue;}
			for(int p=nxt[cur]; p<=n; p+=lowbit(p))
				update(bit_root[p],1,m,a[cur],1);
			cur++;
		}
		if(Q[i].a<=Q[i].b){
			plus[plus[0]=1]=root[Q[i].r];
			minus[minus[0]=1]=root[Q[i].l-1];
			ans1[Q[i].idx]=query(Q[i].b);
			plus[plus[0]=1]=root[Q[i].r];
			minus[minus[0]=1]=root[Q[i].l-1];
			ans1[Q[i].idx]-=query(Q[i].a-1);
			
			plus[0]=minus[0]=0;
			for(int p=Q[i].r; p; p-=lowbit(p))
				plus[++plus[0]]=bit_root[p];
			ans2[Q[i].idx]=query(Q[i].b);
			plus[0]=minus[0]=0;
			for(int p=Q[i].r; p; p-=lowbit(p))
				plus[++plus[0]]=bit_root[p];
			ans2[Q[i].idx]-=query(Q[i].a-1);
		}
		
	}
	For(i,q)printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}

