#include <stdio.h>
#include <string.h>
#define lowbit(x) x&(-x)
int n,sum[200001],num[200001];
void add(int x,int a)
{
	while(x<=n)
	{
		sum[x]+=a;
		x+=lowbit(x);
	}
}
int get(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=sum[x];
		x-=lowbit(x);
	}
	return ret;
}
int main()
{
	int kase=1;
	while(scanf("%d",&n)&&n)
	{
		if(kase!=1)
			printf("\n");
		memset(sum,0,sizeof(sum));
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&num[i]);
			add(i,num[i]);
		}
		char order[10];
		printf("Case %d:\n",kase++);
		while(scanf("%s",order)&&order[0]!='E')
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(order[0]=='M')
				printf("%d\n",get(y)-get(x-1));
			else
			{
				add(x,y-num[x]);
				num[x]=y;
			}
		}
	}
	return 0;
}
