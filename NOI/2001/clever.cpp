#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define INF (1<<29)
#define dig(x,i) (((x)/p10[i])%10)

int p10[7]={1,10,100,1e3,1e4,1e5,1e6};

inline int swap0(int x,int i){
  int a=dig(x,5),b=dig(x,i);
  return x-a*p10[5]-b*p10[i]+b*p10[5]+a*p10[i];
}
inline int swap1(int x,int i){
  int a=dig(x,0),b=dig(x,i);
  return x-a*p10[0]-b*p10[i]+b*p10[0]+a*p10[i];
}
inline void update(int &x,int t){
  x=min(x,t);
}
#define MP make_pair
#define proc(x,y) \
  if(d[x][y]==-1){\
  d[x][y]=d[cur][pos]+1;\
  q.push(MP(x,y));\
  }

int st,ed;
int d[1000000][6];
int dp(){
  queue<pair<int,int> > q;
  memset(d,-1,sizeof(d));
  d[st][5]=0;
  q.push(MP(st,5));
  while(!q.empty()){
    int cur=q.front().first,pos=q.front().second;q.pop();
    if(cur==ed)return d[cur][pos];
    proc(swap0(cur,pos),pos);
    proc(swap1(cur,pos),pos);
    if(dig(cur,pos)<9)proc(cur+p10[pos],pos);
    if(dig(cur,pos)>0)proc(cur-p10[pos],pos);
    if(pos<5)proc(cur,pos+1);
    if(pos>0)proc(cur,pos-1);
  }
}
int main(){
  freopen("clever.in","r",stdin);
  freopen("clever.out","w",stdout);
  memset(d,-1,sizeof(d));
  scanf("%d%d",&st,&ed);
  printf("%d\n",dp());
  return 0;
}
