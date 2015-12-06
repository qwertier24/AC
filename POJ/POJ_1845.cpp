#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
#define MOD 9901
#define MAXN 7100
using namespace std;
int is_prime[MAXN+10],fnum=0;
vector<int> primes;
struct FACT
{
	int f,p;
}fact[MAXN+10];
void get_primes()
{
	memset(is_prime,-1,sizeof(is_prime));
	for(int i=2; i*i<=MAXN; i++)
		if(is_prime[i])
			for(int j=i*i; j<=MAXN; j+=i)
				is_prime[j]=0;
	for(int i=2; i<=MAXN; i++)
		if(is_prime[i])
			primes.push_back(i);
}
int fast_pow(int n,long long p)
{
	int t=n%MOD,ret=1;
	while(p!=0)
	{
		if(p&1)
			ret=(ret*t)%MOD;
		t=(t*t)%MOD;
		p=p>>1;
	}
	return ret;
}
void ext_eu(int a,int b,int& x,int& y)
{
	if(a==1){x=1,y=0;}
	else
	{
		ext_eu(b%a,a,y,x);
		x-=(b/a)*y;
	}
}
int main()
{
	int n,p,ans=1;
	get_primes();
	cin>>n>>p;
	for(int i=0; primes[i]*primes[i]<n; i++)
		if(n%primes[i]==0)
		{
			fact[++fnum].f=primes[i];
			fact[fnum].p=0;
			while(n%primes[i]==0)
				fact[fnum].p++,n/=primes[i];
		}
	if(n!=1)
		fact[++fnum].f=n,fact[fnum].p=1;
	for(int i=1; i<=fnum; i++)
	{
		if(fact[i].f%MOD!=0)
		{
			if(fact[i].f%MOD==1)
				ans=(ans*((1l+(long long)p*fact[i].p)%MOD))%MOD;
			else
			{
				int inv,y;
				ext_eu(fact[i].f-1,MOD,inv,y);
				ans=(((ans*(fast_pow(fact[i].f,fact[i].p*(long long)p+1l)-1))%MOD)*inv)%MOD;
			}
		}
	}
	printf("%d\n",((ans%MOD)+MOD)%MOD);
	return 0;
}
