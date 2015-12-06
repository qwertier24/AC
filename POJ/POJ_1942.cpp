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

int main()
{
	long long n,m;
	while((cin>>n>>m)&&(n||m))
	{
		long long c=1;
		long long b=n+m,a=min(n,m);
		for(int i=1; i<=a; i++)
			c=c*(b-i+1)/i;
		cout<<c<<endl;
	}
	return 0;
}
