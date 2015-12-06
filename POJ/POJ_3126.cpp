#include <stdio.h>
#include <queue>
#include <cstring>
#define MAXN 10000
using namespace std;
int gn[5]={0,1,10,100,1000},vis[10000],d[10000],s,e,prime[10000];
void get_prime()
{
	memset(prime,-1,sizeof(prime));
	prime[1]=0;
	for(int i=2; i*i<=MAXN; i++)
		if(prime[i])
			for(int j=i+i; j<=MAXN; j+=i)
				prime[j]=0;
}
bool check(int p)
{
	if(prime[p]&&!vis[p])
		return true;
	else
		return false;
}
void bfs(int p0)
{
	queue<int> q;
	memset(vis,0,sizeof(vis));
	d[p0]=0;
	vis[p0]=1;
	q.push(p0);
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		//printf("%d\n",p);
		for(int i=1; i<10; i++)
		{
			if(i!=p/gn[4]&&check(i*gn[4]+p%gn[4]))
			{
				int pt=i*gn[4]+p%gn[4];
				q.push(pt);
				vis[pt]=1;
				d[pt]=d[p]+1;
			}
		}
		for(int i=1; i<=3; i++)
		{
			for(int j=0; j<10; j++)
			{
				int pt=p-((p/gn[i])%10)*gn[i]+j*gn[i];
				//if(p==1033&&i==3)
				//	printf("%d %d\n",pt,check(pt));
				if(j!=(p/gn[i])%10&&check(pt))
				{
					int pt=p-((p/gn[i])%10)*gn[i]+j*gn[i];
					q.push(pt);
					vis[pt]=1;
					d[pt]=d[p]+1;
				}
			}
		}
	}
}
int main()
{
	get_prime();
	//for(int i=1; i<10; i++)
	//	printf("%d %d\n",i*1000+33,prime[i*1000+33]);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&s,&e);
		bfs(s);
		int t=d[e];
		printf("%d\n",t);
	}
	return 0;
}
