#include <stdio.h>
#include <algorithm>
using namespace std;
int num[400][400],d[400][400]={0};
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
			scanf("%d",&num[i][j]);
	for(int i=n; i>=1; i--)
	{
		for(int j=1; j<=i; j++)
			d[i][j]=num[i][j]+max(d[i+1][j],d[i+1][j+1]);
	}
	printf("%d",d[1][1]);
	return 0;
}
