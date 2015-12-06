#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<ctype.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1000010

typedef long long LL;
using namespace std;

void readint(int &x){
  x=0;
  char c=getchar();
  while(!isdigit(c))c=getchar();
  while(isdigit(c)){
    x=x*10+c-'0';
    c=getchar();
  }
}
int dig[20],cnt;
void writeint(int x){
  cnt=0;
  if(!x){puts("0");return;}
  while(x){
    dig[++cnt]=x%10;
    x/=10;
  }
  for(int i=cnt; i; --i)
    putchar(dig[i]+'0');
  puts("");
}


int n,m;

int pa[N];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}
void init(){
  For(i,n)pa[i]=i;
}
void unionset(int u,int v){
  if(findset(u)!=findset(v)){
    pa[pa[u]]=pa[v];
  }
}

int le[N],pe[N<<1],ev[N<<1],ecnt,ei[N<<1];
void addEdge(int u,int v,int idx){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ei[ecnt]=idx;
}

int lq[N],pq[N<<1],qv[N<<1],qcnt,qi[N<<1],ansLCA[N];
void addLCAQ(int u,int v,int id){
  qcnt++;
  pq[qcnt]=lq[u];
  lq[u]=qcnt;
  qv[qcnt]=v;
  qi[qcnt]=id;
}

int fa[N],preIdx[N];

int vis[N],dep[N];
void dfs(int u){
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa[u])continue;
    fa[v]=u;
    preIdx[v]=ei[i];
    dep[v]=dep[u]+1;
    dfs(v);
    unionset(v,u);
  }
  vis[u]=1;
  for(int i=lq[u]; i; i=pq[i]){
    int &v=qv[i];
    if(vis[v])
      ansLCA[qi[i]]=findset(v);
  }
}

int ld[N],pd[N],dcnt,de[N];
void addDel(int id,int d){
  dcnt++;
  pd[dcnt]=ld[id];
  ld[id]=dcnt;
  de[dcnt]=d;
}
int mark[N];
void del(int u,int a,int id){
  u=findset(u);
  while(dep[u]>dep[a]){
    mark[preIdx[u]]=1;
    addDel(id,u);
    unionset(u,fa[u]);
    u=findset(u);
  }
}
void color(int id){
  for(int i=ld[id]; i; i=pd[i])
    unionset(de[i],fa[de[i]]);
}
void dfs2(int u){
  vis[u]=1;
  for(int i=le[u]; i; i=pe[i]){
    if(ev[i]==fa[u] || mark[ei[i]])continue;
    dfs2(ev[i]);
    unionset(ev[i],u);
  }
}

struct OPT{
  int u,v,type;
}opt[N];

int u,v,ans[N];
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  readint(n);readint(m);
  For(i,n-1){
    readint(u);readint(v);
    addEdge(u,v,i);
    addEdge(v,u,i);
  }
  For(i,m){
    readint(opt[i].type);
    if(opt[i].type==1){
      readint(opt[i].u);
    }else{
      readint(opt[i].u);readint(opt[i].v);
      addLCAQ(opt[i].u,opt[i].v,i);
      addLCAQ(opt[i].v,opt[i].u,i);
    }
  }

  init();
  dfs(1);

  init();
  For(i,m){
    if(opt[i].type==2){
      u=opt[i].u,v=opt[i].v;
      int &a=ansLCA[i];
      del(u,a,i);
      del(v,a,i);
    }
  }
  
  init();
  memset(vis,0,sizeof(vis));
  For(i,n)if(!vis[i])dfs2(i);
  for(int i=m; i; --i){
    u=opt[i].u,v=opt[i].v;
    if(opt[i].type==1){
      ans[i]=preIdx[findset(u)];
    }else{
      int &a=ansLCA[i];
      color(i);
    }
  }
  For(i,m)if(opt[i].type==1)writeint(ans[i]);
  return 0;
}
