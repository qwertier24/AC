#include <stdio.h>
#include <algorithm>
#include <string.h>
#define INF 1<<30
#define maxnode 1<<17
using namespace std;
int v,y1,y2,ans_min,ans_max,ans_sum;
struct IntervalTree
{
	int sumv[maxnode],addv[maxnode],minv[maxnode],maxv[maxnode],setv[maxnode];
	void pushdown(int o)
	{
		int lc=o<<1,rc=o<<1|1;
		if(setv[o]>=0)
		{
			setv[lc]=setv[rc]=setv[o];
			addv[lc]=addv[rc]=0;
			setv[o]=-1;
		}
		if(addv[o])
		{
			addv[lc]+=addv[o];
			addv[rc]+=addv[o];
			addv[o]=0;
		}
	}
	void maintain(int o,int l,int r)
	{
		if(setv[o]>=0)
		{
			minv[o]=maxv[o]=setv[o];
			sumv[o]=setv[o]*(r-l+1);
		}
		else if(r>l)
		{
			sumv[o]=sumv[o<<1]+sumv[o<<1|1];
			minv[o]=min(minv[o<<1],minv[o<<1|1]);
			maxv[o]=max(maxv[o<<1],maxv[o<<1|1]);
		}
		minv[o]+=addv[o];
		maxv[o]+=addv[o];
		sumv[o]+=addv[o]*(r-l+1);
	}
	void add(int o,int l,int r)
	{
		if(y1<=l&&y2>=r)
			addv[o]+=v;
		else
		{
			int lc=o<<1,rc=o<<1|1,m=(l+r)/2;
			pushdown(o);
			if(y1<=m)add(lc,l,m); else maintain(lc,l,m);
			if(y2>m)add(rc,m+1,r); else maintain(rc,m+1,r);
		}
		maintain(o,l,r);
	}
	void set(int o,int l,int r)
	{
		if(y1<=l&&y2>=r)
			setv[o]=v,addv[o]=0;
		else
		{
			int lc=o<<1,rc=o<<1|1,m=(l+r)/2;
			pushdown(o);
			if(y1<=m)set(lc,l,m); else maintain(lc,l,m);
			if(y2>m)set(rc,m+1,r); else maintain(rc,m+1,r);
		}
	maintain(o,l,r);
	}
	void query(int o,int l,int r,int cnt)
	{
		if(setv[o]>=0)
		{
			int t=setv[o]+cnt+addv[o];
			ans_min=min(ans_min,t);
			ans_max=max(ans_max,t);
			ans_sum+=t*(min(y2,r)-max(y1,l)+1);
		}
		else if(y1<=l&&y2>=r)
		{
			ans_min=min(ans_min,minv[o]+cnt);
			ans_max=max(ans_max,maxv[o]+cnt);
			ans_sum+=sumv[o]+cnt*(r-l+1);
		} 
		else
		{
			int m=(l+r)/2;
			if(y1<=m)query(o<<1,l,m,cnt+addv[o]);
			if(y2>m)query(o<<1|1,m+1,r,cnt+addv[o]);
		}
	}
}tree[21];
int main()
{
	int r,c,m;
	while(scanf("%d%d%d",&r,&c,&m)!=EOF)
	{
		memset(tree,0,sizeof(tree));
		for(int i=1; i<=r; i++)
		{
			memset(tree[i].setv,-1,sizeof(tree[i].setv));
			tree[i].setv[1]=0;
		}
		for(int i=1; i<=m; i++)
		{
			int x1,x2,order;
			scanf("%d",&order);
			if(order==1)
			{
				scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
				for(int j=x1; j<=x2; j++)
				{
					tree[j].add(1,1,c);
				}
			}
			else if(order==2)
			{
				scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
				for(int j=x1; j<=x2; j++)
				{
					tree[j].set(1,1,c);
				}
			}
			else
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				ans_min=INF;
				ans_max=-INF;
				ans_sum=0;
				for(int j=x1; j<=x2; j++)
				{
					tree[j].query(1,1,c,0);
				}
				printf("%d %d %d\n",ans_sum,ans_min,ans_max);
			}
		}
	}
	return 0;
}
