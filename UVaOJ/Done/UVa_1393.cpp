#include <stdio.h>
int gcd[310][310];
int GCD(int a,int b)
{
	while(b)
	{
		int t=a;
		a=b;
		b=t%b;
	}
	return a;
}
int main()
{
	int m,n,ans=0;
	for(int i=1; i<=300; i++)
		for(int j=1; j<=300; j++)
			gcd[i][j]=GCD(i,j);
	while(scanf("%d%d",&m,&n)&&m)
	{
		ans=0;
		for(int i=1; i<=m-1; i++)
			for(int j=1; j<=n-1; j++)
				if(gcd[i][j]==1)
					ans+=(m-i)*(n-j)-((2*i<m&&2*j<n)?(m-2*i)*(n-2*j):0);
		printf("%d\n",ans*2);
	}
	return 0;
}
