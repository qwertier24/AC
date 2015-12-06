/*
ID: mayukun3
PROG: agrinet
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int pa[101];
struct PATH
{
	int x,y,w;
	bool operator< (const PATH& rhs) const
	{
		return w<rhs.w;
	}
}path[10010];
int findset(int x)
{
	if(pa[x]==x)
		return x;
	else
		return pa[x]=findset(pa[x]);
}
int main()
{
	freopen("agrinet.in","r",stdin);freopen("agrinet.out","w",stdout);
	int path_num=0,n,dist=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			int t;
			scanf("%d",&t);
			if(i!=j)
			{
				path[path_num].w=t;
				path[path_num].x=i;
				path[path_num++].y=j;
			}
		}
	for(int i=1; i<=n; i++)
		pa[i]=i;
	sort(path,path+path_num);
	for(int i=0; i<path_num; i++)
		if(findset(path[i].x)!=findset(path[i].y))
		{
			pa[pa[path[i].x]]=pa[path[i].y];
			dist+=path[i].w;
		}
	printf("%d\n",dist);
	return 0;
}