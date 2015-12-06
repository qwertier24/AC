#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#define PROB
#define N 50010
#define lowbit(x) (x&(-x))
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
using namespace std;

int va[N],vb[N],ma,mb;

#define SIZE 12000000
int lc[SIZE],rc[SIZE],maxv[SIZE],sz;
double sumv[SIZE];
#define mid ((l+r)>>1)

int debug;
void update(int &o,int l,int r,int p,int v,double add){
	if(!o)o=++sz,lc[o]=rc[o]=0,maxv[o]=sumv[o]=0;
	if(l==r){
		if(maxv[o]<v){
			maxv[o]=v;
			sumv[o]=add;
		}else if(maxv[o]==v)
			sumv[o]+=add;
		return;
	}
	if(p<=mid)update(lc[o],l,mid,p,v,add);
	if(p>mid)update(rc[o],mid+1,r,p,v,add);
	if(maxv[lc[o]]>maxv[rc[o]]){
		maxv[o]=maxv[lc[o]];
		sumv[o]=sumv[lc[o]];
	}else if(maxv[lc[o]]==maxv[rc[o]]){
		maxv[o]=maxv[lc[o]];
		sumv[o]=sumv[lc[o]]+sumv[rc[o]];
	}else{
		maxv[o]=maxv[rc[o]];
		sumv[o]=maxv[rc[o]];
	}
	//printf("%d %d %d %d\n",o,l,r,maxv[o]);
}
int query(int o,int l,int r,int L,int R){
	if(!o)return 0;
	//if(debug)printf("%d %d %d %d\n",o,l,r,maxv[o]);
	if(L<=l && r<=R)return maxv[o];
	if(R<=mid)return query(lc[o],l,mid,L,R);
	if(L>mid)return query(rc[o],mid+1,r,L,R);
	return max(query(lc[o],l,mid,L,R),query(rc[o],mid+1,r,L,R));
}
double getSum(int o,int l,int r,int L,int R,int v){
	if(!o)return 0;
	if(maxv[o]<v)return 0;
	if(L<=l && r<=R)return sumv[o];
	if(R<=mid)return getSum(lc[o],l,mid,L,R,v);
	if(mid<L)return getSum(rc[o],mid+1,r,L,R,v);
	return getSum(lc[o],l,mid,L,R,v)+getSum(rc[o],mid+1,r,L,R,v);
}
int root[N];

int n,a[N],b[N],f[N],f2[N];
vector<int> v[N];
double g1[N],g2[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	scanf("%d",&n);
	For(i,n){
		scanf("%d%d",&a[i],&b[i]);
		va[++ma]=a[i];
		vb[++mb]=b[i];
	}
	sort(va+1,va+ma+1);
	sort(vb+1,vb+mb+1);
	ma=unique(va+1,va+ma+1)-va-1;
	mb=unique(vb+1,vb+mb+1)-vb-1;
	For(i,n)a[i]=lower_bound(va+1,va+ma+1,a[i])-va;
	For(i,n)b[i]=lower_bound(vb+1,vb+mb+1,b[i])-vb;
	
	int ans=0;
	For(i,n){
		for(int p=a[i]; p<=ma; p+=lowbit(p))
			f[i]=max(f[i],query(root[p],1,mb,b[i],mb)+1);
			
		if(f[i]==1)
			g1[i]=1;
		else{
			for(int p=a[i]; p<=ma; p+=lowbit(p))
				g1[i]+=getSum(root[p],1,mb,b[i],mb,f[i]-1);
		}
		//printf("%d %f\n",i,g1[i]);
		
		ans=max(ans,f[i]);
		for(int p=a[i]; p; p-=lowbit(p))
			update(root[p],1,mb,b[i],f[i],g1[i]);
	}
	printf("%d\n",ans);

	memset(root,0,sizeof(root));
	for(int i=n; i; i--){
		for(int p=a[i]; p; p-=lowbit(p)){
			//printf("query:%d\n",root[p]);
			f2[i]=max(f2[i],query(root[p],1,mb,1,b[i])+1);
		}
		
		if(f2[i]==1)
			g2[i]=1;
		else{
			for(int p=a[i]; p; p-=lowbit(p))
				g2[i]+=getSum(root[p],1,mb,1,b[i],f2[i]-1);
		}
		//printf("%d %d %f\n",i,f2[i],g2[i]);
		
		for(int p=a[i]; p<=ma; p+=lowbit(p))
			update(root[p],1,mb,b[i],f2[i],g2[i]);
	}
	
	double sum=0;
	For(i,n)if(f[i]==ans)sum+=g1[i];
	For(i,n)printf("%.5f%s",f[i]+f2[i]==ans+1?g1[i]*g2[i]/sum:0.0,i==n?"":" ");
	return 0;
}

