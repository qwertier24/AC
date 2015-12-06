#include<stdio.h>
#include<algorithm>
#define N 500010

using namespace std;

int n,m,q,a[N],b[N],root[N];

int lc[10000010],rc[10000010],sz,sumv[10000010];
#define mid ((l+r)>>1)
void add(int& o,int p,int l,int r,int x){
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

int query(int p,int q,int v){
	int l=1,r=m;
	while(l<r){
		int s1=sumv[lc[q]]-sumv[lc[p]],s2=sumv[rc[q]]-sumv[rc[p]];
		if(s1>v){
			r=mid;
			p=lc[p],q=lc[q];
		}else if(s2>v){
			l=mid+1;
			p=rc[p],q=rc[q];
		}else{
			return 0;
		}
	}
	return b[l];
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	for(int i=1; i<=n; i++){
		a[i]=lower_bound(b+1,b+m+1,a[i])-b;
		add(root[i],root[i-1],1,m,a[i]);
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(root[l-1],root[r],(r-l+1)/2));
	}
	return 0;
}
