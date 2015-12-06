#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB
using namespace std;

const int maxa=1000;
#define SIZE 10000000
#define mid ((l+r)>>1)
int sz,sumv[SIZE],cntv[SIZE],lc[SIZE],rc[SIZE],root[500010];
void add(int &o,int p,int l,int r,int v){
	if(!o)o=++sz,sumv[o]=sumv[p],cntv[o]=cntv[p];
	sumv[o]+=v;
	cntv[o]++;
	if(l==r)return;
	if(v<=mid){
		rc[o]=rc[p];
		add(lc[o],lc[p],l,mid,v);
	}else{
		lc[o]=lc[p];
		add(rc[o],rc[p],mid+1,r,v);
	}
}
int query(int o,int p,int l,int r,int v){
	if(v==0)return 0;
	if(l==r)return (v-1)/l+1;
	if(sumv[o]-sumv[p]==v)return cntv[o]-cntv[p];
	int s=sumv[rc[o]]-sumv[rc[p]];
	if(s>=v)return query(rc[o],rc[p],mid+1,r,v);
	return query(lc[o],lc[p],l,mid,v-s)+cntv[rc[o]]-cntv[rc[p]];
}

int n,m,q,a[500010],b[210][210],sum[210][210][1010],cnt[210][210][1010];
#define getsum(a,x1,y1,x2,y2,k) (a[x2][y2][k]-a[x2][y1-1][k]-a[x1-1][y2][k]+a[x1-1][y1-1][k])
int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	if(n==1){
		for(int i=1; i<=m; i++){
			scanf("%d",&a[i]);
			add(root[i],root[i-1],1,maxa,a[i]);
		}
		while(q--){
			int t,l,r,h;
			scanf("%d%d%d%d%d",&t,&l,&t,&r,&h);
			if(sumv[root[r]]-sumv[root[l-1]]<h){
				puts("Poor QLW");
				continue;
			}
			printf("%d\n",query(root[r],root[l-1],1,maxa,h));
		}
	}else{
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++){
				scanf("%d",&b[i][j]);
				for(int k=maxa; k; k--){
					sum[i][j][k]=sum[i][j-1][k]+sum[i-1][j][k]-sum[i-1][j-1][k]+(b[i][j]==k?b[i][j]:0);
					cnt[i][j][k]=cnt[i][j-1][k]+cnt[i-1][j][k]-cnt[i-1][j-1][k]+(b[i][j]==k);
				}
			}
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				for(int k=maxa; k; k--)
					sum[i][j][k]+=sum[i][j][k+1],cnt[i][j][k]+=cnt[i][j][k+1];
		while(q--){
			int x1,y1,x2,y2,h;
			scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&h);
			if(getsum(sum,x1,y1,x2,y2,1)<h){
				puts("Poor QLW");
				continue;
			}
			int hi=maxa,lo=1;
			while(lo<hi){
				int mi=(lo+hi-1)/2+1;
				if(getsum(sum,x1,y1,x2,y2,mi)>=h)lo=mi;
				else hi=mi-1;
			}
			printf("%d\n",getsum(cnt,x1,y1,x2,y2,lo+1)+(h-getsum(sum,x1,y1,x2,y2,lo+1)-1)/lo+1);
		}
	}
	return 0;
}

