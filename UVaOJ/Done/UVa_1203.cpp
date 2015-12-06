#include <stdio.h>
#include <queue>
using namespace std;
struct EVE
{
	int time,qnum,interval;
	bool operator < (const EVE& t) const
	{
		return time>t.time||(time==t.time && qnum>t.qnum);
	}
};
priority_queue<EVE> pq;
int main()
{
	char s[100];
	int t1,t2;
	EVE eve;
	while(scanf("%s",s)&&s[0]!='#')
	{
		scanf("%d%d",&t1,&t2);
		eve.time=t2;
		eve.qnum=t1;
		eve.interval=t2;
		pq.push(eve);
	}
	int k;
	scanf("%d",&k);
	while(k--)
	{
		EVE t=pq.top();
		printf("%d\n",t.qnum);
		pq.pop();
		t.time+=t.interval;
		pq.push(t);
	}
	return 0;
}
