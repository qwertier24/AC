#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int sum[200001],remain[200001];
int main()
{
	int n,mt,ct,ans,sum,last;
	while(scanf("%d",&n)!=EOF)
	{
		ans=0;
		sum=0;
		last=1;
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d",&mt,&ct);
			remain[i]=remain[i+n]=mt-ct;
		}
		for(int i=1; i<=n+n; i++)
		{
			sum+=remain[i];
			if(sum>=0)
				ans=max(ans,i-last+1);
			else
				sum=0,last=i+1;
			if(ans==n)
				break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
