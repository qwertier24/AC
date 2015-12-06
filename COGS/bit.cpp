#include <stdio.h>
#include <queue>
#include <ctype.h>
#include <string.h>
#define INF 10000000
using namespace std;
int g[40000],min_d[40000],f[40000],m,n,vis[40000]={0};
char s[200];
queue<int> q;
void bfs()
{
	//printf("p0=%d\n",p0);
	while(!q.empty())
	{
		int p=q.front();
		//printf("%d %d\n",p,vis[p]);
		q.pop();
		min_d[p]=min_d[f[p]]+1;
		if((p+1)%m&&!vis[p+1])
		{
			q.push(p+1);
			f[p+1]=p;
			vis[p+1]=1;
		}
		if(p%m&&!vis[p-1])
		{
			q.push(p-1);
			f[p-1]=p;
			vis[p-1]=1;
		}
		if(p/m&&!vis[p-m])
		{
			q.push(p-m);
			f[p-m]=p;
			vis[p-m]=1;
		}
		if(p/m+1<n&&!vis[p+m])
		{
			q.push(p+m);
			f[p+m]=p;
			vis[p+m]=1;
		}
	}
}
int main()
{
	freopen("bit.in","r",stdin);
	freopen("bit.out","w",stdout);
	scanf("%d%d",&n,&m);
	min_d[199*199]=-1;
	for(int i=0; i<n; i++)
	{
		scanf("%s",s);
		for(int j=0; j<m; j++)
			g[i*m+j]=s[j]-'0';
		//printf("%d\n",g[i][0]);
	}
	//printf("g[152][0]=%d\n",g[152][0]);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			min_d[i*m+j]=INF;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(g[i*m+j])
			{
				//printf("%d %d %d\n",i,j,g[i*m+j]);
				q.push(i*m+j);
				f[i*m+j]=199*199;
				vis[i*m+j]=1;
			}
	bfs();
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			printf("%d ",min_d[i*m+j]);
		printf("\n");
	}
	return 0;
}
