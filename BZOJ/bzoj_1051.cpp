#include<stdio.h>
#include<algorithm>
#include<ctype.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define N 10000
#define M 50000

using namespace std;

void readint(int &x){
  char c=getchar();
  x=0;
  while(!isdigit(c))c=getchar();
  while(isdigit(c)){
    x=x*10+c-'0';
    c=getchar();
  }
}
/*--------------------------------------------------*/
int laste[N+10],ecnt,ev[M+10],pree[M+10];
void addEdge(int u,int v){
  ecnt++;
  ev[ecnt]=v;
  pree[ecnt]=laste[u];
  laste[u]=ecnt;
}

int dfs_clock,pre[N+10],low[N+10],scc_no[N+10],scc_cnt,scc_size[N+10];
int stack[N+10],top;
void dfs(int u){
  pre[u]=low[u]=++dfs_clock;
  stack[++top]=u;
  for(int i=laste[u]; i; i=pree[i]){
    int v=ev[i];
    if(!pre[v]){
      dfs(v);
      low[u]=min(low[u],low[v]);
    }else if(!scc_no[v]){
      low[u]=min(low[u],pre[v]);
    }
  }
  if(low[u]==pre[u]){
    scc_cnt++;
    while(stack[top]!=u){
      scc_no[stack[top--]]=scc_cnt;
      scc_size[scc_cnt]++;
    }
    scc_no[stack[top--]]=scc_cnt;
    scc_size[scc_cnt]++;
  }
}

int n,m,u,v;
int in[N+10],out[N+10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  readint(n);
  readint(m);
  For(i,m){
    readint(u);
    readint(v);
    addEdge(u,v);
  }
  For(i,n)if(!pre[i])dfs(i);
  For(u,n){
    for(int i=laste[u]; i; i=pree[i])if(scc_no[u]!=scc_no[ev[i]]){
      out[scc_no[u]]=1;
      in[scc_no[ev[i]]]=1;
    }
  }
  int out0=0,ans;
  For(i,scc_cnt)if(!out[i]){
    out0++;
    ans=scc_size[i];
  }
  if(out0>1||out0==0)puts("0");
  else printf("%d",ans);
  return 0;
}
