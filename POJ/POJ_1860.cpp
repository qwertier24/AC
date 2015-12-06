#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;
struct EDGE
{
	int f,t;
	double r,c;
};
vector<EDGE> edges;
int n,m;
double d[101]={0};
bool BELLMAN_FORD()
{
	for(int i=1; i<n; i++)
		for(int j=0; j<edges.size(); j++)
			d[edges[j].t]=max(d[edges[j].t],(d[edges[j].f]-edges[j].c)*edges[j].r);
	for(int i=0; i<edges.size(); i++)
		if(d[edges[i].t]<(d[edges[i].f]-edges[i].c)*edges[i].r)
			return true;
	return false;
}
int main()
{
	double ori;
	int s;
	scanf("%d%d%d%lf",&n,&m,&s,&ori);
	d[s]=ori;
	for(int i=1; i<=m; i++)
	{
		int f,t;
		double r1,c1,r2,c2;
		cin>>f>>t>>r1>>c1>>r2>>c2;
		edges.push_back((EDGE){f,t,r1,c1});
		edges.push_back((EDGE){t,f,r2,c2});
	}
	//BELLMAN_FORD();
	//for(int i=1; i<=n; i++)
	//	cout<<i<<" "<<d[i]<<endl;
	printf("%s\n",BELLMAN_FORD()?"YES":"NO");
	return 0;
}
