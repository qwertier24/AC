#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
int q[200001],d[200001],A[200001],steps[200001];
int main()
{
	freopen("iceroad.in","r",stdin);
	freopen("iceroad.out","w",stdout);
	int n,l,r,ans=0,len,last;
	scanf("%d %d %d",&n,&l,&r);
	for(int i=0; i<=n; i++)
		scanf("%d",&A[i]);
	int rear=0,front=0;
	for(int i=l; i<=n; i++)
	{
		if(i-q[front]>r)
			front++;
		//printf("q[front]=%d d[%d]=%d\n",q[front],i,d[i]);
		d[i]=d[q[front]]+A[i];
		while(front<=rear&&d[i+1-l]>=d[q[rear]])
			rear--;
		q[++rear]=i+1-l;
		//printf("q[front]=%d d[%d]=%d\n",q[front],i,d[i]);
	}
	steps[0]=-1;len=0;
	for(int i=n-r+1; i<=n; i++)
	{
		if(ans<d[i])
		{
			ans=d[i];
			last=i;
		}
	}
	steps[++len]=last;
	//printf("%d %d %d\n",d[48],d[last]-A[last]);
	for(int i=last-1; i>=l; i--)
	{
		//printf("%d\n",i);
		if(d[i]==d[last]-A[last]&&last-i>=l&&last-i<=r)
		{
			//printf("last:%d\n",last);
			last=i;
			steps[++len]=i;
		}
	}
	steps[++len]=0;
	printf("%d\n",ans);
	for(int i=len; i>=0; i--)
		printf("%d ",steps[i]);
	printf("\n");
	return 0;
}
