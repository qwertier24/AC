/*
ID: mayukun3
PROG: maze1
LANG: C++
*/
#include <stdio.h>
#include <queue>
#include <map>
#include <string.h>
#define INF 10000000
using namespace std;
int outed[101][40]={0},w,h,vis[101][40]={0};
char g[201][80];
int addx[4]={-1,0,1,0},addy[4]={0,1,0,-1};
struct P
{
	int x,y;
	P(int a,int b):x(a),y(b){}
	P():x(0),y(0){}
	bool operator<(const P& t) const
	{
		return (x<t.x)||(x==t.x&&y<t.y);
	}
};
bool check(int x1,int y1,int x2,int y2)
{
	if(y2==0 || x2==0 || x2==h+1 || y2==w+1 || g[(2*x1-1+x2*2-1)/2][(y1*2-1+y2*2-1)/2]=='+' || g[(2*x1-1+x2*2-1)/2][(y1*2-1+y2*2-1)/2]=='-' || g[(2*x1-1+x2*2-1)/2][(y1*2-1+y2*2-1)/2]=='|' || vis[x2][y2])
		return false;
	return true;
}
void search(int x,int y)
{
	memset(vis,0,sizeof(vis));
	outed[x][y]=1;
	queue<P> q;
	map<P,P> father;
	q.push(P(x,y));
	vis[x][y]=1;
	outed[0][0]=1;
	father[P(x,y)].x=0;
	father[P(x,y)].y=0;
	while(!q.empty())
	{
		P t=q.front();
		outed[t.x][t.y]=min(outed[t.x][t.y],outed[father[t].x][father[t].y]+1);
		for(int i=0; i<4; i++)
			if(check(t.x,t.y,t.x+addx[i],t.y+addy[i]))
			{
				P c(t.x+addx[i],t.y+addy[i]);
				q.push(c);
				father[c].x=t.x;
				father[c].y=t.y;
				vis[c.x][c.y]=1;
			}
		q.pop();
	}
}
int main()
{
	freopen("maze1.in","r",stdin);freopen("maze1.out","w",stdout);
	int ans=0;
	scanf("%d%d",&w,&h);
	getchar();
	for(int i=0; i<=h*2; i++)
	{
		char s[1000];
		gets(s);
		for(int j=0; j<=w*2; j++)
		{
			g[i][j]=s[j];
			if(g[i][j]==' ')
			{
				if(j==w*2)
					outed[(i+1)/2][w]=1;
				if(j==0)
					outed[(i+1)/2][1]=1;
				if(i==0)
					outed[1][(j+1)/2]=1;
				if(i==h*2)
					outed[h][(j+1)/2]=1;
			}
		}
	}
	for(int i=1; i<=h; i++)
		for(int j=1; j<=w; j++)
			if(!outed[i][j])
				outed[i][j]=INF;
	for(int i=1; i<=h; i++)
		for(int j=1; j<=w; j++)
			if(outed[i][j]==1)
				search(i,j);
	for(int i=1; i<=h; i++)
		for(int j=1; j<=w; j++)
			ans=max(ans,outed[i][j]);
	printf("%d\n",ans);
	return 0;
}