#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int p,num_t,v[3000001],num[1000001];
int opt(int odd,int a,int b)
{
	if(odd)
		return a|b;
	else
		return a^b;
}
void BUILD(int o,int odd,int l,int r)
{
	if(l==r)
	{
		v[o]=num[l];
		return;
	}
	BUILD(o<<1,1^odd,l,(l+r)/2);
	BUILD(o<<1|1,1^odd,(l+r)/2+1,r);
	v[o]=opt(odd,v[o<<1],v[o<<1|1]);
}
void Modify(int o,int odd,int l,int r)
{
	//printf("%d %d %d\n",o,l,r);
	if(l==p&&r==p)
	{
		v[o]=num_t;
		return;
	}
	int m=(l+r)/2;
	if(p>m)
		Modify(o<<1|1,1^odd,m+1,r);
	else
		Modify(o<<1,1^odd,l,m);
	v[o]=opt(odd,v[o<<1],v[o<<1|1]);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=(1<<n); i++)
		scanf("%d",&num[i]);
	BUILD(1,n%2,1,1<<n);
	//printf(" %d\n",v[3]);
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d",&p,&num_t);
		Modify(1,n%2,1,1<<n);
		printf("%d\n",v[1]);
	}
	return 0;
}
