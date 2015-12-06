/*
ID: mayukun3
PROG: milk
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
struct FARM
{
	int p,s;
}f[5001];
bool cmp(const FARM& a,const FARM& b)
{
	return a.p<b.p;
}
int main()
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++)
		scanf("%d %d",&f[i].p,&f[i].s);
	sort(f+1,f+m+1,cmp);
	for(int i=1; i<=m && n>0; i++)
	{
		ans+=min(n,f[i].s)*f[i].p;
		n-=min(n,f[i].s);
	}
	printf("%d\n",ans);
}