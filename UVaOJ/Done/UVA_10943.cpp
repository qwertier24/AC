#include <stdio.h>
#include <string.h>
int d[101][101];
void Init()
{
	memset(d,0,sizeof(d));
	for(int i=0; i<=100; i++)
		d[0][0]=1;
	for(int k=1; k<=100; k++)
		for(int N=0; N<=100; N++)
			for(int i=0; i<=N; i++)
				d[k][N]=(d[k][N]+d[k-1][N-i])%1000000;
}
int main()
{
	int n,k;
	Init();
	while(scanf("%d%d",&n,&k)&&n)
	{
		printf("%d\n",d[k][n]);
	}
	return 0;
}
