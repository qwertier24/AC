#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;

const int n=4;
int ori,final,cur[4][4],dx[4]={0,0,-1,1},dy[4]={-1,1,0,0},vis[1<<20],dist[1<<16];
int check(int p,int xt,int yt,int x,int y){
  if(xt<0||xt>=4||yt<0||yt>=4)
     return -1;
  if(1&(p>>(xt*n+yt)))return -1;
  int pt=((1<<(x*n+y))|(1<<(xt*n+yt)))^p;
  if(vis[pt])return -1;
  else return pt;
}
int bfs(){
  queue<int> q;
  q.push(ori);
  vis[ori]=1;
  while(!q.empty()){
    int p=q.front();
    q.pop();
    if(p==final)return dist[p];
    Rep(i,n)Rep(j,n)cur[i][j]=1&(p>>(i*n+j));
    int pt;
    Rep(i,n)Rep(j,n)if(1&(p>>(i*n+j)))
      Rep(k,4)if((pt=check(p,i+dx[k],j+dy[k],i,j))!=-1){
	//print(p);
	//printf(" %d %d %d ",i*n+j,k,(i+dx[k])*n+j+dy[k]);
	////print(pt);
	//printf("\n");
	vis[pt]=1;
	dist[pt]=dist[p]+1;
	q.push(pt);
      }
  }
  return -1;
}
char s[10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  Rep(i,n){
    scanf("%s",s);
    Rep(j,n)ori|=((s[j]-'0')<<(i*n+j));
  }
  Rep(i,n){
    scanf("%s",s);
    Rep(j,n)final|=((s[j]-'0')<<(i*n+j));
  }
  printf("%d",bfs());
  return 0;
}
