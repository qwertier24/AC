#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
long long cnt[65001]={0},num[65001];
int powten[6]={1,10,1E2,1E3,1E4,1E5};
int main()
{
	int T,pos;
	for(int i=1; i<=65000; i++)
	{
		double t=floor(log10(i));
		num[i]=num[i-1]+(int)t+1;
	}
	for(int i=1; i<=65000; i++)
		cnt[i]=cnt[i-1]+num[i];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&pos);
		int l=1,r=32000;
		while(l<r)
		{
			int m=(l+r)/2;
			//printf("%d %d %d\n",l,r,m);
			if(cnt[m]<=(long long)pos)
				l=m+1;
			else
				r=m;
		}
		l--;
		if(cnt[l]==pos)
			printf("%d\n",l%10);
		else
		{
			//printf("  %d\n",l);
			long long sum=cnt[l];
			int ans=1;
			while(sum+num[ans]<(long long)pos)
				ans++;
			sum+=num[ans-1];
	//printf("%d %I64d %I64d %I64d %I64d\n",ans,num[ans],num[ans-1],num[ans+1],sum);
			double t=floor(log10(ans));
			printf("%d\n",ans/powten[(int)((int)t+1-(pos-sum))]%10);
		}
	}
	return 0;
}
