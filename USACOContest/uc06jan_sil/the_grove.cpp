#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
char g[60][60];
int da[3000],db[3000],vis[3000],addx[8]={-1,-1,-1,0,0,1,1,1},addy[8]={-1,0,1,-1,1,-1,0,1},n,m,dx,dy,sx,sy;
bool check(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m&&!vis[x*m+y]&&g[x][y]!='X';
}
void bfs1(int p0){
	memset(vis,0,sizeof(vis));
	memset(da,-1,sizeof(da));
	queue<int> q;
	q.push(p0);
	vis[p0]=1;
	da[p0]=0;
	while(!q.empty()){
		int p=q.front();
		q.pop();
		int x=p/m,y=p%m;
		//printf("%d %d\n",x,y);
		for(int i=0; i<8; i++){
			int xt=x+addx[i],yt=y+addy[i],pt=xt*m+yt;
			if(check(xt,yt)){
				if(g[xt][yt]=='Y'&&i>=0&&i<=2)
					continue;
				da[pt]=da[p]+1;
				vis[pt]=1;
				q.push(pt);
			}
		}
	}
}
void bfs2(int p0){
	memset(vis,0,sizeof(vis));
	memset(db,-1,sizeof(db));
	queue<int> q;
	q.push(p0);
	vis[p0]=1;
	db[p0]=0;
	while(!q.empty()){
		int p=q.front();
		q.pop();
		int x=p/m,y=p%m;
		//printf("%d %d\n",x,y);
		for(int i=0; i<8; i++){
			int xt=x+addx[i],yt=y+addy[i],pt=xt*m+yt;
			if(check(xt,yt)){
				if(g[xt][yt]=='Y'&&i>=5&&i<=7)
					continue;
				db[pt]=db[p]+1;
				vis[pt]=1;
				q.push(pt);
			}
		}
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
		scanf("%s",g[i]);
	int ans=1<<30;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(g[i][j]=='*')
				sx=i,sy=j;
	for(int i=0; i<n; i++){
		bool flag=false;
		for(int j=0; j<m; j++)
			if(g[i][j]=='X'){
				flag=true;
				dx=i,dy=j;
				for(int k=j-1; k>=0; k--)
					if(g[i][k]!='X')
						g[i][k]='Y';
				break;
			}
		if(flag)break;
	}
	bfs1(sx*m+sy);
	bfs2(sx*m+sy);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(g[i][j]=='Y')
				ans=min(ans,da[i*m+j]+db[i*m+j]);
	printf("%d",ans);
	return 0;
}
