#include <stdio.h>
#include <cstring>
#include<iostream>
using namespace std;
int d[300000],vis[300000],s,e;
struct QU
{
	int que[300000],fp,rp;
	QU(){fp=0,rp=-1;}
	void push(int t)
	{
		que[++rp]=t;
	}
	bool empty()
	{
		return fp>rp;
	}
	void pop()
	{
		fp++;
	}
	int front()
	{
		return que[fp];
	}
}q;
int bfs(int p0)
{
	q.push(p0);
	memset(vis,0,sizeof(vis));
	memset(d,0,sizeof(d));
	vis[p0]=1;
	d[p0]=0;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		//printf("%d %d\n",q.fp,q.rp);
		if(p==e)
		{
			return d[p];
		}
		if(p*2<=200000&&!vis[p*2])
		{
			q.push(p*2);
			vis[p*2]=1;
			d[p*2]=d[p]+1;
		}
		if(p+1<=200000&&!vis[p+1])
		{
			q.push(p+1);
			vis[p+1]=1;
			d[p+1]=d[p]+1;
		}
		if(p-1>=0&&!vis[p-1])
		{
			q.push(p-1);
			vis[p-1]=1;
			d[p-1]=d[p]+1;
		}
	}
}
int main()
{
	scanf("%d%d",&s,&e);
	cout<<bfs(s);
	return 0;
}
