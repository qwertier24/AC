#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
struct F
{
	int opt,num;
}f[500001];
bool cmp(const F& a,const F& b)
{
	return a.num<b.num;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,ans=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&f[i].num);
			if(f[i].num<0)
			{
				f[i].num=-f[i].num;
				f[i].opt=-1;
			}
			else
			{
				f[i].opt=1;
			}
		}
		sort(f+1,f+n+1,cmp);
		int p=1;
		while(p<=n && f[p].opt!=1)
		{
			p++;
		}
		if(p>n)
		{
			printf("1\n");
			continue;
		}
		int o=1,count=1;
		for(int i=p+1; i<=n; i++)
		{
			if(f[i].opt!=o)
			{
				o=f[i].opt;
				count++;
			}
		}
		ans=max(ans,count);
		count=1,p=1,o=-1;
		while(p<=n && f[p].opt!=-1)
			p++;
		if(p>n)
		{
			printf("1\n");
			continue;
		}
		for(int i=p+1; i<=n;i ++)
		{
			if(f[i].opt!=o)
			{
				o=f[i].opt;
				count++;
			}
		}
		ans=max(ans,count);
		printf("%d\n",ans);
	}
	return 0;
}
