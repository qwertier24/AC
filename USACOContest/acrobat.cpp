/*
ID: mayukun3
PROG: acrobat
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
struct COW
{
	int w,s;
	bool operator<(const COW& rhs)const
	{
		return w+s<rhs.w+rhs.s;
	}
}cow[50001];
int main()
{
	int n,ans=-(1<<29);
	freopen("acrobat.in","r",stdin);freopen("acrobat.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d%d",&cow[i].w,&cow[i].s);
	sort(cow+1,cow+n+1);
	int sum=0;
	for(int i=1; i<=n; i++)
	{
		ans=max(ans,sum-cow[i].s);
		sum+=cow[i].w;
	}
	printf("%d\n",ans);
	return 0;
}
//a1-b2<a2-b1