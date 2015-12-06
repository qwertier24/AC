#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <algorithm>
#define MAXN 250*250
#define INF 999999999
using namespace std;
int num[MAXN],B[MAXN],d[MAXN],g[MAXN];
inline int max(const int a,const int b)
{
	return a>b?a:b;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int kase=1; kase<=T; kase++)
	{
		int n,q,p,nb=0,ans=0;
		n*=n;
		memset(num,0,sizeof(num));
		scanf("%d %d %d",&n,&p,&q);p++;q++;
		for (int i=1;i<=p ;i++ )
		{
			int t;
			scanf("%d",&t);
			num[t]=i;
		}
		for (int i=1;i<=q ; i++)
		{
			int t;
			scanf("%d",&t);
			if(num[t])
				B[++nb]=num[t];
		}
		for (int i=1; i<=nb; i++)
			g[i]=INF;
		for (int i=1; i<=nb;i++ )
		{
			int k=lower_bound(g+1,g+nb+1,B[i])-g;
			d[i]=k;
			g[k]=B[i];
			ans=max(ans,d[i]);
		}
		printf("Case %d: %d\n",kase,ans);
	}
	return 0;
}
