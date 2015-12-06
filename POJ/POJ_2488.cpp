#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
struct P
{
	int x,y;
};
vector<P> ans;
int addx[8]={-1,1,-2,2,-2,2,-1,1},addy[8]={-2,-2,-1,-1,1,1,2,2},n,m,vis[30][30];
bool dfs(int x,int y,int deep)
{
	if(deep==n*m)
	{
		ans.push_back((P){x,y});
		return true;
	}
	vis[x][y]=1;
	for(int i=0; i<8; i++)
	{
		int xt=x+addx[i],yt=y+addy[i];
		if(xt>=1&&xt<=n&&yt>=1&&yt<=m&&!vis[xt][yt])
			if(dfs(xt,yt,deep+1))
			{
				ans.push_back((P){x,y});
				return true;
			}
	}
	vis[x][y]=0;
	return false;
}
void print()
{
	for(int i=ans.size()-1; i>=0; i--)
		printf("%c%d",ans[i].y-1+'A',ans[i].x);
	printf("\n\n");
}
int main()
{
	int T,kase=1;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		bool found=false;
		scanf("%d%d",&n,&m);
		printf("Scenario #%d:\n",kase++);
		for(int i=1; i<=n&&!found; i++)
			for(int j=1; j<=m&&!found; j++)
			{
				memset(vis,0,sizeof(vis));
				//printf("%d %d\n",i,j);
				if(dfs(i,j,1))
				{
					found=true;
					print();
				}
			}
		if(!found)
			printf("impossible\n\n");
	}
	return 0;
}
