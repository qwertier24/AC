#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int d[501],n,m,w;
struct EDGE
{
	int f,t,d;
};
vector<EDGE> edges;
bool BELLMAN_FORD()
{
	for(int i=1; i<n; i++)
		for(int j=0; j<edges.size(); j++)
			d[edges[j].t]=min(d[edges[j].t],d[edges[j].f]+edges[j].d);
	for(int i=0; i<edges.size(); i++)
		if(d[edges[i].t]>d[edges[i].f]+edges[i].d)
			return true;
	return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		edges.clear();
		scanf("%d%d%d",&n,&m,&w);
		for(int i=1; i<=m; i++)
		{
			int f,t,dt;
			scanf("%d%d%d",&f,&t,&dt);
			edges.push_back((EDGE){f,t,dt});
			edges.push_back((EDGE){t,f,dt});
		}
		for(int i=1; i<=w; i++)
		{
			int f,t,dt;
			scanf("%d%d%d",&f,&t,&dt);
			edges.push_back((EDGE){f,t,-dt});
		}
		for(int i=1; i<=n; i++)
			d[i]=1<<30;
		d[1]=0;
		printf("%s\n",BELLMAN_FORD()?"YES":"NO");
		//for(int i=1; i<=n; i++)
		//	printf("d[%d]=%d\n",i,d[i]);
	}
	return 0;
}
