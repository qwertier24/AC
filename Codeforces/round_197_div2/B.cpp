#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
int n,m;
long long dist(int a,int b)
{
	if(a>=b)
		return a-b;
	else
		return n-(b-a);
}
int a[100001];
int main()
{
	long long ans=0;
	scanf("%d%d",&n,&m);
	a[0]=1;
	for(int i=1; i<=m; i++)
	{
		scanf("%d",&a[i]);
		ans+=dist(a[i],a[i-1]);
	}
	cout<<ans;
	return 0;
}
