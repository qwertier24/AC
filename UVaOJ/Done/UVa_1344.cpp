#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int a[1010],b[1010];
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		int marka[1010]={0},markb[1010]={0},ans=0;
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		for(int i=1; i<=n; i++)
			scanf("%d",&b[i]);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=n; i>=1; i--)
			if(!markb[i])
			for(int j=1; j<=n; j++)
				if(!marka[j]&&a[j]>b[i])
				{
					marka[j]=1;
					markb[i]=1;
					ans+=200;
					break;
				}
		for(int i=1; i<=n; i++)
			if(!markb[i])
				for(int j=1; j<=n; j++)
					if(!marka[j]&&a[j]==b[i])
					{
						marka[j]=1;
						markb[i]=1;
						break;
					}
		for(int i=1; i<=n; i++)
			if(!markb[i])
				ans-=200;
		printf("%d\n",ans);
	}
	return 0;
}
