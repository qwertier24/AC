#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#define INF 1<<30
using namespace std;
int x,y,x1,y1,x2,y2;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long ans=0;
		int n,m,y0,min_y[60010];
		scanf("%d%d",&m,&n);
		m--;
		scanf("%d%d",&x1,&y1);
		for(int i=0; i<=m; i++)
			min_y[i]=INF;
		min_y[x1]=0;
		y0=y1;
		scanf("%d%d",&x2,&y2);
		min_y[x2]=0;
		if(x1>x2)
			swap(x1,x2);
		for(int i=3; i<=n; i++)
		{
			scanf("%d%d",&x,&y);
			min_y[x]=min(min_y[x],abs(y-y0));
		}
		int yt=0;
		for(int i=x1; i<=x2; i++)
		{
			yt=min_y[i]=min(min(yt+1,min_y[i]),min(i-x1,x2-i));
			//printf(" %d %d %d %d\n",i,min_y[i],yt,min(i-x1,x2-i)+y1);
		}
		yt=0;
		for(int i=x2; i>=x1; i--)
		{
			yt=min_y[i]=min(min(yt+1,min_y[i]),min(i-x1,x2-i));
		}
		for(int i=x1+1; i<x2; i++)
		{
			if(min_y[i])
			{
				ans++;
				ans+=max(0,min(m-y0,min_y[i]-1))+max(0,min(y0,min_y[i]-1));
				//printf("  %d %d %d\n",i,min_y[i],ans);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
