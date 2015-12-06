/*
ID: mayukun3
PROG: hamming
LANG: C++
*/
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> ans;
int n,d,b,diff[1<<8];
bool check(int a)
{
	for(int i=0; i<ans.size(); i++)
		if(diff[a^ans[i]]<d)
			return false;
	return true;
}
int main()
{
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	scanf("%d%d%d",&n,&b,&d);
	for(int i=0; i<(1<<b); i++)
	{
		diff[i]=0;
		for(int j=0; j<b; j++)
			if(i&(1<<j))
				diff[i]++;
	}
	ans.push_back(0);
	for(int i=1; i<(1<<b)&&ans.size()<n; i++)
		if(check(i))
			ans.push_back(i);
	printf("%d",ans[0]);
	for(int i=1; i<ans.size(); i++)
	{
		if(i%10==0)
			printf("\n%d",ans[i]);
		else
			printf(" %d",ans[i]);
	}
	printf("\n");
}