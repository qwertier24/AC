#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
using namespace std;
long long SG(long long a)
{
	return (a%2==0)?(a/2l):(SG(a/2l));
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		long long ans=0;
		scanf("%d",&n);
		while(n--)
		{
			long long t;
			cin>>t;
			ans^=SG(t);
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
