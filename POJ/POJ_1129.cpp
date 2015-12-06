#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
vector<int> adj[26];
int n;
bool check(int cn)
{
	//printf("cn:%d\n",cn);
	int channel[26]={0},vis[28];
	for(int i=0; i<n; i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=0; j<adj[i].size(); j++)
			vis[channel[adj[i][j]]]=1;
		int t=1;
		while(vis[t])
			t++;
		if(t>cn)
			return false;
		channel[i]=t;
		//printf("   %d %d %d\n",i,channel[adj[i][0]],channel[i]);
	}
	return true;
}
int main()
{
	char s[100];
	while(scanf("%d",&n)&&n)
	{
		for(int i=0; i<n; i++)
		{
			adj[i].clear();
			scanf("%s",s);
			for(int j=2; j<strlen(s); j++)
				adj[i].push_back(s[j]-'A');
		}
		int l=1,r=26;
		while(l<r)
		{
			int m=(l+r)/2;
			if(check(m))
				r=m;
			else
				l=m+1;
		}
		if(l==1)
			printf("1 channel needed.\n");
		else
			printf("%d channels needed.\n",l);
	}
	return 0;
}
