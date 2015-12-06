#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int v_sum[101][101]={0},sum[101]={0},n;
void Init(int t,int b)
{
	for(int i=1; i<=n; i++)
		sum[i]=sum[i-1]+v_sum[b][i]-v_sum[t-1][i];
}
int main()
{
	int ans=-(1<<30);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			int num;
			scanf("%d",&num);
			v_sum[i][j]=v_sum[i-1][j]+num;
		}
	for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j++)
		{
			Init(i,j);
			int min_sum=0;
			for(int k=1; k<=n; k++)
			{
				ans=max(ans,sum[k]-min_sum);
				min_sum=min(min_sum,sum[k]);
			}
		}
	printf("%d",ans);
	return 0;
}
