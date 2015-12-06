#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int tree1[200000+1],tree2[20000+1],a[200001],n,x[200001];
int lowbit(int num)
{
	return num&(-num);
}
void add1(int pos)
{
	pos+=lowbit(pos);
	while(pos<=n)
	{
		tree1[pos]++;
		pos+=lowbit(pos);
	}
}
void add2(int pos)
{
	pos+=lowbit(pos);
	while(pos<=n)
	{
		tree2[pos]++;
		pos+=lowbit(pos);
	}
}
int main()
{
	int i,j,T;
	scanf("%d",&T);
	for(int k=1; k<=T; k++)
	{
		memset(x,0,sizeof(x));
		memset(tree1,0,sizeof(tree1));
		memset(tree2,0,sizeof(tree2));
		scanf("%d",&n);
		for(i=1; i<=n; i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=1; i<=n; i++)
		{
			x[a[i]]=true;
			add1(a[i]);
		}
		printf("%d",tree1[3]);
		memset(x,0,sizeof(x));
	}
	return 0;
}
