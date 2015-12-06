#include <stdio.h>
#include <string.h>
#define maxn 31
double p[maxn],total=0,a[maxn]={0};
bool vis[maxn]={0};
int n,r;
void search(int deep,int pos)
{
	vis[pos]=true;
	double t=1.0;
	if(deep==r)
	{
		for(int i=1; i<=n; i++)
			if(vis[i])
		{
			t*=p[i];
		}
		for(int i=1; i<=n; i++)
			if(!vis[i])
			t*=(1-p[i]);
		total+=t;
		for(int i=1; i<=n; i++)
			if(vis[i]){
			a[i]+=t;
		}
	}
	else
		for(int i=pos+1; i<=n+deep+1-r; i++)
			search(deep+1,i);
	vis[pos]=false;
}
int main()
{
	int kase=0;
	while(scanf("%d%d",&n,&r)&&n)
	{
		kase++;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		total=0;
		for(int i=1; i<=n; i++)
			scanf("%lf",&p[i]);
		printf("Case %d:\n",kase);
		if(r==0)
		{
			for(int i=1; i<=n; i++)
				printf("0\n");
		}
		else
		{
			for(int i=1; i<=n-r+1; i++)
			search(1,i);
			for(int i=1; i<=n; i++)
			printf("%lf\n",a[i]/total);
		}
	}
	return 0;
}
