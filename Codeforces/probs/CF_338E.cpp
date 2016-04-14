#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int a[150010],b[150010],minv[600010],addv[600010],L,R,addt;
int n,m,h;
void Build(int o,int l,int r)
{
	//printf("%d %d %d\n",o,l,r);
	if(l==r)
	{
		minv[o]=m-l;
		if(r==m)
			minv[o]=0;
		return;
	}
	Build(o<<1,l,(l+r)>>1);
	Build(o<<1|1,((l+r)>>1)+1,r);
	minv[o]=min(minv[o<<1],minv[o<<1|1]);
}
void Add(int o,int l,int r)
{
	if(L<=l&&R>=r)
	{
		addv[o]+=addt;
		minv[o]+=addt;
	}
	else
	{
		int mid=(l+r)>>1;
		if(L<=mid )Add(o<<1,l,mid);
		if(R>mid)Add(o<<1|1,mid+1,r);
		minv[o]=min(minv[o<<1],minv[o<<1|1]);
		minv[o]+=addv[o];
	}
}
void print()
{
	printf("%d\n  %d\n    %d\n    %d\n  %d\n",minv[1],minv[2],minv[4],minv[5],minv[3]);
}
int main()
{
	int ans=0;
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1; i<=m; i++)
		scanf("%d",&b[i]);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	sort(b+1,b+m+1);
	m++;
	Build(1,1,m);
	for(int i=1; i<m; i++)
	{
		int k=lower_bound(b+1,b+m,h-a[i])-b;
		//printf("%d %d %d\n",i,k,minv[1]);
		addt=-1;L=1,R=k;
		Add(1,1,m);
		//print();
	}
	if(minv[1]>=0)
		ans++;
	for(int i=m; i<=n; i++)
	{
		int k=lower_bound(b+1,b+m,h-a[i-m+1])-b;
		addt=1,L=1,R=k;
		Add(1,1,m);
		//printf("%d %d %d\n",i-m+1,k,minv[1]);
		//print();
		k=lower_bound(b+1,b+m,h-a[i])-b;
		addt=-1;L=1,R=k;
		Add(1,1,m);
		if(minv[1]>=0)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}
