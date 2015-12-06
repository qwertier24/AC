#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
struct PLANET
{
	int x,y,z,move;
	int state[2];
	int no_stable;
	void add_line(int t)
	{
		state[t]++;
		no_stable=(state[move]<state[1^move]);
	}
}p[1010];
struct EDGE
{
	int p1,p2;
	int d;
	bool operator<(const EDGE& rhs) const
	{
		return d<rhs.d;
	}
}edges[1000000];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int ans_cnt=0,ans_r2=0,cnt=0,edges_num=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d %d %d %d",&p[i].x,&p[i].y,&p[i].z,&p[i].move);
			p[i].state[p[i].move]=1;
			p[i].state[1^p[i].move]=0;
			p[i].no_stable=0;
		}
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
			{
				edges[edges_num].d=(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y)+(p[i].z-p[j].z)*(p[i].z-p[j].z);
				edges[edges_num].p1=i;
				edges[edges_num].p2=j;
				edges_num++;
			}
		sort(edges,edges+edges_num);
		for(int i=0; i<edges_num; i++)
		{
			//printf("%d\n",i);
			int l=i,r=i;
			while(r<edges_num-1&&edges[r+1].d==edges[l].d)
				r++;
			for(int j=l; j<=r; j++)
			{
				int a=edges[j].p1,b=edges[j].p2;
				cnt-=p[a].no_stable;
				cnt-=p[b].no_stable;
				p[a].add_line(p[b].move);
				p[b].add_line(p[a].move);
				cnt+=p[a].no_stable;
				cnt+=p[b].no_stable;
			}
			if(cnt>ans_cnt)
			{
				ans_cnt=cnt;
				ans_r2=edges[i].d;
			}
			i=r;
		}
		printf("%d\n%.4lf\n",ans_cnt,sqrt(ans_r2));
	}
	return 0;
}
