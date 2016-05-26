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
	int n,sum=0,t;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&t);
		sum+=t;
	}
	if(sum%n)
	  printf("%d",n-1);
	else
	  printf("%d",n);
	return 0;
}
