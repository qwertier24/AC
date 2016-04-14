#include <stdio.h>
#include <algorithm>
using namespace std;
struct LAW
{
	int a,b,p;
}law[100010],law2[100010];
int vis[100010]={0},mark[100010]={0};
bool cmp1(const LAW& a,const LAW& b)
{
	if(a.a==b.a)
	{
		return a.b>b.b;
	}
	return a.a>b.a;
}
bool cmp2(const LAW& a,const LAW& b)
{
	if(a.b==b.b)
	{
		return a.a>b.a;
	}
	return a.b<b.b;
}
int main()
{
	int n,p,k;
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1; i<=n; i++)
	{
		scanf("%d%d",&law[i].a,&law[i].b);
		law[i].p=i;
		law2[i].a=law[i].a;
		law2[i].b=law[i].b;
		law2[i].p=i;
	}
	sort(law+1,law+n+1,cmp1);
	sort(law2+1,law2+n+1,cmp2);
	/*
	for(int i=1; i<=n; i++)
		printf("%d %d %d\n",law2[i].p,law2[i].a,law2[i].b);
	printf("\n");
	for(int i=1; i<=n; i++)
		printf("%d %d %d\n",law[i].p,law[i].a,law[i].b);
	*/
	for(int i=1; i<=p-k; i++)
	{
		mark[law2[i].p]=1;
		//printf("%d ",law2[i].p);
	}
	int found=0;
	LAW min_law;
	min_law.b=1<<30;
	for(int i=1; found<k; i++)
	{
		if(!mark[law[i].p])
		{
			printf("%d ",law[i].p);
			vis[law[i].p]=1;
			min_law=cmp2(law[i],min_law)?law[i]:min_law;
			found++;
		}
	}
	//printf("\n%d %d %d\n",min_law.p,min_law.a,min_law.b);
	int pt=upper_bound(law2+1,law2+n+1,min_law,cmp2)-law2-1;
	//printf("%d\n",pt);
	for(int i=pt; found<p ; i--)
	{
		if(!vis[law2[i].p])
		{
			printf("%d ",law2[i].p);
			found++;
		}
	}
	return 0;
}