#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;
char str[100];
int n,sett,L,R,sumv[4000000],setv[4000000],pirate[2000000],rev[4000000];
inline int trans(int sum,int total_cnt,int inv)
{
	if(inv)
		return total_cnt-sum;
	else
		return sum;
}
void Build(int o,int l,int r)
{
	if(l==r)
	{
		sumv[o]=pirate[l];
		setv[o]=pirate[l];
		return;
	}
	int m=(l+r)>>1;
	Build(o<<1,l,m);
	Build(o<<1|1,m+1,r);
	sumv[o]=sumv[o<<1]+sumv[o<<1|1];
	//printf(" %d %d %d %d\n",o,l,r,sumv[o]);
}
void maintain(int o,int l,int r)
{
	if(setv[o]!=-1)
		sumv[o]=setv[o]*(r-l+1);
	else if(l!=r)
		sumv[o]=sumv[o<<1]+sumv[o<<1|1];
	sumv[o]=trans(sumv[o],r-l+1,rev[o]);
}
void pushdown(int o)
{
	int lc=o<<1,rc=o<<1|1;
	if(setv[o]!=-1)
	{
		setv[lc]=setv[rc]=setv[o];
		rev[lc]=rev[rc]=rev[o];
		setv[o]=-1;
		rev[o]=0;
	}
	else
	{
		rev[lc]^=rev[o];
		rev[rc]^=rev[o];
		rev[o]=0;
	}
}
void reverse(int o,int l,int r)
{
	if(L<=l&&R>=r)
		rev[o]^=1;
	else
	{
		pushdown(o);
		int m=(l+r)>>1;
		if(L<=m)
			reverse(o<<1,l,m);
		else
			maintain(o<<1,l,m);
		if(R>m)
			reverse(o<<1|1,m+1,r);
		else
			maintain(o<<1|1,m+1,r);
	}
	maintain(o,l,r);
	//printf("%d %d sum:%d set:%d rev:%d\n",l,r,sumv[o],setv[o],rev[o]);
}
void set(int o,int l,int r)
{
	//printf("%d %d %d\n",o,l,r);
	if(L<=l&&r<=R)
	{
		setv[o]=sett;
		rev[o]=0;
	}
	else
	{
		int m=(l+r)>>1;
		pushdown(o);
		if(L<=m)
			set(o<<1,l,m);
		else
			maintain(o<<1,l,m);
		if(R>m)
			set(o<<1|1,m+1,r);
		else
			maintain(o<<1|1,m+1,r);
	}
	maintain(o,l,r);
}
int query(int o,int l,int r,int inv)
{
	//printf("%d %d sum:%d set:%d rev:%d\n",l,r,sumv[o],setv[o],rev[o]);
	if(setv[o]!=-1)
		return trans(setv[o]*(min(R,r)-max(l,L)+1),min(R,r)-max(l,L)+1,inv^rev[o]);
	if(L<=l&&r<=R)
	{
		//printf("%d %d %d %d\n",o,l,r,trans(sumv[o],r-l+1,inv));
		return trans(sumv[o],r-l+1,inv);
	}
	int ret=0,m=(l+r)>>1;
	if(L<=m)
		ret+=query(o<<1,l,m,inv^rev[o]);
	if(R>m)
		ret+=query(o<<1|1,m+1,r,inv^rev[o]);
	return ret;
}
void print(int o,int l,int r)
{
	printf("  %d %d %d sum:%d set:%d %d\n",o,l,r,sumv[o],setv[o],rev[o]);
	if(l!=r)
	{
		int m=(l+r)>>1;
		print(o<<1,l,m);
		print(o<<1|1,m+1,r);
	}
}
int main()
{
	int T,kase=1;
	scanf("%d",&T);
	while(T--)
	{
		n=0;
		int m,qcnt=0;
		scanf("%d",&m);
		while(m--)
		{
			int t;
			scanf("%d%s",&t,str);
			int len=strlen(str);
			for(int j=1; j<=t; j++)
			{
				for(int i=0; i<len; i++)
				{
					pirate[n+i]=str[i]-'0';
				}
				n+=len;
			}
		}
		memset(setv,-1,sizeof(setv));
		memset(rev,0,sizeof(rev));
		Build(1,0,n-1);
		scanf("%d",&m);
		printf("Case %d:\n",kase++);
		for(int i=1; i<=m; i++)
		{
			scanf("%s%d%d",str,&L,&R);
			if(str[0]=='F')
			{
				sett=1;
				set(1,0,n-1);
				//print(1,0,n-1);
			}
			else if(str[0]=='E')
			{
				sett=0;
				set(1,0,n-1);
			}
			else if(str[0]=='I')
				reverse(1,0,n-1);
			else
				printf("Q%d: %d\n",++qcnt,query(1,0,n-1,0));
		}
	}
	return 0;
}
