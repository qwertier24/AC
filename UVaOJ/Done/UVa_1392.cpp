#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
struct P
{
	int h,pos;
	bool operator<(const P& rhs)const
	{
		return h<rhs.h;
	}
}points[150010]={0};
char s1[150010],s2[150010];
int main()
{
	int n,p;
	while(scanf("%d%d",&n,&p)&&n)
	{
		int ans=0,max_pos=0;
		scanf("%s%s",s1,s2);
		for(int i=1; i<=n; i++)
		{
			points[i].h=points[i-1].h+100*(s1[i-1]!=s2[i-1])-p;
			points[i].pos=i;
			//printf("%d %d\n",i,points[i].h);
		}
		points[++n].h=0;
		points[n].pos=0;
		sort(points+1,points+n+1);
		for(int i=1; i<=n; i++)
		{
			int l=i,r=i;
			while(r<n&&points[r].h==points[r+1].h)
				r++;
			for(int j=l; j<=r; j++)
				max_pos=max(max_pos,points[j].pos);
			for(int j=l; j<=r; j++)
				ans=max(ans,max_pos-points[j].pos);
			//printf("%d %d %d %d\n",l,r,max_pos,points[l].h);
			i=r;
		}
		if(ans)
			printf("%d\n",ans);
		else
			printf("No solution.\n");
	}
	return 0;
}
