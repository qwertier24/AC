#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define gcd __gcd

struct Node{
  int x,y,d;
  bool operator<(const Node& r)const{
    return d>r.d;
  }
  Node(int _x,int _y,int _d):x(_x),y(_y),d(_d){}
};

#define N 1000

int w[N][N];

#define check(x,y) ((x)<N && (x)>=0 && (y)<N && (y)>=0)
#define xt (x+dx[i])
#define yt (y+dy[i])
int dist[N][N],dx[4]={0,0,-1,1},dy[4]={-1,1,0,0},vis[N][N];
void DIJ(){
  priority_queue<Node> pq;
  memset(dist,0x3f,sizeof(dist));
  dist[0][0]=w[0][0];
  pq.push(Node(0,0,dist[0][0]));
  while(!pq.empty()){
    int x=pq.top().x,y=pq.top().y;
    pq.pop();
    if(vis[x][y])continue;
    vis[x][y]=1;
    REP(i,0,3){
      if(check(xt,yt) && dist[xt][yt]>dist[x][y]+w[xt][yt]){
        dist[xt][yt]=dist[x][y]+w[xt][yt];
        pq.push(Node(xt,yt,dist[xt][yt]));
      }
    }
  }
}

int n,m;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  REP(i,0,N-1)REP(j,0,N-1)
    w[i][j]=gcd(i+1,j+1);
  DIJ();
  int T;
  scanf("%d",&T);
  while(T--){
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d\n",dist[n-1][m-1]);
  }
  return 0;
}
