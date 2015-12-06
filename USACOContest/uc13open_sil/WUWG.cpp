#include <stdio.h>
#include <algorithm>
#include <queue>
#define INF (1<<30)
#define For(i,b,e) for(int i=b; i<=e; ++i)
using namespace std;
int n,m;
char g[510][510];
int dist[510][510],vis[510][510],top[510][510],bottom[510][510];
struct Point{
	int x,y,g_dir;
	Point(int a,int b,int c):x(a),y(b),g_dir(c){}
};
queue<Point> q;
inline bool check(int x,int y){
	return x>=0&&y>=0&&x<n&&y<m&&g[x][y]!='#'&&!vis[x][y];
}
void dfs(int x,int y,int g_dir,int d){
	vis[x][y]=1;
	dist[x][y]=d;
	q.push(Point(x,y,g_dir));
	if(g_dir==-1){
		if(y>0&&check(bottom[x][y-1],y-1))
			dfs(bottom[x][y-1],y-1,g_dir,d);
		if(y<m-1&&check(bottom[x][y+1],y+1))
			dfs(bottom[x][y+1],y+1,g_dir,d);
	}else{
		if(y>0&&check(top[x][y-1],y-1))
			dfs(top[x][y-1],y-1,g_dir,d);
		if(y<m-1&&check(top[x][y+1],y+1))
			dfs(top[x][y+1],y+1,g_dir,d);
	}
}
int bfs(Point p0){
	q.push(p0);
	if(!check(p0.x,p0.y))return -1;
	dfs(p0.x,p0.y,-1,0);
	while(!q.empty()){
		Point cur=q.front();
		q.pop();
		int &x=cur.x,&y=cur.y;
		//printf("%d %d\n",x,y);
		if(g[x][y]=='D')
			return dist[x][y];
		if(check(top[x][y],y)){
			int xt=top[x][y],yt=y;
			dfs(xt,yt,-1*cur.g_dir,dist[x][y]+1);
		}
		if(check(bottom[x][y],y)){
			int xt=bottom[x][y],yt=y;
			dfs(xt,yt,-1*cur.g_dir,dist[x][y]+1);
		}
	}
	return -1;
}
int main(){
	freopen("gravity.in","r",stdin);
	freopen("gravity.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; ++i){
		scanf("%s",g[i]);
		//printf("%s\n",g[i]);
	}
	for(int i=0; i<m; i++){
		if(g[0][i]!='#')
			top[0][i]=INF;
		if(g[0][i]=='D')
			top[0][i]=0;
		if(g[n-1][i]!='#')
			bottom[n-1][i]=INF;
		if(g[n-1][i]=='D')
			bottom[n-1][i]=n-1;
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(g[i][j]=='#')
				top[i][j]=bottom[i][j]=INF;
	for(int i=1; i<n; ++i)
		for(int j=0; j<m; j++)
			if(g[i][j]!='#'){
				if(g[i-1][j]!='#')
					top[i][j]=top[i-1][j];
				else 
					top[i][j]=i;
				if(g[i][j]=='D')
					top[i][j]=i;
				//printf("%d %d %d %d\n",i,j,top[i][j],g[i-1][j]=='.');
			}
	for(int i=n-2; i>=0; --i)
		for(int j=0; j<m; j++)
			if(g[i][j]!='#'){
				if(g[i+1][j]!='#')
					bottom[i][j]=bottom[i+1][j];
				else
					bottom[i][j]=i;
				if(g[i][j]=='D')
					bottom[i][j]=i;
				//printf("%d %d %d\n",i,j,bottom[i][j]);
			}
	For(i,0,n-1)
		For(j,0,m-1)
			if(g[i][j]=='C'){
				printf("%d",bfs(Point(bottom[i][j],j,-1)));
				break;
			}
	return 0;
}
