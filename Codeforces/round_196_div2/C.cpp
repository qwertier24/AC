#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
#define MOD 1000000009l
using namespace std;
long long q_pow2(int pn)
{
	long long ret=1,t=2;
	while(pn)
	{
		if(pn%2)
			ret=(ret*t)%MOD;
		pn/=2;
		t=(t*t)%MOD;
	}
	return ret;
}
long long solve(long long m,long long k)
{
	//printf("%I64d",(m/k+1l));
	return ((k*(q_pow2((int)(m/k+1l))-2))%MOD+m%k)%MOD;
}
int main()
{
	long long n,m,k;
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	long long block_num=n-m+1;
	if(m<=(k-1)*block_num)
		printf("%I64d",m%MOD);
	else
	{
		//cout<<(m-(k-1)*(block_num-1));
		printf("%I64d",((solve(m-(k-1)*(block_num-1),k)+(k-1)*(block_num-1))%MOD+MOD)%MOD);
	}
	return 0;
}
