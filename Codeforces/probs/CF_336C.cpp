#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int num[1000001];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&num[i]);
	for(int i=29; i>=0; i--)
	{
		int flag=(1<<i)-1,cnt=0;
		for(int j=1; j<=n; j++)
			if((num[j]>>i)&1)
				flag&=num[j],cnt++;
		if(flag==0)
		{
			printf("%d\n",cnt);
			for(int j=1; j<=n; j++)
			{
				if((num[j]>>i)&1)
					printf("%d ",num[j]);
			}
			return 0;
		}
				
	}
	return 0;
}
