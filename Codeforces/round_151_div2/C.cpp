#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<map>
#include<queue>
#include<iostream>
using namespace std;
int num[1000];
int main()
{
	//freopen("prob.in","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",&num[i]);
	sort(num+1,num+n+1);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n-i+1; j++)
		{
			printf("%d %d",i,num[j]);
			for(int k=n-i+2; k<=n; k++)
				printf(" %d",num[k]);
			printf("\n");
			m--;
			if(!m)
				return 0;
		}
	return 0;
}
