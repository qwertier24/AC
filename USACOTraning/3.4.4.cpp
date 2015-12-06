/*
ID: mayukun3
PROG: fence9
LANG: C++
*/
#include <stdio.h>
int gcd(int a,int b)
{
	while(a)
	{
		int t=a;
		a=b%a;
		b=t;
	}
	return b;
}
int cnt(int n,int m)
{
	if(n==0||m==0)return 0;
	return ((n-1)*(m-1)-gcd(n,m)+1)/2;
}
int main()
{
	int n,m,p;
	freopen("fence9.in","r",stdin);freopen("fence9.out","w",stdout);
	scanf("%d %d %d",&n,&m,&p);
	if(p*n>=0)
	{
		if(p>=n)
			printf("%d\n",cnt(n,m)+cnt(p-n,m)+((n!=0&&n!=p)?(m-1):0));
		else
			printf("%d\n",cnt(n,m)-cnt(n-p,m)-gcd(n-p,m)+1);
	}
	return 0;
}