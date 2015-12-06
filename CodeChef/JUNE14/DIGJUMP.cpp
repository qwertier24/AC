#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
#define N 100010
vector<int> pos[10];

int n,mark[10],dist[N],vis[N],a[N];

int q[N],fr,rr;
void bfs(){
  q[fr=rr=0]=1;
  vis[1]=1;
  while(fr<=rr){
    int &u=q[fr++];
    if(!mark[a[u]]){
      mark[a[u]]=1;
      REP(i,pos[a[u]].size()){
        int v=pos[a[u]][i];
        if(vis[v])continue;
        vis[v]=1;
        q[++rr]=v;
        dist[v]=dist[u]+1;
      }
    }
    if(u>1 && !vis[u-1]){
      vis[u-1]=1;
      dist[u-1]=dist[u]+1;
      q[++rr]=u-1;
    }
    if(u<n && !vis[u+1]){
      vis[u+1]=1;
      dist[u+1]=dist[u]+1;
      q[++rr]=u+1;
    }
  }
}
char str[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%s",str+1);
  n=strlen(str+1);
  FOR(i,n){
    a[i]=str[i]-'0';
    pos[a[i]].push_back(i);
  }
  bfs();
  printf("%d",dist[n]);
  return 0;
}
