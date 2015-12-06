#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
struct SEG
{
	double l,r;
	bool operator<(const SEG& rhs)const
	{
		return l<rhs.l||(l==rhs.l&&r<rhs.r);
	}
};
vector<SEG>seg;
int main()
{
	int n,d,kase=1;
	while(scanf("%d%d",&n,&d)&&(n||d))
	{
		seg.clear();
		int ans=0;
		bool flag=true;
		for(int i=1; i<=n; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(y>d)
				flag=false;
			else
				seg.push_back((SEG){x-sqrt(d*d-y*y),x+sqrt(d*d-y*y)});
		}
		printf("Case %d: ",kase++);
		sort(seg.begin(),seg.end());
		if(flag)
		{
			for(int i=1; i<seg.size(); i++)
			{
				if(seg[i-1].r>=seg[i].l)
				{
					seg[i].l=seg[i-1].l;
					seg[i].r=min(seg[i-1].r,seg[i].r);
					seg[i-1].l=1,seg[i-1].r=0;
				}
				//printf("%lf %lf %lf %lf\n",seg[i-1].l,seg[i-1].r,seg[i].l,seg[i].r);
			}
			for(int i=0; i<seg.size(); i++)
				if(seg[i].l<=seg[i].r)
					ans++;
			printf("%d\n",ans);
		}
		else
			printf("-1\n");
	}
	return 0;
}
