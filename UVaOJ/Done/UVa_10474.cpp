#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#define INF 1<<30
using namespace std;
int num[2000010];
int main()
{
	int n,q,kase=1;
	while(scanf("%d%d",&n,&q)&&n)
	{
		printf("CASE# %d:\n",kase++);
		for(int i=1; i<=n; i++)
			scanf("%d",&num[i]);
		num[n+1]=INF;
		sort(num+1,num+n+1);
		for(int i=1; i<=q; i++)
		{
			int query;
			scanf("%d",&query);
			int k=lower_bound(num+1,num+n+1,query)-num;
			if(num[k]!=query)
				printf("%d not found\n",query);
			else
				printf("%d found at %d\n",query,k);
		}
	}
	return 0;
}
