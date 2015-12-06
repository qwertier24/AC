/*
ID: mayukun3
PROG: range
LANG: C++
*/
#include <stdio.h>
char s[300];
int g[251][251],d[251][251]={0};
int n;
int max_a(int x,int y,int dir)
{
}
int main()
{
	freopen("range.in","r",stdin);freopen("range.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%s",s);
		for(int j=0; j<n; j++)
		g[i][j+1]=s[j]-'0';
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(g[i][j])
				d[i][j]=1;
			//printf("%d ",d[i][j]);
		}
		//printf("\n");
	}
	for(int x=1; x<=n; x++)
		for(int y=1; y<=n; y++)
			if(g[x][y])
			for(int a=2; a<=x&&a<=y; a++)
			{
				if(d[x-1][y]>=a-1&&d[x-1][y-1]>=a-1&&d[x][y-1]>=a-1)
					d[x][y]++;
				else
					break;
			}
	for(int i=2; i<=n; i++)
	{
		int cnt=0;
		for(int x=1; x<=n; x++)
			for(int y=1; y<=n; y++)
				if(d[x][y]>=i)
					cnt++;
		if(cnt)
			printf("%d %d\n",i,cnt);
	}
	return 0;
}
