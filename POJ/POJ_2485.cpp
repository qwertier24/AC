#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int pa[501];
struct EDGE
{
	int f,t,d;
	bool operator<(const EDGE& rhs)const
	{
		return d<rhs.d;
	}
};
vector<EDGE> edges;
int findset(int x)
{
	if(pa[x]==x)return x;
	else return pa[x]=findset(pa[x]);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int ans=0,n;
		edges.clear();
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			pa[i]=i;
			for(int j=1; j<=n; j++)
			{
				int d;
				scanf("%d",&d);
				if(i<j)
					edges.push_back((EDGE){i,j,d});
			}
		}
		sort(edges.begin(),edges.end());
		for(int i=0; i<edges.size(); i++)
			if(findset(edges[i].f)!=findset(edges[i].t))
			{
				ans=max(ans,edges[i].d);
				pa[pa[edges[i].f]]=pa[edges[i].t];
			}
		printf("%d\n",ans);
	}
	return 0;
}
