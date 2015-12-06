#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#define For(i,begin,end) for(int i=begin; i<=end; i++)
#define oo 1<<30
#define ONLINE 1
#define PROG "photo"
using namespace std;
struct SEG
{
	int l,r;
	bool operator<(const SEG& rhs)const
	{
		return r<rhs.r;
	}
}seg[200010];
int n,m,d[200010]={0},left[200010]={0},right[200010]={0};
int q[200010],front=0,rear=-1;
bool check(int a,int l,int r)
{
	return a>=l&&a<=r;
}
void precalc()
{
	int j=1;
	sort(seg+1,seg+m+1);
	For(i,1,n){
		left[i]=left[i-1];
		while(j<=m&&seg[j].r<i){
			left[i]=max(left[i],seg[j].l);
			j++;
		}
		//printf("%d %d\n",i,j);
	}
	right[n+1]=n;
	j=m;
	for(int i=n; i>=1; i--){
		//printf("  %d %d\n",i,j);
		right[i]=min(right[i+1],i-1);
		while(j&&seg[j].r>=i){
			right[i]=min(right[i],seg[j].l-1);
			j--;
		}
	}
}
int main()
{
	freopen(PROG".in","r",stdin);
#ifdef ONLINE
	freopen(PROG".out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++)
		scanf("%d%d",&seg[i].l,&seg[i].r);
	int ans=-1,p=0;
	precalc();
	For(i,1,n+1){
		for(; p<=right[i]; p++)
			if(d[p]!=-1){
				while(front<=rear&&d[q[rear]]<=d[p])
					rear--;
				q[++rear]=p;
		}
		while(front<=rear&&!check(q[front],left[i],right[i]))
			front++;
		if(front<=rear)
			d[i]=d[q[front]]+(i<=n);
		else
			d[i]=-1;
	}
	printf("%d",d[n+1]);
	return 0;
}
