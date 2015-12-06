/*
ID: mayukun3
PROG: castle
LANG: C++
*/
#include <stdio.h>
#define up 2
#define down 8
#define left 1
#define right 4
struct G
{
	int p,walls;
}g[100][100];
struct ANS
{
	char dir;
	int x,y,s;
}ans;
bool vis[100][100]={0};
int room_num=0,n,m,S[3000]={0};
void extend(int x,int y)
{
	if(vis[x][y])return;
	G& t=g[x][y];
	vis[x][y]=true;
	t.p=room_num;
	S[room_num]++;
	if(!(t.walls&up))
		extend(x-1,y);
	if(!(t.walls&down))
		extend(x+1,y);
	if(!(t.walls&left))
		extend(x,y-1);
	if(!(t.walls&right))
		extend(x,y+1);
}
int main()
{
	ans.s=0;
	int max_s_before=0;
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++)
			scanf("%d",&g[i][j].walls);
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++)
			if(!vis[i][j])
			{
				room_num++;
				extend(i,j);
				max_s_before=max_s_before<S[room_num]?S[room_num]:max_s_before;
			}
	for(int j=1; j<=n; j++)
		for(int i=m; i>=1; i--)
		{
			//printf("%d %d :%d\n",i,j,S[g[i][j].p]);
			G& t=g[i][j];
			if(i!=1&&t.p!=g[i-1][j].p&&(t.walls&up)&&S[t.p]+S[g[i-1][j].p]>ans.s)
			{
				ans.s=S[t.p]+S[g[i-1][j].p];
				ans.dir='N';
				ans.x=i;
				ans.y=j;
			}
			if(j!=n&&t.p!=g[i][j+1].p&&(t.walls&right)&&S[t.p]+S[g[i][j+1].p]>ans.s)
			{
				ans.s=S[t.p]+S[g[i][j+1].p];
				ans.dir='E';
				ans.x=i;
				ans.y=j;
			}
		}
	printf("%d\n%d\n%d\n%d %d %c\n",room_num,max_s_before,ans.s,ans.x,ans.y,ans.dir);
}