#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXN 100001
int total_dist[MAXN],origin_dist[MAXN],d[MAXN],total_w[MAXN];
int func(int i)
{
	return d[i]+origin_dist[i+1]-total_dist[i+1];
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(d,0,sizeof(d));
		memset(total_dist,0,sizeof(total_dist));
		memset(origin_dist,0,sizeof(origin_dist));
		memset(total_w,0,sizeof(total_w));
		int n,C;
		scanf("%d %d",&C,&n);
		int xt=0,yt=0;
		for(int i=1; i<=n; i++)
		{
			int x,y,w;
			scanf("%d %d %d",&x,&y,&w);
			total_dist[i]=total_dist[i-1]+abs(x-xt)+abs(y-yt);
			origin_dist[i]=abs(x)+abs(y);
			total_w[i]=total_w[i-1]+w;
			xt=x,yt=y;
		}
		int front=1,rear=1,q[MAXN];
		memset(q,0,sizeof(q));
		for(int i=1; i<=n; i++)
		{
			while(rear<=front && total_w[i]-total_w[q[rear]]>C)rear++;
			d[i]=func(q[rear])+total_dist[i]+origin_dist[i];
			while(rear<=front && func(i)<=func(q[front]))front--;
			q[++front]=i;
			//printf("I:%d FRONT:%d q[front]:%d REAR:%d q[rear]:%d FUNC[Q[REAR]]:%d D[i]:%d\n",i,front,q[front],rear,q[rear],func(q[rear]),d[i]);
		}
		printf("%d\n",d[n]);
		if(T>0)printf("\n");
	}
	return 0;
}
