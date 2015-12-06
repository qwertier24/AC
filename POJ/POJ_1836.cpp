#include <stdio.h>
#include <algorithm>
#define INF 1000000
using namespace std;
int d1[1001],d2[1001],max_d1[1001]={0},max_d2[1001]={0};
double height[1001],g[1001];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%lf",&height[i]);
	for(int i=1; i<=n; i++)
		g[i]=INF;
	for(int i=1; i<=n; i++)
	{
		int k=lower_bound(g+1,g+n+1,height[i])-g;
		g[k]=height[i];
		d1[i]=k;
		max_d1[i]=max(max_d1[i-1],d1[i]);
	}
	for(int i=1; i<=n; i++)
		g[i]=INF;
	for(int i=n; i>=1; i--)
	{
		int k=lower_bound(g+1,g+n+1,height[i])-g;
		g[k]=height[i];
		d2[i]=k;
		max_d2[i]=max(max_d2[i-1],d2[i]);
	}
	for(int i=1; i<=n; i++)
		ans=max(ans,max(d1[i]+d2[i]-1,max_d1[i]+max_d2[i+1]));
	printf("%d",n-ans);
	return 0;
}
