#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
int a[100010];
int main()
{
	int n;
	long long sum=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	long long ans;
	sort(a+1,a+n+1);
	ans=(sum-1)/((long long)n-1)+1;
	if(ans<a[n])
		printf("%d",a[n]);
	else
		cout<<ans;
	return 0;
}
