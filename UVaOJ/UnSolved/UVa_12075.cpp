#include <stdio.h>

int main()
{
	long long ans;
	int m,n,kase=1;
	while(scanf("%d%d",&m,&n)&&m)
	{
		ans=0;
		for(int x=0; x<=m; x++)
			for(int y=0; y<n; y++)
			{
				ans+=m*(n-y) * (m*(n-y)-1)/2 + m*(n-y)*(n-y) + (m-x)*m*(n-y) + (m-x)*(n-y);
				//printf("%d %d: %d\n",x,y,m*(n-y) * (m*(n-y)-1)/2 + m*(n-y)*(n-y) + (m-x)*m*(n-y));
			}
		printf("Case %d: %I64d\n",kase++,ans);
	}
	return 0;
}
