#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define INF -10000
int g[160][160],n,v_sum[160][160]={0},sum[160]={0};
bool no_positive()
{
	for(int i=1; i<=n*2; i++)
		for(int j=1; j<=n*2; j++)
			if(g[i][j]>0)
				return false;
	return true;
}
void Init(int top,int bottom)
{
	for(int i=1; i<=2*n; i++)
	{
		sum[i]=sum[i-1]+v_sum[i][bottom]-v_sum[i][top-1];
	}
}
inline int max(const int a,const int b)
{
	return a>b?a:b;
}
inline int min(const int a,const int b)
{
	return a<b?a:b;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int c=0,ans=INF;
		scanf("%d",&n);
		if(n%2)c=1;
		for(int x0=1; x0<=n; x0++)
			for(int y0=1; y0<=n; y0++)
			{
				int num,x,y;
				scanf("%d",&num);
				if(x0>n/2)
					x=x0-n/2;
				else
					x=x0+n/2+c;
				if(y0>n/2)
					y=y0-n/2;
				else
					y=y0+n/2+c;
				g[x][y]=g[x+n][y]=g[x][y+n]=g[x+n][y+n]=num;
				ans=max(ans,g[x][y]);
			}
		if(no_positive())
		{
			printf("%d",ans);
			continue;
		}
		for(int i=1; i<=2*n; i++)
			for(int j=1; j<=2*n; j++)
				v_sum[i][j]=v_sum[i][j-1]+g[j][i];
		for(int t=1; t<=2*n; t++)
			for(int b=t; b-t+1<=n&&b<=n*2; b++)
			{
				Init(t,b);
				int q[160]={0},rear=0,front=0;
				for(int r=1; r<=2*n; r++)
				{
					while(r-q[front]>n && front<rear)
						front++;
					if(ans<sum[r]-sum[q[front]])
					{
						ans=sum[r]-sum[q[front]];
						//printf("t:%d b:%d r:%d q[front]:%d\n",t,b,r,q[front]);
					}
					while(front<rear && sum[r]<=sum[q[rear]])
						rear--;
					q[++rear]=r;
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}
