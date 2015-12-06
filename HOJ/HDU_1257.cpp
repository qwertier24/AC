#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int d[1010]={0},h[1001]={0};
int main()
{
	int n,ans;
	while(scanf("%d",&n)!=EOF)
	{
		ans=0;
		memset(d,0,sizeof(d));
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&h[i]);
			for(int j=0; j<i; j++)
				if(h[j]<h[i])
					d[i]=max(d[i],d[j]+1);
			//printf("%d %d\n",i,d[i]);
			ans=max(ans,d[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
