#include<stdio.h>
#include<string.h>
#include<algorithm>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
using std::lower_bound;

typedef long long LL;
#define N 100010

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
int sumv[N<<2];
int query(int o,int l,int r,int k){
	sumv[o]--;
	if(l==r)return l;
	if(sumv[lc]>=k)return query(lc,l,mid,k);
	else return query(rc,mid+1,r,k-sumv[lc]);
}
void build(int o,int l,int r){
	sumv[o]=r-l+1;
	if(l==r)return;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
int g[N],f[N],n,a[N],p[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&n);
	build(1,1,n);
	REP(i,1,n){
		scanf("%d",&p[i]);
	}
	RREP(i,n,1){
		p[i]=query(1,1,n,p[i]+1);
		a[p[i]]=i;
	}
	REP(i,1,n)g[i]=n+1;
	REP(i,1,n){
		int k=lower_bound(g+1,g+n+1,a[i])-g;
		f[i]=k;
		g[k]=a[i];
	}
	int ans=0;
	REP(i,1,n){
		if(ans<f[p[i]])ans=f[p[i]];
		printf("%d\n",ans);
	}
	return 0;
}

