#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define MOD 1000000007ll
using namespace std;
char s[100010];
long long fast_pow(long long a,long long p)
{
	long long t=a,ret=1;
	while(p)
	{
		if(p&1ll)
			ret=(ret*t)%MOD;
		t=(t*t)%MOD;
		p=p>>1;
	}
	return ret;
}
void ext_gcd(long long a,long long b,long long& x,long long& y)
{
	if(a==1){x=1,y=0;}
	else
	{
		ext_gcd(b%a,a,y,x);
		x-=b/a*y;
	}
}
int rev(long long a,long long b)
{
	long long x,y;
	ext_gcd(a,b,x,y);
	return x;
}
int main()
{
	int k;
	scanf("%s%d",s,&k);
	int len=strlen(s);
	long long ans=0;
	int pow2len=fast_pow(2,len)%MOD,t=((fast_pow(pow2len,k)-1)*rev(pow2len-1,MOD))%MOD;
	//printf("%d\n",pow2len);
	//printf("%d %d\n",rev(pow2len,MOD),(pow2len*rev(pow2len,MOD)%MOD+MOD)%MOD);
	for(int i=len-1; i>=0; i--)
		if((s[i]-'0')%5==0)
		{
			if(pow2len%MOD==1)
				ans=(ans+fast_pow(2,i))%MOD;
			else
				ans=(ans+fast_pow(2,i)*t)%MOD;
		}
	printf("%I64d\n",(ans+MOD)%MOD);
	return 0;
}
