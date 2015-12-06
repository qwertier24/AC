#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define UPPER 1E9
using namespace std;
int n,m,cost[100001];
bool check(int expense)
{
	int p=0;
	for(int i=1; i<=m; i++)
	{
		int sum=0;
		while(p<n&&sum+cost[p+1]<=expense)
			p++,sum+=cost[p];
	}
	if(p<n)
		return false;
	else
		return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",&cost[i]);
	int l=1,r=UPPER;
	while(l<r)
	{
		int m=(l+r)/2;
		if(check(m))
			r=m;
		else
			l=m+1;
	}
	printf("%d\n",l);
	return 0;
}
