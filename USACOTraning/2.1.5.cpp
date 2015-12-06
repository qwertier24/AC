/*
ID: mayukun3
PROG: sort3
LANG: C++
*/
#include <algorithm>
#include <stdio.h>
using namespace std;
int main()
{
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	int n,npos[1001],num[1001],ans=0,count[4]={0};
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&num[i]);
		count[num[i]]++;
	}
	int i;
	for(i=1; i<=count[1]; i++)
		npos[i]=1;
	for(; i<=count[1]+count[2]; i++)
		npos[i]=2;
	for(; i<=count[1]+count[2]+count[3]; i++)
		npos[i]=3;
	for(i=1; i<=n; i++)
		if(num[i]!=npos[i])
			for(int j=i+1; j<=n; j++)
				if(num[j]==npos[i]&&num[i]==npos[j])
				{
					//printf("%d %d\n",i,j);
					ans++;
					swap(num[j],num[i]);
				}
	for(int i=1; i<=count[1]; i++)
		if(num[i]!=npos[i])
		{
			ans+=2;
		}
	printf("%d\n",ans);
}