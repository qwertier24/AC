#include <stdio.h>
#include <algorithm>
#define INF 1<<30
using namespace std;
int g[1001],d[1001],num[1001];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&num[i]);
	for(int i=1; i<=n; i++)
		g[i]=INF;
	for(int i=1; i<=n; i++)
	{
		int k=lower_bound(g+1,g+n+1,num[i])-g;
		d[i]=k;
		g[k]=num[i];
		ans=max(ans,d[i]);
	}
	printf("%d",ans);
	return 0;
}
