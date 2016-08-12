#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

int getint(){
  char ch = getchar();
  for ( ; ch > '9' || ch < '0'; ch = getchar());
  int tmp = 0;
  for ( ; '0' <= ch && ch <= '9'; ch = getchar())
    tmp = tmp * 10 + int(ch) - 48;
  return tmp;
} 

typedef unsigned int LL;
using namespace std;
#define N 100010
#define M 100010
#define seed 401u

vector<LL> sump[N];
vector<int> fact[N];
LL psd[N];

struct Node{
  int rev,cnt;
  char c;
  LL hsum,rhsum;
  Node ch[2],fa,pfa;
  void init(){rev=cnt=c=hsum=rhsum=ch[0]=ch[1]=fa=pfa=0;}
  inline void pushdown();
  inline void maintain();
  inline void change(int,int);
  inline void modify(char);
  inline void Rev();
}node[N+M];
inline void Node::Rev(){
  rev^=1;
  swap(ch[0],ch[1]);
  swap(hsum,rhsum);
}
inline void Node::modify(char c0){ //after pushdown
  hsum-=c*psd[node[ch[0]].cnt];
  hsum+=c0*psd[node[ch[0]].cnt];
  rhsum-=c*psd[node[ch[1]].cnt];
  rhsum+=c0*psd[node[ch[1]].cnt];
  c=c0;
}
inline void Node::pushdown(){
  if(rev){
    node[ch[0]].Rev();
    node[ch[1]].Rev();
    rev=0;
  }
}
inline void Node::maintain(){ //after pushdown
  cnt=node[ch[0]].cnt+node[ch[1]].cnt+(c>0);
  hsum=node[ch[0]].hsum*psd[cnt-node[ch[0]].cnt] + c*psd[node[ch[1]].cnt] + node[ch[1]].hsum;
  rhsum=node[ch[1]].rhsum*psd[cnt-node[ch[1]].cnt] + c*psd[node[ch[0]].cnt] + node[ch[0]].rhsum;
}
inline void Node::change(int v,int cur){ //after pushdown
  node[v].fa=node[ch[1]].pfa=cur;
  node[v].pfa=node[ch[1]].fa=0;
  ch[1]=v;
  maintain();
}
void rotate(int o,int d){
  int k=node[o].ch[d];
  node[o].ch[d]=node[k].ch[1^d];
  node[node[k].ch[1^d]].fa=o;

  int d2=node[node[o].fa].ch[1]==o;
  node[node[o].fa].ch[d2]=k;
  node[k].fa=node[o].fa;
  
  node[k].ch[1^d]=o;
  node[o].fa=k;
  node[o].maintain();
  node[k].maintain();
}
int top[N+M];
void splay(int cur){
  top[0]=0;
  while(cur){
    top[++top[0]]=cur;
    cur=node[cur].fa;
  }
  cur=top[1];
  if(top[0]>1){
    node[cur].pfa=node[top[top[0]]].pfa;
    node[top[top[0]]].pfa=0;
  }
  RREP(i,top[0],1)
    node[top[i]].pushdown();
  int fa,gfa,d1,d2;
  while(node[cur].fa){
    fa=node[cur].fa,gfa=node[fa].fa;
    d1=node[gfa].ch[1]==fa,d2=node[fa].ch[1]==cur;
    if(!gfa){
      rotate(fa,d2);
    }else{
      if(d1==d2){rotate(gfa,d1);rotate(fa,d2);}
      else{rotate(fa,d2);rotate(gfa,d1);}
    }
  }
  node[cur].pushdown();
}
void access(int u){
  for(int v=0; u; u=node[v].pfa){
    splay(u);
    node[u].change(v,u);
    v=u;
  }
}
void evert(int u){
  access(u);
  splay(u);
  node[u].Rev();
}
void link(int u,int v){
  evert(v);
  splay(v);
  access(u);
  splay(u);
  node[v].pfa=u;
}

LL get_hash(int v,int l){
  splay(v);
  if(l==node[v].cnt)
    return node[v].hsum;
  while(node[node[v].ch[0]].cnt!=l){
    node[v].pushdown();
    if(node[node[v].ch[0]].cnt<l){
      l-=node[node[v].ch[0]].cnt+(node[v].c>0);
      v=node[v].ch[1];
    }else{
      v=node[v].ch[0];
    }
  }
  splay(v);
  return node[node[v].ch[0]].hsum;
}

LL fPow(LL t,int p){
  LL ret=1;
  while(p){
    if(p&1)ret=ret*t;
    t=t*t;
    p>>=1;
  }
  return ret;
}
void init(){
  psd[0]=1;
  for(int i=1; i<=100000; i++){
    LL lst=0;
    for(int j=i; j<=100000; j+=i){
      fact[j].push_back(i);
      lst=lst+fPow(seed,j-i);
      sump[j].push_back(lst);
    }
    psd[i]=psd[i-1]*seed;
  }
}

int n,Q,mark[1000];
map<int,int> id[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  init();
  int T;
  scanf("%d",&T);
  while(T--){
    n=getint();
    
    REP(i,1,n+n-1)node[i].init();
    REP(i,1,n-1){
      int u,v;
      char c[3];
      //u=getint();
      //v=getint();
      scanf("%d%d",&u,&v);
      scanf("%s",c);
      id[u][v]=id[v][u]=i+n;
      node[i+n].modify(c[0]);
      node[i+n].cnt=1;
      node[i+n].maintain();
      link(i+n,u);
      link(v,i+n);
    }
    Q=getint();
    while(Q--){
      int op,u,v,len;
      LL full_hash;
      scanf("%d%d%d",&op,&u,&v);
      //op=getint();u=getint();v=getint();
      if(op==1){ //query
        evert(u);
        access(v);
        splay(v);
        full_hash=node[v].hsum;
        len=node[v].cnt;
        /*
        printf("%llu\n",full_hash);
        LL t='b'*psd[1]+'a'*psd[0];
        printf("t:%llu %llu\n",t,get_hash(v,fact[len][1])*sump[len][1]);
        printf("%llu %llu\n",1+seed*seed,sump[len][1]);
        */
        int ans=1<<30;
        RREP(i,int(fact[len].size())-2,0){
          RREP(j,int(fact[len].size())-2,i+1)
            if(mark[j] && fact[len][j]%fact[len][i]==0)
              continue;
          if(get_hash(v,fact[len][i])*sump[len][i]==full_hash)
            ans=fact[len][i];
          else
            mark[i]=1;
        }
        REP(i,0,fact[len].size()-1)
          mark[i]=0;
        if(ans==1<<30)
          ans=len;
        printf("%d\n",ans);
      }else{ //modify
        char c[3];
        scanf("%s",c);
        splay(id[u][v]);
        node[id[u][v]].modify(c[0]);
      }
    }
  }
  return 0;
}
