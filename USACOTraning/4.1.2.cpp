#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
/*
ID: mayukun3
PROG: nuggets
LANG: C++
*/
#include <string>
#include <math.h>
using namespace std;
int paper[12],max_paper=0,d[300*300]={0};
int gcd(int a,int b)
{
	while(a)
	{
		int t=a;
		a=b%a;
		b=t;
	}
	return b;
}
int main()
{
	freopen("nuggets.in","r",stdin);freopen("nuggets.out","w",stdout);
	int n,GCD;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&paper[i]);
		max_paper=max(max_paper,paper[i]);
		GCD=(i==1?paper[i]:gcd(GCD,paper[i]));
	}
	d[0]=1;
	//printf("%d\n",max_paper);
	if(GCD!=1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1; i<=n; i++)
		for(int j=paper[i]; j<=max_paper*max_paper; j++)
		{
			if(d[j-paper[i]])
				d[j]=1;
			//printf("%d %d %d\n",i,j,d[j]);
		}
	for(int i=max_paper*max_paper; i>=0; i--)
		if(!d[i])
		{
			printf("%d\n",i);
			return 0;
		}
	printf("0\n");
	return 0;
}
