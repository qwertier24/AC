#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int ans=0;
		for(int i=1; i<=n; i++)
		{
			int t;
			scanf("%d",&t);
			ans^=t;
		}
		if(ans)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
