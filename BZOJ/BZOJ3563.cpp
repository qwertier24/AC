#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<ctype.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 100010
#define M 500010

bool getint(char* &s,int &x){
  int flag=0;
  x=0;
  while(*s && !isdigit(*s))s++;
  while(*s && isdigit(*s)){
    flag=1;
    x=x*10+*(s++)-'0';
  }
  return flag;
}

int le[N],ev[M<<1],pe[M<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int vis[N],tot;
void dfs(int u){
  if(vis[u])return;
  vis[u]=1;
  tot++;
  for(int i=le[u]; i; i=pe[i])
    dfs(ev[i]);
}


char str[100010],*ps;
pair<int,int> e[M];
int n,m,ans[N],Q,k,del[20],cnt,mark[M],tmp;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  REP(i,1,m){
    while(fgets(str,sizeof(str),stdin),!getint(ps=str,tmp));
    ps=str;
    getint(ps,e[i].first);
    getint(ps,e[i].second);
  }
  scanf("%d",&Q);
  REP(i,1,Q){
    scanf("%d",&k);
    while(fgets(str,sizeof(str),stdin),!getint(ps=str,tmp));
    ps=str;
    cnt=0;
    while(getint(ps,del[cnt+1]))
      cnt++;
    ans[i-1]=cnt^k;
  }
  REP(i,1,Q-1)puts(ans[i]-ans[i-1]?"Connected":"Disconnected");
  REP(i,1,cnt)
    mark[del[i]^ans[Q-1]]=1;
  REP(i,1,m)if(!mark[i]){
    addEdge(e[i].first,e[i].second);
    addEdge(e[i].second,e[i].first);
  }
  dfs(5);
  puts(tot<n?"Disconnected":"Connected");
  return 0;
}
