#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define N 500
#define M 500
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define INF 1<<30
#define PROB "ccski"

using namespace std;

typedef pair<int,int> Point;

int n,m,g[N+10][M+10],way[N+10][M+10];

int vis[N+10][M+10],dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
bool check(int x,int y,int res,int gap){
  return x>0&&y>0&&x<=n&&y<=m&&!vis[x][y]&&abs(g[x][y]-res)<=gap;
}
bool bfs(int x0,int y0,int gap){
  memset(vis,0,sizeof(vis));
  queue<Point> q;
  q.push(Point(x0,y0));
  while(!q.empty()){
    Point p=q.front();
    int x=p.first,y=p.second;
    q.pop();
    Rep(i,4)if(check(x+dx[i],y+dy[i],g[x][y],gap)){
      q.push(Point(x+dx[i],y+dy[i]));
      vis[x+dx[i]][y+dy[i]]=1;
    }
  }
  For(i,n)For(j,m)if(way[i][j]&&!vis[i][j])return false;
  return true;
}
int main(){
  freopen(PROB".in","r",stdin);
  freopen(PROB".out","w",stdout);
  scanf("%d%d",&n,&m);
  For(i,n)For(j,m)scanf("%d",&g[i][j]);
  int px=INF,py;
  For(i,n)For(j,m){
    scanf("%d",&way[i][j]);
    if(way[i][j])px=i,py=j;
  }
  if(px==INF){
    puts("0");
    return 0;
  }
  int l=0,r=int(1e9);
  while(l<r){
    int gap=(l+r)>>1;
    if(bfs(px,py,gap))r=gap;
    else l=gap+1;
  }
  printf("%d",l);
  return 0;
}
