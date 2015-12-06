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
long long dist[100010];
long long gcd(long long a,long long b)
{
	while(a)
	{
		long long t=a;
		a=b%a;
		b=t;
	}
	return b;
}
int main()
{
	int n;
	scanf("%d",&n);
	long long sum_dist=0;
	long long ans=0;
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&dist[i]);
		sum_dist+=dist[i];
	}
	sort(dist+1,dist+n+1);
	long long last=0;
	for(int i=1; i<=n; i++)
	{
		sum_dist-=dist[i];
		ans+=dist[i]*i-last+sum_dist-dist[i]*(n-i);
		last+=dist[i];
	}
	long long g=gcd(ans,n);
	cout<<ans/g<<" "<<n/g;
	return 0;
}
