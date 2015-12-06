#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int d[4][30001]={0},num[30001],d2[4][30001]={0};
int n;
void reserve()
{
	for(int i=1; i<=n/2; i++)
		swap(num[i],num[n-i+1]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&num[i]);
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=3; j++)
		{
			d[j][i]=d[j][i-1]+(num[i]!=j);
			for(int k=1; k<=j; k++)
				d[j][i]=min(d[j][i],d[k][i-1]+(num[i]!=j));
			//printf("%d %d %d\n",j,i,d[j][i]);
		}
	}
	reserve();
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=3; j++)
		{
			d2[j][i]=d2[j][i-1]+(num[i]!=j);
			for(int k=1; k<=j; k++)
				d2[j][i]=min(d2[j][i],d2[k][i-1]+(num[i]!=j));
		}
	}
	printf("%d",min(min(d[1][n],min(d[2][n],d[3][n])),min(d2[1][n],min(d2[2][n],d2[3][n]))));
	return 0;
}
