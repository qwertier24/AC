#include <stdio.h>
int sum[100010]={0},	q[100010];
char s[100010];
inline double k(int a,int b)
{
	return (double)(sum[a]-sum[b])/(double)(a-b);
}
int n,L,ans_l,ans_r;
double max_ave;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&L);
		scanf("%s",s);
		for(int i=0; i<n; i++)
			sum[i+1]=sum[i]+(s[i]-'0');
		max_ave=-1,ans_l,ans_r;
		int front=0,rear=-1;
		for(int i=L; i<=n; i++)
		{
			int l=i-L;
			while(front<rear&&k(l,q[rear])<=k(q[rear],q[rear-1]))
				rear--;
			q[++rear]=l;
			while(front<rear&&k(i,q[front])<=k(i,q[front+1]))
				front++;
			double t=k(i,q[front]);
			if(max_ave==t&&ans_r-ans_l>i-q[front])
			{
				ans_l=q[front];ans_r=i;
			}
			else if(max_ave<t)
			{
				ans_l=q[front];ans_r=i;max_ave=t;
			}
		}
		printf("%d %d\n",ans_l+1,ans_r);
	}
	return 0;
}
