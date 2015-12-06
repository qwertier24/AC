#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#define INF 1e30
using namespace std;
const double PI=acos(-1.0);
map<int,int> lengths;
int n,k;
struct P
{
	double angle;
	int length2;
	bool operator<(const P& rhs)const
	{
		return angle<rhs.angle;
	}
}p[5000];
inline double minuss(double a)
{
	return a>=0?a:a+2*PI;
}
double cost(int maxH2)
{
	vector<int> v;
	double t=maxH2/2;
	double ret=INF;
	for(int i=0; i<n; i++)
		if(p[i].length2<=maxH2)
			v.push_back(i);
	if(v.size()<k)
		return INF;
	for(int i=0; i<v.size(); i++)
		ret=min(ret,t*fabs(p[v[(i+k-1)%v.size()]].angle-p[v[i]].angle));
	return ret;
}
int main()
{
	//freopen("prob.txt","r",stdin);
	int kase=1;
	while(scanf("%d%d",&n,&k)&&n)
	{
		lengths.clear();
		double ans=INF;
		for(int i=0; i<n; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			p[i].length2=x*x+y*y;
			lengths[p[i].length2]=1;
			/*
			if(y>=0)
			{
				p[i].angle=acos(x/sqrt(x*x+y*y));
			}
			else
			{
				p[i].angle=2*PI-acos(x/sqrt(x*x+y*y));
			}
			*/
			if(x >= 0)
			{
				if(y >= 0) p[i].angle = atan( (y*1.0)/x );
				else p[i].angle = 2*PI - atan( (-y*1.0)/x );
			}
			else
			{
				if(y >= 0) p[i].angle = PI - atan( (y*1.0)/(-x) );
				else p[i].angle = PI + atan( (-y*1.0)/(-x) );
			}
		}
		sort(p,p+n);
		for(map<int,int>::iterator it=lengths.begin(); it!=lengths.end(); ++it)
		{
			ans=min(ans,cost(it->first));
		}
		printf("Case #%d: %.2lf\n",kase++,ans);
	}
//	while(1);
	return 0;
}
