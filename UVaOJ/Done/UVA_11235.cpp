#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 100001
struct PART
{
	int left,right;
}part[N+1];
int locate[N+1],a[N+1],d[N+1][20];
inline int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i,j,T,n,q;
	while(true)
	{
		int p_num=0,t=3000000;
		memset(a,0,sizeof(a));
		memset(locate,0,sizeof(locate));
		memset(d,0,sizeof(d));
		memset(part,0,sizeof(part));
		scanf("%d",&n);
		if(!n)break;
		scanf("%d",&q);
		for (i=1; i<=n; i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==t)
			{
				locate[i]=p_num;
				part[p_num].right=i;
				d[p_num][0]++;
			}
			else
			{
				part[++p_num].left=i;
				locate[i]=p_num;
				part[p_num].right=i;
				d[p_num][0]++;
				t=a[i];
			}
		}
		for(j=1; (1<<j)<=p_num; j++)
			for(i=1; i+(1<<j)<=p_num; i++)
			{
				d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
			}
		for (i=1;i<=q ;i++ )
		{
			int left,right;
			scanf("%d%d",&left,&right);
			int l=part[locate[left]].right+1,r=part[locate[right]].left-1;
			if(l>right)
				printf("%d\n",right-left+1);
			else if(l>r)
				printf("%d\n",max(l-left,right-r));
			else
			{
				int k=0;
				while((1<<k)<=locate[r]-locate[l]+1)
					k++;
				k--;
				printf("%d\n",max(max(d[locate[l]][k],d[locate[r]-(1<<k)+1][k]),max(l-left,right-r)));
			}
		}
	}
	return 0;
}
