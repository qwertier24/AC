#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	int n,m,v,u;
	scanf("%d%d%d",&n,&m,&v);
	if(m>1+((long long)n-1)*((long long)n-2)/2)
		printf("-1");
	else if(m<n-1)
		printf("-1");
	else
	{
		if(v!=1)
		{
			printf("1 %d\n",v);
			u=1;
			m--;
		}
		else
		{
			printf("2 %d\n",v);
			u=2;
			m--;
		}
		for(int i=1; i<=n; i++)
			if(i!=v&&i!=u)
			{
				printf("%d %d\n",v,i);
				m--;
			}
			for(int i=2; i<=n&&m; i++)
				if(i!=v&&i!=u)
					for(int j=i+1; j<=n&&m; j++)
						if(j!=v&&i!=u)
						{
							printf("%d %d\n",i,j);
							m--;
						}
	}
	return 0;
}
