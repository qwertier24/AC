/*
ID: mayukun3
PROG: concom
LANG: C++
*/
#include <stdio.h>
int g[101][101]={0};
int bought[101][101]={0},vis[101][101];
int main()
{
	int n;
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		int f,t,x;
		scanf("%d %d %d",&f,&t,&x);
		g[f][t]=x;
	}
	for(int i=1; i<=100; i++)
	{
		vis[i][i]=1;
		while(true)
		{
			int x=0;
			for(int j=1; j<=100; j++)
				if(g[i][j]>50&&!vis[i][j])
				{
					x++;
					bought[i][j]=1;
					vis[i][j]=1;
					for(int k=1; k<=100; k++)
					{
						if(g[i][k]<100)
						g[i][k]+=g[j][k];
					}
				}
			if(x==0)
				break;
		}
	}
	for(int i=1; i<=100; i++)
		for(int j=1; j<=100; j++)
			if((bought[i][j])&&i!=j)
				printf("%d %d\n",i,j);
}