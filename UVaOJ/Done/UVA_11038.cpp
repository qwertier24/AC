#include <stdio.h>
#include <iostream>
using namespace std;
long long solve(long long l,long long r)
{
	l--;
	long long loop=1,sum_l=0,sum_r=0;
	while(loop*10 <=l)
	{
		sum_l+=(l/(loop*10)-1)*loop;
		if((l/loop)%10)
			sum_l+=loop;
		else
			sum_l+=l%loop+1;
		loop*=10;
	}
	loop=1;
	while(loop*10 <=r)
	{
		sum_r+=(r/(loop*10)-1)*loop;
		if((r/loop)%10)
			sum_r+=loop;
		else
			sum_r+=r%loop+1;
		loop*=10;
		//cout<<loop<<"  "<<sum_r;
	}
	return sum_r-sum_l+(l==-1?1:0);
}
int main()
{
	long long n,m;
	while(cin>>m>>n&&m!=-1)
	{
		cout<<solve(m,n);
	}
	return 0;
}
