#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;
long long ext_eu(long long a,long long b,long long& x,long long& y)
{
	//cout<<a<<" "<<b<<endl;
	if(a==0){x=0;y=1;return b;}
	else
	{
		long long d=ext_eu(b%a,a,y,x);
		x-=(b/a)*y;
		return d;
	}
}
int main()
{
	long long s,e,step,k;
	while(cin>>s>>e>>step>>k&&(s||e||step||k))
	{
		long long x,y;
		if(s==e){printf("0\n");continue;}
		long long b=e-s,gcd=ext_eu(step,1LL<<k,x,y);
		if(b<0)
			b+=(1ll)<<k;
		if(b%gcd)
			printf("FOREVER\n");
		else
		{
			long long mod=(1ll<<k)/gcd;
			//cout<<"B:"<<b<<"  "<<mod<<endl;
			x=(x*(b/gcd))%mod;
			x=(x+mod)%mod;
			cout<<x<<endl;
		}
	}
	return 0;
}
