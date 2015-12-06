#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int d[200010][60]={0},color[200010],cost[200010],k,p,n;
int main()
{
	int max_pos=0;
	long long ans=0;
	scanf("%d%d%d",&n,&k,&p);
	for(int i=1; i<=n; i++)
		scanf("%d%d",&color[i],&cost[i]);
	for(int i=1; i<=n; i++)
	{
		if(cost[i]<=p)
			max_pos=i;
		for(int j=0; j<k; j++)
			d[i][j]=d[i-1][j];
		d[i][color[i]]++;
		ans+=d[max_pos][color[i]];
		if(max_pos==i)
			ans--;
	//	printf("%d %d\n",max_pos,d[max_pos][color[i]]);
	}
	cout<<ans;
	return 0;
}
