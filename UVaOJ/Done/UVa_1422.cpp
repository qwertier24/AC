#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int t,n;
struct Task
{
	int l,r,w;
	bool operator<(const Task& rhs)const
	{
		if(r==rhs.r)
			return l>rhs.l;
		return r>rhs.r;
	}
}tasks[10010];
bool cmp(const Task& a,const Task& b)
{
	if(a.l==b.l)
		return a.r<b.r;
	return a.l<b.l;
}
bool check(int v)
{
	priority_queue<Task> pq;
	int p=1,done=0;
	for(int i=1; i<=t; i++)
	{
		int rem=v;
		while(tasks[p].l==i&&p<=n)
			pq.push(tasks[p++]);
		while(rem)
		{
			//printf("%d %d %d\n",rem,p,pq.size());
			if(pq.empty())
				break;
			Task task=pq.top();
			pq.pop();
			int remt=rem;
			rem-=min(remt,task.w);
			task.w-=min(task.w,remt);
			if(task.w)
				pq.push(task);
			else
				done++;
			//printf("  %d   %d %d %d   %d %d\n",i,task.l,task.r,task.w,pq.size(),remt);
		}
		if(!pq.empty()&&pq.top().r<=i)
		{
			//printf("   %d %d %d\n",pq.top().l,pq.top().r,pq.top().w);
			return false;
		}
	}
	if(done==n)
		return true;
	else
		return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		t=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d%d",&tasks[i].l,&tasks[i].r,&tasks[i].w);
			tasks[i].r--;
			t=max(t,tasks[i].r);
		}
		int l=1,r=20010;
		sort(tasks+1,tasks+n+1,cmp);
		//for(int i=1; i<=n; i++)
			//printf("\n%d %d %d\n",tasks[i].l,tasks[i].r,tasks[i].w);
		while(l<r)
		{
			int m=(l+r)/2;
			//printf("L:%d R:%d M:%d\n",l,r,m);
			if(check(m))
				r=m;
			else
				l=m+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
