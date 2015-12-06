/*
ID: mayukun3
PROG: nocows
LANG: C++
*/
#include <stdio.h>
#define MOD 9901
int d[300][300]={0},f[300]={0},n,h;
int main()
{
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	scanf("%d %d",&n,&h);
	if(n%2==0)
	{
		printf("0\n");
		return 0;
	}
	n=(n-1)/2;
	h=h-1;
	f[0]=1;
	d[1][1]=1;
	d[0][0]=1;
	for(int i=2; i<=h; i++)
	{
		for(int j=i; j<=n; j++)
		{
			for(int k=i-1; j-1-k>=0; k++)
				d[i][j]=(d[i][j]+d[i-1][k]*d[i-1][j-1-k])%MOD;
			for(int k=i-1; j-1-k>=0; k++)
				d[i][j]=(d[i][j]+2*d[i-1][k]*f[j-1-k])%MOD;
		}
		for(int j=i-1; j<=n; j++)
			f[j]=(f[j]+d[i-1][j])%MOD;
	}
	printf("%d\n",d[h][n]);
}