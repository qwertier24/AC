#include <stdio.h>
#include <algorithm>
using namespace std;
int q[100010],front=0,rear=-1,n,s,t,d[100010],sum[100010]={0},num[100010],ans=-(1<<29);
int main()
{
	freopen("ggame.in","r",stdin);
	freopen("ggame.out","w",stdout);
	scanf("%d%d%d",&n,&s,&t);
	q[++rear]=0;
	for(int i=1; i<s; i++)
		scanf("%d",&num[i]),sum[i]=sum[i-1]+num[i];
	for(int i=s; i<=n; i++)
	{
		scanf("%d",&num[i]);
		sum[i]=sum[i-1]+num[i];
		while(i-q[front]>t)
			front++;
		d[i]=sum[i]-sum[q[front]];
		ans=max(ans,d[i]);
		//printf("  %d %d\n",i,d[i]);
		while(front<=rear&&sum[q[rear]]>sum[i+1-s])
			rear--;
		q[++rear]=i+1-s;
	}
	printf("%d",ans);
	return 0;
}
