#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define INF (1<<30)
#define PROB "chorus"
using namespace std;
int h[110],n,g[110],d1[110],d2[110];
void rev(){
	for(int i=1; i<=n/2; i++)
		swap(h[i],h[n-i+1]);
}
void dp(int *d,int *a){
	for(int i=1; i<=n; i++)
		g[i]=INF;
	for(int i=1; i<=n; i++){
		int k=lower_bound(g+1,g+n+1,a[i])-g;
		d[i]=k;
		g[k]=a[i];
		//printf("%d %d %d\n",i,h[i],d[i]);
	}
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&h[i]);
	dp(d1,h);
	rev();
	dp(d2,h);
	int ans=0;
	for(int i=1; i<=n; i++)
		ans=max(ans,d1[i]+d2[n-i+1]-1);
	printf("%d",n-ans);
	return 0;
}

