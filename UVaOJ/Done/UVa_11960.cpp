#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#define maxn 1000000
using namespace std;
struct QUERY
{
	int ord,query,ans;
}q[50010];
int is_prime[1000010];
long long fact[1000010]={0};
void Init()
{
	memset(is_prime,-1,sizeof(is_prime));
	for(int i=2; i*i<=maxn; i++)
		if(is_prime[i])
			for(int j=i*i; j<=maxn; j+=i)
				is_prime[j]=0;
	for(int i=2; i<=maxn; i++)
		for(int j=i; j<=maxn; j+=i)
				fact[j]++;
}
bool cmp1(const QUERY& a,const QUERY& b)
{
	return a.query<b.query;
}
bool cmp2(const QUERY& a,const QUERY& b)
{
	return a.ord<b.ord;
}
int main()
{
	int T,n,l=0;
	Init();
	//printf("%d\n",fact[36]);
	scanf("%d",&T);
	memset(q,0,sizeof(q));
	for(int i=1; i<=T; i++)
	{
		scanf("%d",&q[i].query);
		q[i].ord=i;
	}
	sort(q+1,q+T+1,cmp1);
	int ans=0;
	for(int i=1; i<=T; i++)
	{
		for(int j=l+1; j<=q[i].query; j++)
			if(fact[j]>=fact[ans])
				ans=j;
		l=q[i].query;
		q[i].ans=ans;
	}
	sort(q+1,q+T+1,cmp2);
	for(int i=1; i<=T; i++)
		printf("%d\n",q[i].ans);
	return 0;
}
