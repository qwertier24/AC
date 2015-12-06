#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int num[10001];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&num[i]);
	sort(num+1,num+n+1);
	if(n%2)
		printf("%d\n",num[n/2+1]);
	else
		printf("%d\n",num[n/2]);
	return 0;
}
