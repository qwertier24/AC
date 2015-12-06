#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define R 50
#define C 50
#define N 15
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define PROB "island"

using namespace std;

const int INF=1<<29;

int r,c;

int n=0,mark[R+10][C+10],dx[5]={0,0,0,-1,1},dy[5]={0,-1,1,0,0},vis[R+10][C+10];
int dist[N+10][N+10];

char g[R+10][C+10];

bool check(int x,int y){
  return x>0&&x<=r&&y>0&&y<=c&&!vis[x][y];
}

void flood(int x,int y){
  mark[x][y]=n;
  vis[x][y]=1;
  //printf("%d %d %d\n",x,y,mark[x][y]);
  For(i,4)if(check(x+dx[i],y+dy[i])&&g[x+dx[i]][y+dy[i]]=='X'){
    flood(x+dx[i],y+dy[i]);
  }
}

int dt[R+10][C+10];
queue<pair<int,int> >q;
void dfs(int x,int y,int D){
  dt[x][y]=D;
  vis[x][y]=1;
  q.push(make_pair(x,y));
  For(i,4)if(check(x+dx[i],y+dy[i])&&g[x+dx[i]][y+dy[i]]=='X')
    dfs(x+dx[i],y+dy[i],D);
}
void bfs(int cur){
  memset(vis,0,sizeof(vis));
  For(i,r)For(j,c)if(mark[i][j]==cur){
    q.push(make_pair(i,j));
    dt[i][j]=0;
    vis[i][j]=1;
  }
  while(!q.empty()){
    int x=q.front().first,y=q.front().second;
    q.pop();
    //if(!cur)printf("cur:%d %d %d\n",x,y,dt[x][y]);
    For(i,4)if(check(x+dx[i],y+dy[i])&&g[x+dx[i]][y+dy[i]]!='.'){
      if(g[x+dx[i]][y+dy[i]]=='X'){
	dfs(x+dx[i],y+dy[i],dt[x][y]);
      }else{
	vis[x+dx[i]][y+dy[i]]=1;
	dt[x+dx[i]][y+dy[i]]=dt[x][y]+1;
	q.push(make_pair(x+dx[i],y+dy[i]));
      }
    }
  }
  For(i,r)For(j,c)
    if(mark[i][j]!=-1)dist[cur][mark[i][j]]=min(dist[cur][mark[i][j]],dt[i][j]);
}

int d[1<<16][N+10];
int main(){
#ifndef ONLINE_JUDGE
  //freopen("in","r",stdin);
#endif
  freopen(PROB".in","r",stdin);
  freopen(PROB".out","w",stdout);
  memset(mark,-1,sizeof(mark));
  scanf("%d%d",&r,&c);
  For(i,r)scanf("%s",g[i]+1);
  For(i,r)For(j,c)if(check(i,j)&&g[i][j]=='X'){
    flood(i,j);
    n++;
  }
  Rep(i,n)Rep(j,n)dist[i][j]=INF;
  For(i,r)For(j,c)if(mark[i][j]!=-1&&dist[mark[i][j]][mark[i][j]]!=-1){
    bfs(mark[i][j]);
  }
  //Rep(i,n)Rep(j,n)printf("dist:%d %d %d\n",i,j,dist[i][j]);
  Rep(S,(1<<n))Rep(i,n){
    d[S][i]=INF;
    if(1&(S>>i)){
      int S0=S^(1<<i);
      if(S0==0)d[S][i]=0;
      Rep(j,n)
	d[S][i]=min(d[S][i],d[S0][j]+dist[j][i]);
    }
    //printf("%o %d %d\n",S,i,d[S][i]);
  }
  int ans=INF;
  Rep(i,n)ans=min(ans,d[(1<<n)-1][i]);
  printf("%d",ans);
  return 0;
}
