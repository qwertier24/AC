#include <stdio.h>
#include <cstring>
int addx[4]={0,1,0,-1},addy[4]={1,0,-1,0},n,m,vis[110][110],a,b;
struct ROBOT
{
	int x,y,dir;
}robots[110];
int Dir(char t)
{
	if(t=='N') return 0;
	else if(t=='E') return 1;
	else if(t=='S') return 2;
	else return 3;
}
void modify(int p,char opt)
{
	if(opt=='L') robots[p].dir=((robots[p].dir-1)%4+4)%4;
	else if(opt=='R') robots[p].dir=(robots[p].dir+1)%4;
	else robots[p].x+=addx[robots[p].dir],robots[p].y+=addy[robots[p].dir];
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&n,&m);
		memset(vis,-1,sizeof(vis));
		bool crashed=false;
		int ans_f,ans_t;
		for(int i=1; i<=a; i++)
			for(int j=1; j<=b; j++)
				vis[i][j]=0;
		for(int i=1; i<=n; i++)
		{
			char c;
			scanf("%d%d %c",&robots[i].x,&robots[i].y,&c);
			vis[robots[i].x][robots[i].y]=i;
			robots[i].dir=Dir(c);
		}
		for(int i=1; i<=m; i++)
		{
			char c;
			int p,repeat;
			scanf("%d %c %d",&p,&c,&repeat);
			if(!crashed)
				while(repeat--)
				{
					vis[robots[p].x][robots[p].y]=0;
					modify(p,c);
					//printf("%d %d %d %d %d\n",p,robots[p].x,robots[p].y,robots[p].dir,vis[robots[p].x][robots[p].y]);
					if(vis[robots[p].x][robots[p].y]&&vis[robots[p].x][robots[p].y]!=p)
					{
						crashed=true;
						ans_f=p;
						ans_t=vis[robots[p].x][robots[p].y];
						break;
					}
					vis[robots[p].x][robots[p].y]=p;
				}
		}
		if(crashed)
		{
			if(ans_t==-1)
				printf("Robot %d crashes into the wall\n",ans_f);
			else
				printf("Robot %d crashes into robot %d\n",ans_f,ans_t);
		}
		else
			printf("OK\n");
	}
	return 0;
}
