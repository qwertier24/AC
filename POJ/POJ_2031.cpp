#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;
int pa[200];
int findset(int x)
{
	if(pa[x]==x)return x;
	else return pa[x]=findset(pa[x]);
}
struct P
{
	double x,y,z,r;
}p[200];
struct EDGE
{
	int f,t;
	double d;
	bool operator<(const EDGE& rhs)const
	{
		return d<rhs.d;
	}
}edges[40000];
double dist(int a,int b)
{
	double dt= sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y)+(p[a].z-p[b].z)*(p[a].z-p[b].z));
	if(dt<=p[a].r+p[b].r)
		return 0;
	else
		return dt-(p[a].r+p[b].r);
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		double ans=0;
		for(int i=1; i<=n; i++)
			scanf("%lf%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z,&p[i].r);
		int num=0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<i; j++)
			{
				edges[++num].f=i;
				edges[num].t=j;
				edges[num].d=dist(i,j);
			}
		sort(edges+1,edges+num+1);
		for(int i=1; i<=n; i++)
			pa[i]=i;
		for(int i=1; i<=num; i++)
			if(findset(edges[i].f)!=findset(edges[i].t))
			{
				pa[pa[edges[i].f]]=pa[edges[i].t];
				ans+=edges[i].d;
			}
		cout<<setprecision(3)<<setiosflags(ios::fixed)<<ans<<endl;;
	}
	return 0;
}
