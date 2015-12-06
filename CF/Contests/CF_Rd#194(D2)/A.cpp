#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=n*n/2; i>=n/2; i-=n/2)
	{
		for(int j=i-n/2+1; j<=i; j++)
			printf("%d ",j);
		for(int j=n*n-i+1; j<=n*n-i+1+n/2-1; j++)
			printf("%d ",j);
		printf("\n");
	}
	return 0;
}
