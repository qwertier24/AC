#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <map>
using namespace std;
struct FT
{
	int from,to;
};
map<FT,int> mp;
const bool operator<(const FT a,const FT& b)
{
	if(a.from<b.from || (a.from==b.from&&a.to<b.to))
		return true;
	else
		return false;
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		int ok=true;
		for(int i=1; i<=n; i++)
		{
			int A,B;
			scanf("%d %d",&A,&B);
			FT t;
			t.from=B;t.to=A;
			if(mp[t])
			{
				mp[t]--;
			}
			else
			{
				t.from=A;
				t.to=B;
				mp[t]++;
			}
		}
		map<FT,int>::iterator iter;
		for(iter=mp.begin(); iter!=mp.end(); ++iter)
			if(iter->second)
			{
				ok=false;
				break;
			}
		if(ok)printf("Yes\n");
		else printf("No\n");

	}
	return 0;
}
