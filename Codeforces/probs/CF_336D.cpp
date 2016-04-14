#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define MOD 1000000007
using namespace std;
//d[minus+j][j]=c[minus+j-1][j]+d[minus+j-2][j-2];
long long fact[200010];
long long fast_pow(long long a,int p)
{
	long long t=a,ret=1;
	while(p)
	{
		if(p&1)
			ret=(ret*t)%MOD;
		t=(t*t)%MOD;
		p>>=1;
	}
	return ret;
}
long long rev(long long a,int b)
{
	return fast_pow(a,b-2);
}
long long C(int a,int b)
{
	return (fact[b]*rev((fact[b-a]*fact[a])%MOD,MOD))%MOD;
}
int solve(int n,int m)
{
	long long f=0;
	if(m==0)
		return n%2;
	if(n==0)
		return m>1;
	if(n==1&&m==1)
		return 2;
	if(m==1)
	{
		if(n%2)
		{
			return(n+1)/2+1;
		}
		else
		{
			return n/2;
		}
	}
	for(int i=n+m; i>=m; i-=2)
	{
		f=(f+C(m-1,i-1))%MOD;
		//printf("  %I64d %d\n",f,i);
	}
	return (int)f;
}
int main()
{
	fact[0]=1;
	for(long long i=1; i<=200000; i++)
		fact[i]=(fact[i-1]*i)%MOD;
	int n,m,g;
	scanf("%d%d%d",&n,&m,&g);
	if(g==0)
		printf("%d\n",(solve(n,m)%MOD+MOD)%MOD);
	else
	{
		if(n==0)
		{
			if(m==1)
				printf("1\n");
			else
				printf("0\n");
		}
		else
			printf("%d\n",(solve(n-1,m)%MOD+MOD)%MOD);
	}
	return 0;
}
