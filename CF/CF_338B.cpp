#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define INF 1<<30
using namespace std;
int n,m,d,aff[100001]={0},upDist[100001],downDist[100001],m1[100001],m2[100001];
vector<int> adj[100001],son[100001];
void Init(int u,int f)
{
	for(int i=0; i<adj[u].size(); i++)
		if(adj[u][i]!=f)
		{
			son[u].push_back(adj[u][i]);
			Init(adj[u][i],u);
		}
}
void findDD(int u,int f)
{
	downDist[u]=-1;
	int max1=-1,max2=-1;
	for(int i=0; i<son[u].size(); i++)
	{
		int v=son[u][i];
		findDD(v,u);
		if(downDist[v]!=-1)
		{
			downDist[u]=max(downDist[u],downDist[v]+1);
			if(max1<downDist[v])
			{
				max2=max1;
				max1=downDist[v];
				m2[u]=m1[u];
				m1[u]=v;
			}
			else if(max2<downDist[v])
			{
				max2=downDist[v];
				m2[u]=v;
			}
		}
	}
	if(aff[u])
		downDist[u]=max(downDist[u],0);
	
}
void findUD(int u,int f)
{
	upDist[u]=-1;
	if(upDist[f]!=-1)
		upDist[u]=upDist[f]+1;
	if(u!=m1[f]&&m1[f]!=0)
		upDist[u]=max(upDist[u],downDist[m1[f]]+2);
	else if(u==m1[f]&&m2[f]!=0)
		upDist[u]=max(upDist[u],downDist[m2[f]]+2);
	if(aff[u])
		upDist[u]=max(upDist[u],0);
	for(int i=0; i<adj[u].size(); i++)
		if(adj[u][i]!=f)
			findUD(adj[u][i],u);
}
int main()
{
	//freopen("prob.out","w",stdout);
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=m; i++)
	{
		int t;
		scanf("%d",&t);
		aff[t]=1;
	}
	for(int i=1; i<n; i++)
	{
		int f,t;
		scanf("%d%d",&f,&t);
		adj[f].push_back(t);
		adj[t].push_back(f);
	}
	upDist[0]=-1;
	downDist[0]=-1;
	Init(1,0);
	findDD(1,0);
	findUD(1,0);
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		//printf("%d %d %d\n",i,upDist[i],downDist[i]);
		if(max(upDist[i],downDist[i])<=d)
			ans++;
	}
	printf("%d",ans);
	return 0;
}
