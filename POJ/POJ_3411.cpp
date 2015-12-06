#include <stdio.h>
#include <string>
#include <map>
#include <queue>
#include <cstring>
#include <vector>
#define MOD 101
using namespace std;
int c,A,B;
char options[6][10]={"FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"};
int vis[20000],fa[20000],step[20000];
struct QUEUE
{
	int qu[20000],fp,rear;
	QUEUE(){fp=0,rear=-1;}
	void pop()
	{
		fp++;
	}
	void push(int t)
	{
		qu[++rear]=t;
	}
	int front()
	{
		return qu[fp];
	}
	bool empty()
	{
		return fp>rear;
	}
};
void Modify(int& a,int& b,int option)
{
	if(option==0)a=A;
	else if(option==1)b=B;
	else if(option==2)a=0;
	else if(option==3)b=0;
	else if(option==4){int t=a;a=max(a-(B-b),0),b=min(B,b+t);}
	else {int t=a;a=min(A,a+b),b=max(b-(A-t),0);}
}
int bfs(int p0)
{
	QUEUE q;
	memset(vis,0,sizeof(vis));
	vis[p0]=1;
	step[p0]=-1;
	fa[p0]=-1;
	q.push(p0);
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		//printf("%d %d\n",p/MOD,p%MOD);
		if(p/MOD==c||p%MOD==c)
		{
			return p;
			break;
		}
		for(int i=0; i<6; i++)
		{
			int a=p/MOD,b=p%MOD;
			Modify(a,b,i);
			//printf("  %d %d %d\n",a,b,i);
			if(!vis[a*MOD+b])
			{
				vis[a*MOD+b]=1;
				q.push(a*MOD+b);
				step[a*MOD+b]=i;
				fa[a*MOD+b]=p;
			}
		}
	}
	return -1;
}
int main()
{
	scanf("%d%d%d",&A,&B,&c);
	int endpos=bfs(0);
	vector<int> ans;
	if(endpos!=-1)
	{
		while(fa[endpos]!=-1)
		{
			ans.push_back(step[endpos]);
			endpos=fa[endpos];
		}
		printf("%d\n",ans.size());
		for(int i=ans.size()-1; i>=0; i--)
			printf("%s\n",options[ans[i]]);
	}
	else
		printf("impossible\n");
	return 0;
}
