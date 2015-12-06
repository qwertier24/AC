#include <stdio.h>
int n,num;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		bool all_one=true;
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&num);
			if(num!=1)
				all_one=false;
		}
		if(all_one)
		{
			if(n%2)
				printf("poopi\n");
			else
				printf("piloop\n");
		}
		else
		{
			printf("poopi\n");
		}
	}
	return 0;
}
