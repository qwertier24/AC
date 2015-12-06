#include <stdio.h>
#define zero 5000
int d[21][10001]={0},pos[21],w[21],n,m;
bool check(int a)
{
	if(a>=0&&a<=10000)
		return true;
	else
		return false;
}
int main()
{
	d[0][zero]=1;
	scanf("%d%d",&m,&n);
	for(int i=1; i<=m; i++)
		scanf("%d",&pos[i]);
	for(int i=1; i<=n; i++)
		scanf("%d",&w[i]);
	for(int i=1; i<=n; i++)
	{
		for(int k=0; k<=10000; k++)
		{
			//d[i][k]=d[i-1][k];
			for(int j=1; j<=m; j++)
			{
				if(check(k-w[i]*pos[j]))
					d[i][k]+=d[i-1][k-w[i]*pos[j]];
				//if(d[i][k])
					//printf("%d %d %d %d %d\n",i,j,k,d[i][k],k-w[i]*pos[j]);
			}
			//if(d[i][k])
			//printf("%d %d %d\n",i,k,d[i][k]);
		}
	}
	printf("%d",d[n][zero]);
	return 0;
}
