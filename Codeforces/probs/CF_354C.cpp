#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#define maxn 1000000
#define For(i,n) for(int i=1; i<=n; i++)
using namespace std;
int a,cnt[2000010]={0},n,k;
bool check(int x)
{
	int sum=0;
	for(int y=x; y<=maxn; y+=x)
	{
		sum+=cnt[min(maxn,y+k)]-cnt[y-1];
		//if(cnt[y+k]-cnt[y-1])
		//	printf("%d %d %d %d\n",y+k,cnt[y+k],y-1,cnt[y-1]);
	}
	return sum==n;
}
int main()
{
	scanf("%d%d",&n,&k);
	int minA=1<<30;
	For(i,n)
	{
		int a;
		scanf("%d",&a);
		minA=min(minA,a);
		cnt[a]++;
	}
	if(minA<=k+1)
	{
		printf("%d",minA);
		return 0;
	}
	For(i,maxn)
		cnt[i]+=cnt[i-1];
	for(int x=maxn; x>=k+1; x--)
		if(check(x))
		{
			printf("%d",x);
			return 0;
		}
	return 0;
}
