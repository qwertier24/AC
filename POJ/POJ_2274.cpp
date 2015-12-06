#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#define INF 1e30
#define MOD 1000000
#define JUDGE 0
using namespace std;
int val[400]={0},n;
inline int lowbit(int x)
{
	return x&(-x);
}
void add(int x)
{
	while(x<=100)
	{
		val[x]++;
		x+=lowbit(x);
	}
}
int sum(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=val[x];
		x-=lowbit(x);
	}
	return ret;
}
struct CAR
{
	int front,back,p;
	double t,x,v;
	bool operator<(const CAR& rhs)const
	{
		return t>rhs.t||(t==rhs.t&&x+t*v>rhs.x+rhs.t*rhs.v);
	}
}car[250010];
void update(CAR& s)
{
	if(s.front==n+1)
		s.t=INF;
	else if(car[s.front].v>=s.v)
		s.t=INF;
	else
		s.t=(car[s.front].x-s.x)/(s.v-car[s.front].v);
}
void change(CAR& s,CAR& t)
{
	int back=s.back,front=t.p,now=s.p,front_front=t.front;
	car[front_front].back=now;
	car[back].front=t.p;
	car[now].front=front_front;
	car[now].back=front;
	car[front].back=back;
	car[front].front=now;
	update(car[now]);
	update(car[front]);
	update(car[front_front]);
	update(car[back]);
}
int main()
{
	if(JUDGE){
		freopen("therace.in","r",stdin);
		freopen("therace.out","w",stdout);
	}
	scanf("%d",&n);
	int ans=0;
	for(int i=1; i<=n; i++){
		scanf("%lf%lf",&car[i].x,&car[i].v);
	}
	for(int i=n; i>=1; i--)
	{
		if(car[i].v>0)
			ans=(ans+sum((int)car[i].v-1))%MOD;
		add((int)car[i].v);
	}
	priority_queue<CAR> pq;
	printf("%d\n",ans);
	car[n+1].v=INF;
	car[n+1].back=n;
	car[n+1].p=n+1;
	car[0].front=1;
	car[0].p=0;
	for(int i=1; i<=n; i++)
	{
		car[i].front=i+1;
		car[i].back=i-1;
		car[i].p=i;
		update(car[i]);
		pq.push(car[i]);
	}
	for(int i=1; i<=min(10000,ans); i++)
	{
		int now=pq.top().p,front=pq.top().front;
		int back=car[now].back;
		pq.pop();
		int front_front=car[front].front;
		if(car[now].front!=front||car[front].back!=now)
		{
			i--;
			continue;
		}
		printf("%d %d\n",now,front,car[now].t);
		change(car[now],car[front]);
		if(car[now].t<INF)
		{
			pq.push(car[now]);
		}
		if(back!=0&&car[back].t<INF)
		{
			pq.push(car[back]);
		}
	}
	return 0;
}
