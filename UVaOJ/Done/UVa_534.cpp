#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
struct PATH
{
	int f,t;
	double d;
	PATH(int a,int b,double c):f(a),t(b),d(c){}
	PATH(){}
	bool operator<(const PATH& rhs) const
	{
		return d<rhs.d;
	}
};
vector<PATH> paths;
int x[1001],y[1001],pa[1001],road[1001][1001],n,vis[1001];
double ans=0;
int findset(int x)
{
	if(pa[x]==x)return x;
	else return pa[x]=findset(pa[x]);
}
double dist(int a,int b)
{
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
bool dfs(int x)
{
	bool arrivable=false;
	vis[x]=1;
	if(x==2)return true;
	for(int i=1; i<=n; i++)
		if(road[x][i]&&!vis[i]&&dfs(i))
		{
			arrivable=true;
			ans=max(ans,dist(x,i));
			break;
		}
	return arrivable;
}
int main()
{
	int kase=1;
	while(scanf("%d",&n)&&n)
	{
		paths.clear();
		memset(vis,0,sizeof(vis));
		memset(road,0,sizeof(road));
		ans=0;
		for(int i=1; i<=n; i++)
			scanf("%d %d",&x[i],&y[i]),pa[i]=i;
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
				paths.push_back(PATH(i,j,dist(i,j)));
		sort(paths.begin(),paths.end());
		for(int i=0; i<paths.size(); i++)
			if(findset(paths[i].f)!=findset(paths[i].t))
				{
						pa[pa[paths[i].f]]=pa[paths[i].t];
						road[paths[i].f][paths[i].t]=road[paths[i].t][paths[i].f]=1;
				}
		dfs(1);
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",kase++,ans);
	}
}
/*
2
0 0
3 4
3
17 4
19 4
18 5
0
*/
