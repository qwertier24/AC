#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct ANT
{
	int pt;
	char dir;
}a[10010];
struct LOC
{
	int order,p0;
}locate[10010];
int order_p[10010];
bool cmp1(const LOC& a,const LOC& b)
{
		return a.p0<b.p0;
}
bool cmp2(const ANT& a,const ANT& b)
{
	return a.pt<b.pt;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int kase=1; kase<=T; kase++)
	{
		int l,t,n;
		scanf("%d%d%d",&l,&t,&n);
		memset(locate,-1,sizeof(locate));
		memset(a,-1,sizeof(a));
		for(int i=1; i<=n; i++)
		{
			scanf("%d %c",&a[i].pt,&a[i].dir);
			locate[i].order=i;
			locate[i].p0=a[i].pt;
		}
		printf("Case #%d:\n",kase);
		sort(locate+1,locate+n+1,cmp1);
		for(int i=1; i<=n; i++)
			order_p[locate[i].order]=i;
		for(int i=1; i<=n; i++)
			a[i].pt=a[i].dir=='L'?a[i].pt-t:a[i].pt+t;
		sort(a+1,a+n+1,cmp2);
		for(int i=1; i<=n-1; i++)
			if(a[i].pt==a[i+1].pt)
				a[i].dir=a[i+1].dir='T';
		for(int i=1;i <=n; i++)
		{
			int p=order_p[i];
			if(a[p].pt>l || a[p].pt<0)
				printf("Fell off\n");
			else
			{
				printf("%d",a[p].pt);
				if(a[p].dir=='T')
					printf(" Turing\n");
				else
					printf(" %c\n",a[p].dir);
			}
		}
		printf("\n");
	}
	return 0;
}
