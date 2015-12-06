#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
long long C[1000001],coin[1000001];
long long ABS(long long a)
{
	if(a>0ll)
	{
		return a;
	}
	else 
	{
		return (0ll-a);
	}
}
int main()
{
	using namespace std;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		long long M,sum=0,ans=0;
		for (int i=1; i<=n; i++)
		{
			scanf("%lld",&coin[i]);
			sum+=coin[i];
		}
		M=sum/n;
		C[0]=0;
		for (int i=1; i<=n-1; i++)
		{
			C[i]=C[i-1]+coin[i]-M;
		}
		sort(C+1,C+n);
		M=C[n/2];
		ans=ABS(C[n/2]);
		for (int i=1; i<=n-1; i++)
		{
			ans+=ABS(C[i]-M);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
