#include <stdio.h>
#include <string.h>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;
struct P
{
	int h,pos;
	bool operator<(const P& rhs) const
	{
		return h<rhs.h||(h==rhs.h&&pos<rhs.pos);
	}
}p[1001];
int ans[5000],mh[1010][1010],width[1010],height[1010];
char g[1010][1010];
set<int> st;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		memset(ans,0,sizeof(ans));
		memset(mh,0,sizeof(mh));
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			scanf("%s",g[i]+1);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				if(g[i][j]=='.')
					mh[i][j]=mh[i-1][j]+1;
		for(int i=1; i<=n; i++)
		{
			st.clear();
			memset(width,0,sizeof(width));
			memset(height,0,sizeof(height));
			for(int j=1; j<=m; j++)
				p[j].h=mh[i][j],p[j].pos=j;
			sort(p+1,p+m+1);
			for(int j=1; j<=m; j++)
			{
				if(!p[j].h)
				{
					st.insert(p[j].pos);
					continue;
				}
				set<int>::iterator it=st.lower_bound(p[j].pos);
				if(it==st.begin())
				{
					width[p[j].pos]=p[j].pos;
					height[p[j].pos]=p[j].h;
				}
				else
				{
					it--;
					if(width[*it]+height[*it]>p[j].h)
					{
						width[p[j].pos]=width[*it]+p[j].pos-*it;
						height[p[j].pos]=height[*it];
					}
					else
					{
						width[p[j].pos]=p[j].pos-*it;
						height[p[j].pos]=p[j].h;
					}
				}
				ans[width[p[j].pos]+width[p[j].pos]+height[p[j].pos]+height[p[j].pos]]++;
				st.insert(p[j].pos);
			}
		}
		for(int i=4; i<=n+n+m+m; i++)
		{
			if(ans[i])
				printf("%d x %d\n",ans[i],i);
		}
	}
	return 0;
}
