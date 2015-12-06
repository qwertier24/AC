#include <stdio.h>
int sum[100010]={0};
char s[100010],ansl,ansr;
double ansk=-1;
int stack[100010],top;
inline double k(int x,int y)
{
	return (double)(sum[y]-sum[x])/(double)(y-x);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,l;
		scanf("%d%d",&n,&l);
		scanf("%s",s);
		for(int i=1; i<=n; i++)
		{
			sum[i]=sum[i-1]+s[i-1]-'0';
		}
		top=-1;
		for(int i=l; i<=n; i++)
		{
			stack[++top]=i-l;
			while(top>0&&k(stack[top],i)<k(stack[top-1],i))
				top--;
			if(k(stack[top],i)>ansk)
			{
				ansk=k(stack[top],i);
				ansl=stack[top];
				ansr=i;
			}
			if(k(stack[top],i)==ansk&&i-stack[top]<ansr-ansl)
			{
				ansl=stack[top];
				ansr=i;
			}
		}
		printf("%d %d\n",ansl+1,ansr);
	}
	return 0;
}
