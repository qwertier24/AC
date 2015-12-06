#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int d[100001][20];
struct BLOCK
{
	int left,right;
}block[100001];
struct POINT
{
	int num,p;
}point[100001];
int main()
{
	int n,q,bn=1;
	scanf("%d%d",&n,&q);
	scanf("%d",&point[1].num);
	block[1].left=1;
	block[1].right=1;
	for(int i=2; i<=n; i++)
	{
		scanf("%d",&point[i].num);
		if(point[i].num==point[i-1].num)
			block[bn].right++;
		else
		{
			bn++;
			block[bn].left=i;
			block[bn].right=i;
		}
	}
	for(int i=1; i<=bn; i++)
		for(int j=block[i].left; j<=block[i].right; j++)
			point[j].p=i;
	for(int i=1; i<=bn; i++)
		d[i][0]=block[i].right-block[i].left+1;
	for(int i=1; (1<<i)<=bn; i++)
		for(int j=1; j+(1<<i)-1<=bn; j++)
			d[j][i]=max(d[j][i-1],d[j+(1<<(i-1))][i-1]);
	while(q--)
	{
		int l0,r0;
		scanf("%d%d",&l0,&r0);
		if(point[l0].p==point[r0].p)
			printf("%d\n",r0-l0+1);
		else if(point[l0].p==point[r0].p-1)
			printf("%d\n",max(block[point[l0].p].right-l0+1,r0-block[point[r0].p].left+1));
		else
		{
			int l=point[l0].p+1,r=point[r0].p-1;
			int ans=max(block[point[l0].p].right+1-l0,r0-block[point[r0].p].left+1);
			int length=floor(log2(r-l+1));
			printf("%d\n",max(ans,max(d[l][length],d[r-(1<<length)+1][length])));
		}
	}
	return 0;
}
