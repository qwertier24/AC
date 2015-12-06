/*
ID: mayukun3
PROG: humble
LANG: C++
*/
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
struct MULT
{
	long long num,now,last;
	MULT(long long a,long long b,long long c):num(a),now(b),last(c){};
	bool operator< (const MULT& rhs) const
	{
		return num>rhs.num;
	}
};
priority_queue<MULT> pq;
long long S[101];
int main()
{
	int n,p;
	freopen("humble.in","r",stdin);freopen("humble.out","w",stdout);
	scanf("%d%d",&n,&p);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&S[i]);
	}
	sort(S+1,S+n+1);
	for(int i=1; i<=n; i++)
	{
		pq.push(MULT(S[i],i,0));
	}
	for(int i=1; i<p; i++)
	{
		MULT t=pq.top();
		pq.pop();
		pq.push(MULT(t.num*S[1],1,t.now));
		if(t.now<t.last)
			pq.push(MULT(t.num/S[t.now]*S[t.now+1],t.now+1,t.last));
	}
	printf("%lld\n",pq.top().num);
	return 0;
}