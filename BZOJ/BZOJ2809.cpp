#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define N 100010

typedef long long LL;
using namespace std;

int lc[N],rc[N],dist[N],val[N];
int merge(int a,int b){
	if(!a)return b;
	if(!b)return a;
	if(val[a]<val[b])swap(a,b);
	rc[a]=merge(rc[a],b);
	if(dist[rc[a]]>dist[lc[a]])swap(lc[a],rc[a]);
	dist[a]=dist[rc[a]]+1;
	return a;
}

int lead[N],fee[N],fa[N],root[N],cnt[N],n,m;
LL sum[N],ans;
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d%d%d",&fa[i],&fee[i],&lead[i]);
		root[i]=i;
		sum[i]=val[i]=fee[i];
		cnt[i]=1;
	}
	for(int i=n; i; i--){
		while(sum[i]>m){
			sum[i]-=val[root[i]];
			cnt[i]--;
			root[i]=merge(lc[root[i]],rc[root[i]]);
		}
		ans=max(ans,cnt[i]*(LL)lead[i]);
		if(fa[i]){
			root[fa[i]]=merge(root[fa[i]],root[i]);
			cnt[fa[i]]+=cnt[i];
			sum[fa[i]]+=sum[i];
		}
	}
	printf("%lld\n",ans);
	return 0;
}

