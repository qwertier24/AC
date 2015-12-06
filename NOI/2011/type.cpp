#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 100010
#define fi first
#define se second

int pos[N];

int cur,sz,ch[N][26],pa[N];
void build_trie(char *cmd){
  int u=0;
  while(*cmd){
    if(*cmd=='P')
      pos[++cur]=u;
    else if(*cmd=='B')
      u=pa[u];
    else{
      int c=(*cmd)-'a';
      if(!ch[u][c]){
        ch[u][c]=++sz;
        pa[sz]=u;
      }
      u=ch[u][c];
    }
    cmd++;
  }
}

int le[N],ev[N],pe[N],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

vector<pair<int,int> > q[N];
int fr,rr,que[N],fa[N];
void calc_fa(){
  fr=0,rr=-1;
  REP(i,0,25)if(ch[0][i]){
    que[++rr]=ch[0][i];
    addEdge(0,ch[0][i]);
  }
  while(fr<=rr){
    int r=que[fr++];
    REP(i,0,25){
      int u=ch[r][i];
      if(!u){
        ch[r][i]=ch[fa[r]][i];
        continue;
      }
      fa[u]=ch[fa[r]][i];
      addEdge(fa[u],u);
      que[++rr]=u;
    }
  }
}

int L[N],R[N],dfsn;
void dfs(int u){
  L[u]=++dfsn;
  for(int i=le[u]; i; i=pe[i])
    dfs(ev[i]);
  R[u]=dfsn;
}

#define lowbit(x) ((x)&(-(x)))
int val[N];
inline void add(int p,int v){
  while(p<=dfsn){
    val[p]+=v;
    p+=lowbit(p);
  }
}
inline int sum(int p){
  int ret=0;
  while(p){
    ret+=val[p];
    p-=lowbit(p);
  }
  return ret;
}

int ans[N];
void solve(char *cmd){
  cur=0;
  int u=0;
  while(*cmd){
    if(*cmd=='P'){
      ++cur;
      REP(i,0,int(q[cur].size())-1){
        int &x=q[cur][i].fi;
        ans[q[cur][i].se]=sum(R[pos[x]])-sum(L[pos[x]]-1);
      }
    }else if(*cmd=='B'){
      add(L[u],-1);
      u=pa[u];
    }else{
      u=ch[u][*cmd-'a'];
      add(L[u],1);
    }
    cmd++;
  }
}

int m,x,y;
char str[100010];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%s",str);
  build_trie(str);
  calc_fa();
  dfs(0);
  scanf("%d",&m);
  REP(i,1,m){
    scanf("%d%d",&x,&y);
    q[y].push_back(make_pair(x,i));
  }
  solve(str);
  REP(i,1,m)printf("%d\n",ans[i]);
  return 0;
}
