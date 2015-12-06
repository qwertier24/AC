#include <stdio.h>
#include <string.h>
int d[102][10002],dist[102][10002],sum[102][10002];
int sum_d_dist(int n,int m)
{
	return d[n-1][m]-sum[n][m-1];
}
int sum_d_dist2(int n,int m)
{
	return d[n-1][m]+sum[n][m];
}
inline int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k) && n)
	{
		int t;
		memset(d,0,sizeof(d));
		memset(sum,0,sizeof(sum));
		memset(dist,0,sizeof(dist));
		n++;
		for(int i=n; i>=1; i--)
			for(int j=1; j<=m; j++)
			{
				scanf("%d",&t);
				sum[i][j]=sum[i][j-1]+t;
			}
		for(int i=n; i>=1; i--)
			for(int j=1; j<=m; j++)
			{
				scanf("%d",&t);
				dist[i][j]=dist[i][j-1]+t;
			}
		for(int i=1; i<=n; i++)
		{
			int q[10002];
			int front=1,rear=0;
			for(int j=1; j<=m; j++)
			{
				while(front<=rear && sum_d_dist(i,j) >= sum_d_dist(i,q[rear]))
					rear--;
				q[++rear]=j;
				while(front<=rear && dist[i][j]-dist[i][q[front]-1]>k)
					front++;
				d[i][j]=-1;
				if(front<=rear)
					d[i][j]=sum[i][j]+sum_d_dist(i,q[front]);
			}
			front =1;rear=0;
			for(int j=n; j>=1; j--)
			{
				while(front<=rear && sum_d_dist2(i,j) >= sum_d_dist2(i,q[rear]))
					rear--;
				q[++rear]=j;
				while(front<=rear && dist[i][q[front]]-dist[i][j-1]>k)
					front++;
				if(front<=rear)
					d[i][j]=max(d[i][j],sum_d_dist2(i,q[front])-sum[i][j-1]);
				printf("I:%d Q[%d]:%d Q[%d]:%d D[%d][%d]:%d\n",i,front,q[front],rear,q[rear],i,j,d[i][j]);
			}
		}
		int ans=0;
		for(int i=1; i<=m; i++)
			ans=max(ans,d[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}
/*
Sample Input 

2 3 2 
7 8 1 
4 5 6 
1 2 3 
1 1 1 
1 1 1 
1 1 1 
0 0 0
Sample Output 

27
*/