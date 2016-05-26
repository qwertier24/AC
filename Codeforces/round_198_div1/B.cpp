#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define INF 1<<30
using namespace std;
int num[100010],g[100010],d[100010];
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
