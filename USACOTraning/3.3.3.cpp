/*
ID: mayukun3
PROG: shopping
LANG: C++
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct OFFER
{
	int num[1000],kinds[6],p;
}offer[1000];
int buying_kinds[6]={0},dp[10][10][10][10][10];
bool check(int a,int b,int c,int d,int e,int p)
{
	int t[1000]={0};
	t[buying_kinds[1]]=a;
	t[buying_kinds[2]]=b;
	t[buying_kinds[3]]=c;
	t[buying_kinds[4]]=d;
	t[buying_kinds[5]]=e;
	for(int i=1; i<=5; i++)
		if(t[offer[p].kinds[i]]<offer[p].num[offer[p].kinds[i]])
			return false;
	return true;
}
int main()
{
	int s,buying_count[6]={0},p[6]={0},n;
	memset(offer,0,sizeof(offer));
	freopen("shopping.in","r",stdin);freopen("shopping.out","w",stdout);
	scanf("%d",&s);
	for(int i=1; i<=s; i++)
	{
		int nt,ct,kt;
		scanf("%d",&nt);
		for(int j=1; j<=nt; j++)
		{
			scanf("%d%d",&ct,&kt);
			offer[i].kinds[j]=ct;
			offer[i].num[ct]=kt;
		}
		scanf("%d",&offer[i].p);
	}
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		int ct,kt,pt;
		scanf("%d%d%d",&buying_kinds[i],&buying_count[i],&p[i]);
	}
	for(int a=0; a<=buying_count[1]; a++)
		for(int b=0; b<=buying_count[2]; b++)
			for(int c=0; c<=buying_count[3]; c++)
				for(int d=0; d<=buying_count[4]; d++)
					for(int e=0; e<=buying_count[5]; e++)
					{
						dp[a][b][c][d][e]=a*p[1]+b*p[2]+c*p[3]+d*p[4]+e*p[5];
						for(int i=1; i<=s; i++)
							if(check(a,b,c,d,e,i))
								dp[a][b][c][d][e]=min(dp[a][b][c][d][e],dp[a-offer[i].num[buying_kinds[1]]][b-offer[i].num[buying_kinds[2]]][c-offer[i].num[buying_kinds[3]]][d-offer[i].num[buying_kinds[4]]][e-offer[i].num[buying_kinds[5]]]+offer[i].p);
					}
	printf("%d\n",dp[buying_count[1]][buying_count[2]][buying_count[3]][buying_count[4]][buying_count[5]]);
	return 0;
}