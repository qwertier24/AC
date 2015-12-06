#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
map <string,int> mp;
int cnt,n,b,quality[1001];
struct ASS
{
	string type;
	int p,q,t;
}ass[1001];
bool cmp(int a,int b)
{
	return a>b;
}
bool cmp2(struct ASS a, struct ASS b)
{
	return a.p<b.p;
}
bool check(int min_q)
{
	int mark[1001],sum=0;
	memset(mark,0,sizeof(mark));
	for (int i=1; i<=n; i++)
	{
		if(!mark[ass[i].t] && ass[i].q>=quality[min_q])
		{
			sum+=ass[i].p;
			mark[ass[i].t]=1;
		}
	}
	if(sum>b)return false;
	else
	{
		for (int i=1; i<=cnt; i++)
			if(!mark[i])
				return false;
	}
	return true;
}
int main()
{
	int i,j;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		cnt=0;
		mp.clear();
		scanf("%d %d",&n,&b);
		for(i=1; i<=n; i++)
		{
			char t[100];
			cin>>ass[i].type>>t>>ass[i].p>>ass[i].q;
			quality[i]=ass[i].q;
			if(!mp[ass[i].type])
				mp[ass[i].type]=++cnt;
			ass[i].t=mp[ass[i].type];
		}
		sort(quality+1,quality+n+1,cmp);
		sort(ass+1,ass+n+1,cmp2);
		for (i=1; i<=n; i++)
		{
			printf("%d %d\n",ass[i].p,ass[i].q);
		}
		int left=1,right=n;
		while(left<right)
		{
			int mid=left+(right-left)/2;
			printf("mid=%d\n",mid);
			if(check(mid))right=mid;
			else left=mid+1;
		}
		printf("%d\n",quality[left]);
	}
	return 0;
}
