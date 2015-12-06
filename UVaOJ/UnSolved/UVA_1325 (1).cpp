#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct XINGQIU
{
	int rad,p,m;
	double dist;
}qiu[1001][1001],t;
double d[1001][1001];
int x[1001],y[1001],z[1001];
int n;
bool cmp(const struct XINGQIU a,const struct XINGQIU b)
{
	return a.dist<b.dist;
}
int check(double r)
{
	int ret=0;
	t.dist=r;
	for (int i=1; i<=n; i++)
	{
		int p=upper_bound(qiu[i]+2,qiu[i]+n+1,t,cmp) - qiu[i]-1;
		if(qiu[i][p].m>qiu[i][p].p)
			ret++;
	}
	return ret;
}
int main()
{
	while(scanf("%d",&n)!=-1)
	{
		memset(qiu,0,sizeof(qiu));
		for (int i=1;i<=n ;i++ )
			scanf("%d %d %d %d",&x[i],&y[i],&z[i],&qiu[i][1].rad);
		for (int i=1; i<=n;i++ )
			for (int j=2; j<=n; j++)
			{
				d[i][j]=sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) + (z[i]-z[j])*(z[i]-z[j]) );
				qiu[i][j].dist=d[i][j];
				qiu[i][j].rad=qiu[j][1].rad;
				//printf("QIU[%d][%d].RAD=%d\n",i,j,qiu[i][j].rad);
			}
		for (int i=1; i<=n; i++)
		{
			sort(qiu[i]+1,qiu[i]+n+1,cmp);
			for (int j=2; j<=n; j++)
			{
				if(qiu[i][j].rad==qiu[i][1].rad)
					qiu[i][j].p=qiu[i][j-1].p+1;
				else
					qiu[i][j].m=qiu[i][j-1].m+1;
			}
		}
		double ans=100000000;
		int max_num=0;
		for (int i=1;i<=n ;i++ )
			for (int j=i+1; j<=n; j++)
			{
				int num=check(d[i][j]);
				//printf("D=%lf\n",d[i][j]);
				if(num>=max_num)
				{
					max_num=num;
					ans=min(ans,d[i][j]);
				}
			}
		printf("%d\n%.4lf\n",max_num,ans);
	}
	return 0;
}
