#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int n,killed[1010];
vector<int> cow[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(killed,0,sizeof(killed));
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			int t;
			cow[i].clear();
			scanf("%d",&t);
			for(int j=1; j<=t; j++)
			{
				int milk;
				scanf("%d",&milk);
				cow[i].push_back(milk);
			}
		}
		int max_eaten=0,cnt_eaten=0;
		for(int now=0; now<2*2520; now++)
		{
			int min_cow=0,min_milk=1<<30;
			bool nocow=true;
			for(int i=1; i<=n; i++)
				if(!killed[i])
				{
					nocow=false;
					if(cow[i][now%cow[i].size()]<min_milk)
					{
						min_milk=cow[i][now%cow[i].size()];
						min_cow=i;
					}
					else if(cow[i][now%cow[i].size()]==min_milk)
						min_cow=0;
				}
			if(min_cow)
			{
				cnt_eaten++;
				max_eaten=now+1;
				killed[min_cow]=1;
			}
			if(nocow)break;
		}
		printf("%d %d\n",n-cnt_eaten,max_eaten);
	}
	return 0;
}
