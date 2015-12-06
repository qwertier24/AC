/*
ID: mayukun3
PROG: buylow
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define ONLINE
#define PROG "buylow"
using namespace std;
int n,cost[5010],max_inc=0,d1[5010];
struct BIGN
{
	int num[100];
	int len;
	void operator+=(BIGN& t)
	{
		len=max(len,t.len);
		int c=0;
		for(int i=1; i<=len||c; i++)
		{
			if(i>len)len++;
			num[i]+=c;
			c=(num[i]+t.num[i])/10;
			num[i]=(num[i]+t.num[i])%10;
		}
	}
	void print()
	{
		for(int i=len; i>=1; i--)
			printf("%d",num[i]);
		printf("\n");
	}
	BIGN()
	{
		memset(num,0,sizeof(num));
		len=0;
	}
}d2[5010];
void rev()
{
	for(int i=1; i<=n/2; i++)
		swap(cost[i],cost[n-i+1]);
}
int main()
{
#ifdef ONLINE
	freopen(PROG".in","r",stdin);
	freopen(PROG".out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&cost[i]);
	rev();
	d1[0]=0;
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<i; j++)
			if(cost[i]>cost[j])
				d1[i]=max(d1[i],d1[j]+1);
		max_inc=max(max_inc,d1[i]);
	}
	memset(d2,0,sizeof(d2));
	d2[0].len=1;
	d2[0].num[1]=1;
	for(int i=1; i<=n; i++)
	{
		int min_cost=-1;
		for(int j=i-1; j>=0; j--)
			if(d1[j]==d1[i]-1&&cost[j]>min_cost&&cost[j]<cost[i])
			{
				//if(cost[i]==69)
					//printf(" %d %d\n",cost[j],d2[j]);
				min_cost=cost[j];
				d2[i]+=d2[j];
			}
		//printf("%d %d %I64d %d\n",cost[i],d1[i],d2[i],min_cost);
	}
	BIGN ans;
	int min_cost=-1;
	for(int i=n; i>=1; i--)
		if(d1[i]==max_inc&&cost[i]>min_cost)
		{
			min_cost=cost[i];
			ans+=d2[i];
		}
	printf("%d ",max_inc);
	ans.print();
}
