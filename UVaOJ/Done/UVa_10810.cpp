#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
struct SEQUENCE
{
	int num,pos;
	bool operator<(const SEQUENCE& rhs)const
	{
		return num<rhs.num;
	}
}seq[500001];
int cnt[1000001],n;
inline int lowbit(int x)
{
	return x&(-x);
}
int sum(int p)
{
	int ret=0;
	while(p>0)
	{
		ret+=cnt[p];
		p-=lowbit(p);
	}
	return ret;
}
void add(int num,int p)
{
	while(p<=n)
	{
		cnt[p]+=num;
		p+=lowbit(p);
	}
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		long long ans=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&seq[i].num);
			seq[i].pos=i;
			add(1,i);
			//printf("%d\n",cnt[i]);
		}
		sort(seq+1,seq+n+1);
		for(int i=n; i>=1; i--)
		{
			int p0=sum(seq[i].pos);
			if(i>p0)
			{
				//printf("%d %d %d\n",i,seq[i].pos,seq[i].num);
				ans+=i-p0;
				add(-1,seq[i].pos);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
