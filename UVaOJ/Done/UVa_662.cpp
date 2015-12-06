#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define INF 1<<29
using namespace std;
int d[31][210],cost[210][210][210],p[210],last_step[31][210],ans_l[31],ans_r[31];
int main()
{
	int n,m,kase=1;
	while(scanf("%d%d",&n,&m)&&n)
	{
		printf("chain %d\n",kase++);
		memset(cost,0,sizeof(cost));
		for(int i=1; i<=n; i++)
			scanf("%d",&p[i]);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				for(int k=j; k<=n; k++)
				{
					cost[i][j][k]=cost[i][j][k-1]+abs(p[i]-p[k]);
					//printf("%d %d %d %d\n",i,j,k,cost[i][j][k]);
				}
		d[0][0]=0;
		for(int i=1; i<=n; i++)
			d[0][i]=INF;
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
			{
				d[i][j]=INF;
				for(int k=0; k<=j; k++)
				{
					if(d[i][j]>d[i-1][k]+cost[(k+j+1)/2][k+1][j])
					{
						d[i][j]=d[i-1][k]+cost[(k+1+j)/2][k+1][j];
						last_step[i][j]=k;
					}
					//if(d[i][j]!=INF)
					///	printf("%d %d %d\n",i,j,d[i][j]);
				}
			}
		int pos=n;
		for(int i=m; i>=1; i--)
		{
			ans_l[i]=last_step[i][pos]+1;
			ans_r[i]=pos;
			pos=last_step[i][pos];
		}
		for(int i=1; i<=m; i++)
			if(ans_l[i]==ans_r[i])
				printf("Depot %d at restaurant %d serves restaurant %d\n",i,ans_l[i],ans_l[i]);
			else
				printf("Depot %d at restaurant %d serves restaurants %d to %d\n",i,(ans_l[i]+ans_r[i])/2,ans_l[i],ans_r[i]);
		printf("Total distance sum = %d\n\n",d[m][n]);
	}
	return 0;
}
