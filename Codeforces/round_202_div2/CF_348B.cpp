#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#define gcd __gcd
using namespace std;
int val[100010]={0},n;
vector<int> adj[100010];
bool flag=true;
int dfs(int u,int f)
{
	for(int i=0; i<adj[u].size(); i++)
		if(adj[u][i]!=f)
			val[u]+=dfs(adj[u][i],u);
	return val[u];
}
int dfs2(int u,int f)
{
	int k=1;
	if(f!=-1&&adj[u].size()==1)
		return 1;
	for(int i=0; i<adj[u].size(); i++)
		if(adj[u][i]!=f)
		{
			int a=dfs2(adj[u][i],u);
			k*=a/gcd(k,a);
			if(k>val[u])
				flag=false;
			break;
		}
	printf("%d %d\n",u,k);
	if(f==-1)
		return k*adj[u].size();
	else
		return k*(adj[u].size()-1);
}
bool check(int u,int f,long long cut_num)
{
	if(cut_num>val[u]||cut_num%(adj[u].size()-1)!=0)
		return false;
	for(int i=0; i<adj[u].size(); i++)
		if(adj[u][i]!=f)
			if(check(adj[u][i],u,cut_num/(adj[u].size()-1)))
				return false;
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&val[i]);
	for(int i=1; i<n; i++)
	{
		int f,t;
		scanf("%d %d",&f,&t);
		adj[f].push_back(t);
		adj[t].push_back(f);
	}
	long long LCM=dfs2(1,-1);
	cout<<LCM;
	if(!flag)
		puts("  -1");
	else
	{
		long long l=1,r=(long long)1e5;
		while(l<r)
		{
			long long m=(l+r)/2;
			if(check(1,-1,m*LCM))
				r=m;
			else
				l=m+1;
		}
	}
	return 0;
}
