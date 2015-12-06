#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
#define ODD 0
#define EVEN 1
using namespace std;
long long d[1001][1010]={0};
int main()
{
	for(int i=0; i<=1000; i++)
		d[0][i]=1;
	for(int i=1; i<=1000; i++)
	{
		d[i][i]=1;
		for(int j=i-1; j>=1; j--)
			d[i][j]=(i-2*j>=0?d[i-2*j][j]:0)+d[i][j+1];
	}
	int n;
	while(scanf("%d",&n)&&n)
	{
		cout<<n<<' '<<d[n][1]<<endl;
	}
	return 0;
}
