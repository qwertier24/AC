/*
ID: mayukun3
PROG: inflate
LANG: C++
*/
#include <stdio.h>
#define max(a,b) a>b?a:b
int d[10001],m,n,s,t;
int main()
{
	freopen("inflate.in","r",stdin);freopen("inflate.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d%d",&s,&t);
		for(int j=t; j<=m; j++)
			d[j]=max(d[j],d[j-t]+s);
	}
	printf("%d\n",d[m]);
	return 0;
}