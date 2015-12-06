#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
double sum[1001][32],all_zero[1001],d[1001][31];
int main()
{
	int m,n,l;
	while(scanf("%d%d%d",&m,&n,&l)&&m)
	{
		memset(sum,0,sizeof(sum));
		memset(d,0,sizeof(d));
		for(int i=1; i<=n; i++)
		{
			d[i][0]=1;
			for(int j=1; j<=m; j++)
			{
				double p;
				scanf("%lf",&p);
				for(int k=j; k>=0; k--)
				{
					d[i][k]=d[i][k]*(1.0-p)+(k>0?d[i][k-1]*p:0);
					//printf("%d %d %d %lf\n",i,j,k,d[i][k]);
				}
			}
			for(int j=m; j>=1; j--)
				sum[i][j]=sum[i][j+1]+d[i][j];
		}
		memset(all_zero,0,sizeof(all_zero));
		all_zero[0]=1;
		for(int i=1; i<=n; i++)
			for(int j=i; j>=0; j--)
			{
				all_zero[j]=all_zero[j]*(1.0-d[i][0])+(j>0?all_zero[j-1]*d[i][0]:0);
				//printf("%d %lf %lf\n",j,all_zero[j],d[i][0]);
			}
		//printf("%lf\n",all_zero[0]);
		double ans=1.0;
		for(int i=1; i<=n; i++)
			ans-=all_zero[i];
		double t=1.0;
		for(int i=1; i<=n; i++)
			t*=sum[i][1]-sum[i][l];
		ans-=t;
		printf("%.3f\n",ans);
	}
	return 0;
}
