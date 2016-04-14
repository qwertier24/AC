#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<map>
#include<queue>
#include<iostream>
using namespace std;

int main()
{
	//freopen("prob.in","r",stdin);
	int n;
	scanf("%d",&n);
	if(n<=2)
		printf("-1");
	else
	{
		printf("99 100 ");
		for(int i=3; i<=n; i++)
			printf(" %d",i-2);
	}
  return 0;
}
