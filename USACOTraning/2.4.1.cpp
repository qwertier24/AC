/*
ID: mayukun3
PROG: ttwo
LANG: C++
*/
#include <stdio.h>
int vis[4][11][11][4][11][11]={0},cnt=0,addx[4]={-1,0,1,0},addy[4]={0,1,0,-1},g[11][11];
struct P
{
	int x,y,dir;
}c,f;
bool check(int x,int y)
{
	if(x>10 || x<1 || y>10 || y<1 || g[x][y]=='*')
		return false;
	else
		return true;
}
int main()
{
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	for(int i=1; i<=10; i++)
	{
		char s[20];
		scanf("%s",s);
		for(int j=1; j<=10; j++)
		{
			g[i][j]=s[j-1];
			if(g[i][j]=='F')
				f.x=i,f.y=j;
			else if(g[i][j]=='C')
				c.x=i,c.y=j;
		}
	}
	f.dir=c.dir=0;
	while(true)
	{
		int x1,x2,y1,y2;
		//printf("%d %d %d %d %d %d\n",f.dir,f.x,f.y,c.dir,c.x,c.y);
		if(vis[f.dir][f.x][f.y][c.dir][c.x][c.y])
		{
			printf("0\n");
			return 0;
		}
		if(f.x==c.x&&f.y==c.y)
		{
			printf("%d\n",cnt);
			return 0;
		}
		vis[f.dir][f.x][f.y][c.dir][c.x][c.y]=1;
		if(check(f.x+addx[f.dir],f.y+addy[f.dir]))
		{
			f.x+=addx[f.dir];
			f.y+=addy[f.dir];
		}
		else
		{
			f.dir=(f.dir+1)%4;
		}
		if(check(c.x+addx[c.dir],c.y+addy[c.dir]))
		{
			c.x+=addx[c.dir];
			c.y+=addy[c.dir];
		}
		else
		{
			c.dir=(c.dir+1)%4;
		}
		cnt++;
	}
}