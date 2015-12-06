/*
ID: mayukun3
PROG: cowtour
LANG: C++
*/
#include <stdio.h>
#include <math.h>
#include <vector>
#define INF 200000.0
using namespace std;
vector<int> farm[151];
double g[160][160]={0},maxd[160]={0},w[151]={0};
int farm_num=0,vis[160]={0},f[160],n;
struct P
{
	int x,y;
}p[160];
double dist(const P& a,const P& b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void mark(int x)
{
	if(vis[x])return;
	vis[x]=1;
	farm[farm_num].push_back(x);
	for(int i=1; i<=n; i++)
		if(g[x][i]!=INF)
			mark(i);
}
int main()
{
	double ans=INF;
	freopen("cowtour.in","r",stdin);
	freopen("cowtour.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	for(int i=1; i<=n; i++)
	{
		char s[1000];
		scanf("%s",s);
		for(int j=0; j<n; j++)
		{
			if(s[j]-'0')
				g[i][j+1]=dist(p[i],p[j+1]);
			else
				g[i][j+1]=INF;
		}
		g[i][i]=0;
	}
	for(int i=1; i<=n; i++)
		if(!vis[i])
		{
			farm_num++;
			mark(i);
		}
	for(int l=1; l<=farm_num; l++)
	{
		vector<int> t=farm[l];
		for(int K=0; K<t.size(); K++)
		{
			int k=t[K];
			for(int I=0; I<t.size(); I++)
			{
				int i=t[I];
				for(int J=0; J<t.size(); J++)
				{
					int j=t[J];
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		for(int i=0; i<t.size(); i++)
			for(int j=0; j<t.size(); j++)
				maxd[t[i]]=max(maxd[t[i]],g[t[i]][t[j]]);
	}
	for(int i=1; i<=farm_num; i++)
		for(int j=1; j<=farm_num; j++)
			if(i!=j)
			{
				vector<int> f1=farm[i],f2=farm[j];
				double t=INF;
				for(int k=0; k<f1.size(); k++)
					for(int l=0; l<f2.size(); l++)
						ans=min(ans,dist(p[f1[k]],p[f2[l]])+maxd[f1[k]]+maxd[f2[l]]);
			}
	for(int i=1; i<=n; i++)
		ans=max(ans,maxd[i]);
	printf("%lf\n",ans);
	return 0;
}