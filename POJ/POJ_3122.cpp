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
int n,m,r[10001];
const double Pi=acos(-1.0);
bool check(double min_r2)
{
	int cnt=0;
	for(int i=1; i<=n; i++)
		cnt+=floor((double)r[i]*r[i]/min_r2);
	//printf("%lf %d\n",min_s,cnt);
	if(cnt<m)
		return false;
	else
		return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d\n",&n,&m);
		m++;
		for(int i=1; i<=n; i++)
			scanf("%d",&r[i]);
		double l=0,r=1E8;
		while(r-l>1e-5)
		{
			//printf("%lf %lf\n",l,r);
			double m=(l+r)/2.0;
			if(check(m))
				l=m;
			else
				r=m;
		}
		printf("%.4lf\n",l*Pi);
	}
	return 0;
}
