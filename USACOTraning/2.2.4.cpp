/*
ID: mayukun3
PROG: subset
LANG: C++
*/
#include <stdio.h>
int main()
{
	long long n,d[1000]={0};
	d[0]=1;
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	scanf("%lld",&n);
	if(n%4 && (n+1)%4)
		printf("0\n");
	else
	{
		int avr=n*(n+1)/4;
		for(int i=1; i<=n; i++)
			for(int j=avr; j>=i; j--)
			{
				d[j]+=d[j-i];
			}
		printf("%lld\n",d[avr]/2);
	}
}