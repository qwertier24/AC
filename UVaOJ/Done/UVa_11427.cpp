#include <stdio.h>
#include <string.h>
double p[101][101];
int main()
{
	int T;
	scanf("%d",&T);
	for(int kase=1; kase<=T; kase++)
	{
		int a,b,n;
		double Q=0.0;
		scanf("%d/%d%d",&a,&b,&n);
		memset(p,0,sizeof(p));
		p[0][0]=1.0;
		p[0][1]=0.0;
		double P=(double)a/b;
		for(int i=1; i<=n; i++)
			for(int j=0; j*b<=a*i; j++)
			{
				p[i][j]=p[i-1][j]*(1-P);
				if(j)
					p[i][j]+=p[i-1][j-1]*P;
			}
		for(int i=0; i*b<=n*a; i++)
			Q+=p[n][i];
		printf("Case #%d: %d\n",kase,(int)(1/Q));
	}
	return 0;
}
