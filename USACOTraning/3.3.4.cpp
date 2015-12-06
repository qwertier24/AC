/*
ID: mayukun3
PROG: camelot
LANG: C++
*/
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int knights[30*26+1],king;
int dist[30*26][30*26],dist2[30*26][30*26],vis[30*26],m,n,kinghts_num=0,king_dist[30*26],in_queue[30*26];
int addx[8]={2,1,-1,-2,-2,-1,1,2},addy[8]={1,2,2,1,-1,-2,-2,-1};
void bfs(int p0)
{
	for(int i=0; i<n*m; i++)
		dist[p0][i]=dist2[p0][i]=1<<20;
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(p0);
	dist[p0][p0]=0;
	dist2[p0][p0]=king_dist[p0];
	vis[p0]=1;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		int x=p/m,y=p%m;
		for(int i=0; i<8; i++)
			if(x+addx[i]>=0&&x+addx[i]<n&&y+addy[i]>=0&&y+addy[i]<m&&!vis[(x+addx[i])*m+y+addy[i]])
			{
				q.push((x+addx[i])*m+y+addy[i]);
				dist[p0][(x+addx[i])*m+y+addy[i]]=dist[p0][p]+1;
				dist2[p0][(x+addx[i])*m+y+addy[i]]=dist[p0][(x+addx[i])*m+y+addy[i]]+king_dist[(x+addx[i])*m+y+addy[i]];
				vis[(x+addx[i])*m+y+addy[i]]=1;
			}
	}
	memset(in_queue,0,sizeof(in_queue));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			q.push(i*m+j);
	while(!q.empty())
	{
		int  p=q.front();
		int x=p/m,y=p%m;
		q.pop();
		in_queue[p]=0;
		for(int i=0; i<8; i++)
			if(x+addx[i]>=0&&x+addx[i]<n&&y+addy[i]>=0&&y+addy[i]<m&&dist2[p0][(x+addx[i])*m+y+addy[i]]>dist2[p0][p]+1)
			{
				int pt=(x+addx[i])*m+y+addy[i];
				if(!in_queue[pt])
					q.push(pt);
				in_queue[pt]=1;
				dist2[p0][pt]=dist2[p0][p]+1;
				q.push(pt);
			}
	}
}
int main()
{
	freopen("camelot.in","r",stdin);
	freopen("camelot.out","w",stdout);
	char t[5];
	int xt,yt;
	scanf("%d%d",&m,&n);
	scanf("%s %d",t,&yt);
	yt--;
	xt=t[0]-'A';
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			int p=i*m+j;
			king_dist[p]=min(abs(i-xt),abs(j-yt))+abs(abs(i-xt)-abs(j-yt));
		}
	while(scanf("%s %d",t,&yt)!=EOF)
	{
		knights[++kinghts_num]=(t[0]-'A')*m+yt-1;
	}
	for(int x=0; x<n; x++)
		for(int y=0; y<m; y++)
		{
			bfs(x*m+y);
		}
	//printf("%d\n",kinghts_num);
	int ans=1<<30;
	for(int x=0; x<n; x++)
		for(int y=0; y<m; y++)
		{
			int p=x*m+y,min_kdist=1<<30,cost=0;
			for(int i=1; i<=kinghts_num; i++)
			{
				min_kdist=min(min_kdist,dist2[knights[i]][p]-dist[knights[i]][p]);
				cost+=dist[knights[i]][p];
				//printf("%d %d %d %d\n",knights[i]/m,knights[i]%m,dist[knights[i]][p],dist2[knights[i]][p]);
			}
			if(ans>cost+min_kdist)
			{
				//printf("%d %d\n",x,y);
			ans=min(ans,cost+min_kdist);
			}
		}
	if(kinghts_num==0)
		printf("0\n");
	else
	printf("%d\n",ans);
	return 0;
}
