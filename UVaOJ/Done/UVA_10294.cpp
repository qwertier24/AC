#include <stdio.h>
long long pow[51];
int gcd(int a,int b)
{
	int t;
	while(b!=0)
	{
		t=b;
		b=a%b;
		a=t;
	}
	return a;
}
int main()
{
	int n,k;
	//printf("%d\n",gcd(29,7));
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		long long a=0,b=0;
		pow[0]=1;
		for(int i=1; i<=n; i++)
		{
			pow[i]=pow[i-1]*k;
		}
		for(int i=0; i<n; i++)
		{
			a+=pow[gcd(n,i)];
			//printf("%d\n",a);
		}
		if(n%2)
			b=pow[(n+1)/2]*n;
		else
			b=n/2*(pow[n/2+1]+pow[n/2]);
		//printf("%d %lld\n",a,b);
		printf("%lld %lld\n",a/n,(a+b)/2/n);
	}
	return 0;
}
