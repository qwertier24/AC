#include <stdio.h>
long long abs(long long a)
{
	return a>0?a:-a;
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		int req;
		long long cost=0,wine_num,ans=0;
		scanf("%lld",&wine_num);
		for(int i=1; i<n; i++)
		{
			cost+=abs(wine_num);
			scanf("%d",&req);
			if((wine_num+req)*wine_num<=0)
			{
				ans+=cost;
				wine_num+=req;
				cost=0;
			}
			else
				wine_num+=req;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
