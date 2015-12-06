#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
char code[2001][10];
int pa[2001];
struct Edge
{
	int f,t,d;
	bool operator<(const Edge& rhs)const
	{
		return d<rhs.d;
	}
};
vector<Edge> edges;
int dist(int a,int b)
{
	int ret=0;
	for(int i=0; i<7; i++)
		ret+=code[a][i]!=code[b][i];
	return ret;
}
int findset(int x)
{
	if(pa[x]==x)return x;
	else return pa[x]=findset(pa[x]);
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		int ans=0;
		edges.clear();
		for(int i=1; i<=n; i++)
		{
			scanf("%s",code[i]);
			for(int j=1; j<i; j++)
				edges.push_back((Edge){i,j,dist(i,j)});
		}
		for(int i=1; i<=n; i++)
			pa[i]=i;
		sort(edges.begin(),edges.end());
		for(int i=0; i<edges.size(); i++)
			if(findset(edges[i].f)!=findset(edges[i].t))
			{
				pa[pa[edges[i].f]]=pa[edges[i].t];
				ans+=edges[i].d;
			}
		printf("The highest possible quality is 1/%d.\n",ans);
	}
	return 0;
}
