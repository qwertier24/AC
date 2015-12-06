#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int L,n,m,pos[50001];
bool check(int min_l)
{
	int cost=0;
	int l=0;
	for(int i=1; i<=n; i++)
	{
		if(pos[i]-l<min_l)
			cost++;
		else
			l=pos[i];
		//printf("%d %d %d\n",l,i,pos[i]);
	}
	if(L-l<min_l)
		cost++;
//	printf("  %d %d\n",min_l,cost);
	return cost<=m;
}
int main()
{
	scanf("%d%d%d",&L,&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",&pos[i]);
	sort(pos+1,pos+n+1);
	check(4);
	int l=1,r=1E9;
	while(l<r)
	{
		//printf("%d %d\n",l,r);
		int m=(l+r)/2+1;
		if(check(m))
			l=m;
		else
			r=m-1;
	}
	printf("%d\n",l);
	return 0;
}
