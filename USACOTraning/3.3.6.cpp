/*
ID: mayukun3
PROG: game1
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int SUM[300],num[300],n,d[300][300];
int sum(int a,int b)
{
	return SUM[b]-SUM[a-1];
}
int main()
{
	freopen("game1.in","r",stdin);freopen("game1.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&num[i]);
		SUM[i]=SUM[i-1]+num[i];
	}
	for(int i=1; i<=n; i++)
		d[i][i]=num[i];
	for(int i=2; i<=n; i++)
		for(int l=1; l+i-1<=n; l++)
		{
			int r=l+i-1;
			d[l][r]=sum(l,r)-min(d[l][r-1],d[l+1][r]);
		}
	printf("%d %d\n",d[1][n],sum(1,n)-d[1][n]);
	return 0;
}