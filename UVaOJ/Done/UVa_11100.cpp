#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;
struct NUM
{
	int num,times;
	bool operator<(const NUM& rhs)const
	{
		return times<rhs.times||(times==rhs.times&&num>rhs.num);
	}
};
map<int,int> mp;
int bag[10010];
int main()
{
	int n;
	bool first=true;
	while(scanf("%d",&n)&&n)
	{
		mp.clear();
		int ans=0;
		if(first)
			first=false;
		else
			printf("\n");
		for(int i=0; i<n; i++)
		{
			scanf("%d",&bag[i]);
			mp[bag[i]]++;
		}
		for(map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it)
		{
			ans=max(ans,it->second);
		}
		sort(bag,bag+n);
		printf("%d\n",ans);
		int num=n/ans;
		for(int i=0; i<ans; i++)
		{
			printf("%d",bag[i]);
			for(int j=i+ans; j<n; j+=ans)
				printf(" %d",bag[j]);
			printf("\n");
		}
	}
	return 0;
}
