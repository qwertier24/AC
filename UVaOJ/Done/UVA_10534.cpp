#include <stdio.h>
#include <algorithm>
using namespace std;
int t_s[10001],S[10001],n,num[10001],d1[10001],d2[10001],g[10001];
bool cmp(const int& a,const int& b)
{
	return a<b;
}
inline int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int nn=1,ans=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&S[i]);
			t_s[i]=S[i];
		}
		sort(t_s+1,t_s+n+1,cmp);
		num[1]=t_s[1];
		for(int i=2; i<=n; i++)
		{
			while(t_s[i]==t_s[i-1])
				i++;
			num[++nn]=t_s[i];
		}
		for(int i=1; i<=n; i++)
			S[i]=lower_bound(num+1,num+nn+1,S[i])-num;
		for(int i=1; i<=nn; i++)
			g[i]=88888888;
		for(int i=1; i<=n; i++)
		{
			int k=lower_bound(g+1,g+nn+1,S[i])-g;
			d1[i]=k;
			g[k]=S[i];
		}
		for(int i=1; i<=nn; i++)
			g[i]=88888888;
		for(int i=n; i>=1; i--)
		{
			int k=lower_bound(g+1,g+nn+1,S[i])-g;
			d2[i]=k;
			g[k]=S[i];
		}
		for(int i=1; i<=n; i++)
		{
			ans=max(ans,min(d1[i],d2[i])*2-1);
		}
		printf("%d\n",ans);
			//printf("%d %d\n",d1[i],d2[i]);
	}
	return 0;
}
