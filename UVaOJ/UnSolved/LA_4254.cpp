#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
struct TASK
{
	double left,right,v,w;
}task[100001];
bool check(int v)
{
	double  left=1;
	for (int i=1; i<=n; i++)
	{
		if(left+task[i].w/v > task[i].right)
		{
			printf("V:%d I:%d LEFT:%lf\n",v,i,left);
			return false;
		}
		else
		{
			left=left+task[i].w/v;
			printf("V:%d I:%d LEFT:%lf\n",v,i,left);
		}
	}
	return true;
}
inline int max(int a,int b)
{
	return a>b?a:b;
}
bool cmp(const struct TASK a,const struct TASK b)
{
	return a.right<b.right;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int left=0,right=0;
		scanf("%d",&n);
		for (int i=1; i<=n; i++)
		{
			scanf("%lf %lf %lf",&task[i].left,&task[i].right,&task[i].w);
			task[i].v=task[i].w/(task[i].right-task[i].left+1);
			left=max(left,task[i].v);
			right=max(right,task[i].w);
		}
		sort(task+1,task+n+1,cmp);
		while(left<right)
		{
			int mid=(left+right)/2;
			if(check(mid))
				right=mid;
			else
				left=mid+1;
		}
		printf("     %d\n",left);
	}
	return 0;
}
