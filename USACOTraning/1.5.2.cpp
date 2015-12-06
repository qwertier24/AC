/*
ID: mayukun3
PROG: numtri
LANG: C++
*/
#include <stdio.h>
int d[20000]={0},rec[1001][1001];
inline int max(const int a,const int b)
{
	return a>b?a:b;
}
int main()
{
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
			scanf("%d",&rec[i][j]);
	for(int i=n; i>=1; i--)
		for(int j=1; j<=i; j++)
			d[j]=max(d[j],d[j+1])+rec[i][j];
	printf("%d\n",d[1]);
}