#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int p[200010],n,p0;
int dist(int i)
{
	return abs(p0-p[i]);
}
bool check(int max_d)
{
	if(p0-p[1]<=max_d)
	{
		if(dist(p[n])/2.0<=max_d)
			return true;
		else
			return false;
	}
	else if(p[n]-p0<=max_d)
	{
		if(dist(p[0])/2.0<=max_d)
			return true;
		else
			return false;
	}
	else
		return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",&p[i]);
		p0=p[1];
		sort(p+1,p+n+1);
		int l=1,r=(int)2e9,m;
		while(l<r)
		{
			m=(l+r)>>1;
			if(check(m))
				r=m;
			else
				l=m+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
