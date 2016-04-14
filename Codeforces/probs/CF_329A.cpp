#include <stdio.h>
char g[110][110];
int col[110]={0},row[110]={0};
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%s",g[i]+1);
		for(int j=1; j<=n; j++)
			if(g[i][j]=='.')
				row[i]=1,col[j]=1;
	}
	bool rowok=true;
	for(int i=1; i<=n; i++)
		if(!row[i])
			rowok=false;
	bool colok=true;
	for(int i=1; i<=n; i++)
		if(!col[i])
			colok=false;
	if(!colok&&!rowok)
	{
		printf("-1");
		return 0;
	}
	//printf("%d %d\n",rowok,colok);
	if(!colok)
	{
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(g[i][j]=='.')
				{
					printf("%d %d\n",i,j);
					break;
				}
	}
	else
	{
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(g[j][i]=='.')
				{
					printf("%d %d\n",j,i);
					break;
				}
	}
	return 0;
}
