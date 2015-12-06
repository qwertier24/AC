#include <stdio.h>
#include <string.h>
#define maxn
int a[100000];
Init()
{
	for(int i=2; i<=10000; i++)
		if(prime[i])
			for(int j=1; j<=
int main()
{
	long long ans;
	int n;
	while(scanf("%d",&n)&&n)
	{
		memet(a,0,sizeof(a));
		printf("%d ",n);
		int sq=floor(sqrt(n));
		for(int i=2; i<=sq; i++)
			while(n%i==0)
			{
				a[i]++;
				n/=i;
			}
		for(int i=sq; i>=2; i--)
			if(a[i])
			{
				total-=a[i];
				for(int j=0; j<a[i]; j--)
					ans+=a<<(total+j);
			}
	}
	return 0;
}
