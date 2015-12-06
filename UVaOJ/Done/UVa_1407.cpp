#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define INF 1<<29
using namespace std;
struct EDGE
{
	int v,d;
};
vector<EDGE> son[510];
int mark[510],d[510][510][2],treeSize[510],ans[510];
int dfs(int o)
{
	treeSize[o]=1;
	for(int i=0; i<son[o].size(); i++)
		treeSize[o]+=dfs(son[o][i].v);
	d[o][1][0]=d[o][1][1]=0;
	for(int k=0; k<son[o].size(); k++)
		for(int i=treeSize[o]; i>=2; i--)
		{
			int v=son[o][k].v,w=son[o][k].d;
			for(int j=min(i,treeSize[v]); j>=1; j--)
			{
				d[o][i][1]=min(d[o][i][1],d[o][i-j][1]+2*w+d[v][j][1]);
				d[o][i][0]=min(d[o][i][0],min(d[o][i-j][1]+d[v][j][0]+w,d[o][i-j][0]+d[v][j][1]+2*w));
				//printf("%d %d %d %d\n",i,j,d[o][i][0],d[o][i][1]);
			}
		}
	return treeSize[o];
}
int main()
{
	int n,kase=1;
	while(scanf("%d",&n)&&n)
	{
		printf("Case %d:\n",kase++);
		for(int i=0; i<n; i++)
			for(int j=1; j<=n; j++)
				d[i][j][0]=d[i][j][1]=INF;
		for(int i=0; i<n; i++)
			son[i].clear();
		for(int i=1; i<n; i++)
		{
			int p,s,dt;
			scanf("%d%d%d",&s,&p,&dt);
			son[p].push_back((EDGE){s,dt});
			mark[s]=1;
		}
		int root;
		for(int i=0; i<n; i++)
			if(!mark[i])
				root=i;
		dfs(root);
		for(int i=1; i<=n; i++)
		{
			ans[i]=min(d[root][i][1],d[root][i][0]);
			//printf("ans[%d]=%d\n",i,ans[i]);
		}
		int q;
		scanf("%d",&q);
		for(int i=1; i<=q; i++)
		{
			int x;
			scanf("%d",&x);
			int k=upper_bound(ans+1,ans+n+1,x)-ans;
			printf("%d\n",k-1);
		}
	}
	return 0;
}
