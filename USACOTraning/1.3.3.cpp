/*
ID: mayukun3
PROG: barn1
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
bool cmp(const int& a,const int& b)
{
	return a>b;
}
int main()
{
	freopen("barn1.in","r",stdin);
freopen("barn1.out","w",stdout);
	int m,s,c,num=0,block[300],ans,house[300];
	memset(block,0,sizeof(block));
	memset(house,0,sizeof(house));
	scanf("%d%d%d",&m,&s,&c);
	ans=s;
	for(int i=1; i<=c; i++)
	{
		int t;
		scanf("%d",&t);
		house[t]++;
	}
	for(int i=1; i<=s; i++)
	{
		while(house[i]!=0&&i<=s)
			i++;
		block[++num]=1;
		i++;
		while((house[i]==house[i-1])&&(house[i]==0)&&i<=s)
		{
			i++;
			block[num]++;
		}
	}
	//for(int i=1; i<=num; i++)
		//printf("%d\n",block[i]);
	if(house[s]==0)
	{
		ans-=block[num];
		block[num]=0;
	}
	if(house[1]==0)
	{
		ans-=block[1];
		block[1]=0;
	}
	sort(block+1,block+s+1,cmp);
	for(int i=1; i<=min(num,m-1); i++)
	{
		ans-=block[i];
		//printf("%d\n",block[i]);
	}
	printf("%d\n",ans);
}