#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
struct Edge
{
	int f,t,d;
	bool operator<(const Edge& rhs)const
	{
		return d<rhs.d;
	}
};
vector<Edge> edges;
vector<int> alien_pos;
int dist[2500][2500],vis[2500],m,n,s,addx[4]={-1,0,1,0},addy[4]={0,1,0,-1};
int pa[2001];
char g[50][50];
bool check(int x,int y)
{
	return (x<n&&y<m&&x>=0&&y>=0&&!vis[x*m+y]&&g[x][y]!='#');
}
int findset(int x)
{
	if(pa[x]==x)return x;
	else return pa[x]=findset(pa[x]);
}
void bfs(int p0)
{
	//printf("  %d\n",p0);
	queue<int> q;
	memset(vis,0,sizeof(vis));
	q.push(p0);
	dist[p0][p0]=0;
	vis[p0]=1;
	while(!q.empty())
	{
		int p=q.front();
		//printf("p:%d\n",p);
		q.pop();
		int x=p/m,y=p%m;
		for(int i=0; i<4; i++)
			if(check(x+addx[i],y+addy[i]))
			{
				int pt=(x+addx[i])*m+y+addy[i];
				dist[p0][pt]=dist[p0][p]+1;
				vis[pt]=1;
				q.push((x+addx[i])*m+y+addy[i]);
			}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		alien_pos.clear();
		edges.clear();
		scanf("%d%d",&m,&n);
		gets(g[0]);
		for(int i=0; i<n; i++)
			gets(g[i]);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
			{
				if(g[i][j]=='A')
				{
					alien_pos.push_back(i*m+j);
					bfs(i*m+j);
				}
				else if(g[i][j]=='S')
				{
					alien_pos.push_back(i*m+j);
					bfs(i*m+j);
				}
			}
		for(int i=0; i<alien_pos.size(); i++)
			for(int j=0; j<i; j++)
				edges.push_back((Edge){i,j,dist[alien_pos[i]][alien_pos[j]]});
		int ans=0;
		sort(edges.begin(),edges.end());
		for(int i=0; i<edges.size(); i++)
			pa[i]=i;
		for(int i=0; i<edges.size(); i++)
			if(findset(edges[i].f)!=findset(edges[i].t))
			{
				pa[pa[edges[i].f]]=pa[edges[i].t];
				ans+=edges[i].d;
			}
		printf("%d\n",ans);
	}
	return 0;
}
