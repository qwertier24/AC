#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <string.h>
#define INF 1<<20
#define maxnode 300000
using namespace std;
int num[100001],v,minv[maxnode],p,y1,y2,ans_min;
void BUILD(int o,int l,int r)
{
	if(l==r)
	{
		minv[o]=num[l];
		return;
	}
	int lc=o<<1,rc=o<<1|1,m=(l+r)/2;
	BUILD(lc,l,m);
	BUILD(rc,m+1,r);
	minv[o]=min(minv[lc],minv[rc]);
}
void set(int o,int l,int r)
{
	if(l==p&&r==p)
	{
		num[l]=v;
		minv[o]=v;
		return;
	}
	int m=(l+r)/2,lc=o<<1,rc=o<<1|1;
	if(p<=m)
		set(lc,l,m);
	else
		set(rc,m+1,r);
	minv[o]=min(minv[lc],minv[rc]);
}
void query(int o,int l,int r)
{
	if(y1<=l&&y2>=r)
		ans_min=min(ans_min,minv[o]);
	else
	{
		int m=(l+r)/2,lc=o<<1,rc=o<<1|1;
		if(y1<=m)query(lc,l,m);
		if(y2>m)query(rc,m+1,r);
	}
}
int main()
{
	int n,q;
	while(scanf("%d %d",&n,&q)!=EOF)
	{
		for(int i=1; i<=n; i++)
			scanf("%d",&num[i]);
		BUILD(1,1,n);
		for(int i=1; i<=q; i++)
		{
			char order[100];
			scanf("%s",order);
			if(order[0]=='s')
			{
				vector<int> shifts;
				int last_num=0;
				int len=strlen(order);
				for(int j=6; j<strlen(order); j++)
				{
					if(isdigit(order[j]))
						last_num=last_num*10+order[j]-'0';
					else
					{
						shifts.push_back(last_num);
						last_num=0;
					}
				}
				int change_to[30];
				change_to[shifts.size()-1]=num[shifts[0]];
				for(int j=0; j<shifts.size()-1; j++)
					change_to[j]=num[shifts[j+1]];
				for(int j=0; j<shifts.size(); j++)
				{
					p=shifts[j];
					v=change_to[j];
					set(1,1,n);
				}
			}
			else
			{
				sscanf(order,"query(%d,%d)",&y1,&y2);
				ans_min=INF;
				query(1,1,n);
				printf("%d\n",ans_min);
			}
		}
	}
	return 0;
}
