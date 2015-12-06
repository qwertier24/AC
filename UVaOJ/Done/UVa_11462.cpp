#include <stdio.h>
#include <string.h>
int age[101],t,n;
int main()
{
	while(scanf("%d",&n)&&n)
	{
		bool first=true;
		memset(age,0,sizeof(age));
		for(int i=1; i<=n; i++)
			scanf("%d",&t),age[t]++;
		for(int i=0; i<=100; i++)
			for(int j=1; j<=age[i]; j++)
			{
				if(first)
				{
					first=false;
					printf("%d",i);
				}
				else
					printf(" %d",i);
			}
		printf("\n");
	}
	return 0;
}
