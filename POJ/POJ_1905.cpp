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
double L0,n,C,Lt;
bool check(double r)
{
	//printf("  %lf %lf\n",r,L0/(2*r));
	return 2*asin(L0/(2*r))*r>=Lt;
}
int main()
{
	while(cin>>L0>>n>>C&&L0!=-1.0)
	{
		//cout<<L0<<endl;
		if(L0==0.0||n==0.0||C==0.0){printf("0.000\n");continue;}
		Lt=(1+n*C)*L0;
		double l=L0/2,r=1E9;
		while(r-l>1E-6)
		{
			//printf("%lf %lf\n",l,r);
			double m=(l+r)/2.0;
			if(check(m))
				l=m;
			else
				r=m;
		}
		printf("%.3f\n",l-sqrt(l*l-(L0/2)*(L0/2)));
	}
	return 0;
}
