#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 1010
#define M 6010

int le[N],ev[M],ed[M],pe[M],ecnt;
void addEdge(int u,int v,int d){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ed[ecnt]=d;
}

int n;

int q[N],fr,rr,inq[N],cnt[N],dist[N];
int spfa(){
  memset(dist,0x3f,sizeof(dist));
  dist[0]=0;
  REP(i,0,n){q[rr++]=i;inq[i]=1;cnt[i]=1;}
  while(fr!=rr){
    int u=q[fr++];
    inq[u]=0;
    if(fr==N)fr=0;
    for(int i=le[u]; i; i=pe[i]){
      int &v=ev[i];
      if(dist[v]>dist[u]+ed[i]){
        dist[v]=dist[u]+ed[i];
        if(!inq[v]){
          if(++cnt[v]>n)return 0;
          inq[v]=1;
          q[rr++]=v;
          if(rr==N)rr=0;
        }
      }
    }
  }
  return 1;
}

int a0,b0,l0,a1,b1,l1;
int main(){
  freopen("sequence.in","r",stdin);
  //freopen("sequence.out","w",stdout);
  scanf("%d%d%d%d%d%d%d",&n,&a0,&b0,&l0,&a1,&b1,&l1);
  REP(i,1,n){
    addEdge(i,i-1,0);
    addEdge(i-1,i,1);
    if(i-l1>=0){
      addEdge(i,i-l1,-a1);
      addEdge(i-l1,i,b1);
    }
    if(i-l0>=0){
      addEdge(i-l0,i,l0-a0);
      addEdge(i,i-l0,b0-l0);
    }
  }
  if(!spfa())puts("-1");
  else{
    REP(i,1,n)printf("%d",dist[i]-dist[i-1]);
  }
  return 0;
}
