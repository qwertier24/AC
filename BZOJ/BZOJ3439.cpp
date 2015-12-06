#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define SZ 300010
struct Node{
  Node *ch[2];
  int v,sz,r;
  inline void maintain(){
    sz=(ch[0]?ch[0]->sz:0)+(ch[1]?ch[1]->sz:0)+1;
  }
}node[SZ],*root[SZ];
int tot;

inline void rotate(Node* &o,int d){
  Node *k=o->ch[d];
  o->ch[d]=k->ch[!d];
  k->ch[!d]=o;
  o->maintain();
  k->maintain();
  o=k;
}
void insert(Node* &o,Node* &x){
  if(!o){
    o=x;
  }else{
    int d=o->v < x->v;
    insert(o->ch[d],x);
    if(o->ch[d]->r > o->r)
      rotate(o,d);
  }
  o->maintain();
}
void merge(Node* &src,Node* &dest){
  if(!src)return;
  merge(src->ch[0],dest);
  merge(src->ch[1],dest);
  src->ch[0]=src->ch[1]=0;
  src->sz=1;
  insert(dest,src);
}
int kth(Node* &o,int k){
  if(k<=0 || k>o->sz)return -1;
  int lsz=(o->ch[0]?o->ch[0]->sz:0);
  if(k==lsz+1)return o->v;
  if(k<=lsz)return kth(o->ch[0],k);
  return kth(o->ch[1],k-lsz-1);
}

vector<pair<int,int> > k[SZ];
int sz,ch[SZ][26],val[SZ];
int insert(char *s,int i){
  int u=0;
  while(*s){
    int c=*(s++)-'a';
    if(!ch[u][c])
      ch[u][c]=++sz;
    u=ch[u][c];
  }
  Node *tmp=&node[++tot];
  tmp->v=i;tmp->r=rand();
  insert(root[u],tmp);
  return u;
}
int ans[100010];
void dfs(int u){
  REP(i,0,25){
    if(ch[u][i]){
      int &v=ch[u][i];
      dfs(v);
      merge(root[v],root[u]);
    }
  }
  REP(i,0,int(k[u].size())-1){
    ans[k[u][i].first]=kth(root[u],k[u][i].second);
  }
}

int n,pos[100010],kt;
char str[SZ];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n){
    scanf("%s",str);
    reverse(str,str+strlen(str));
    pos[i]=insert(str,i);
  }
  REP(i,1,n){
    scanf("%d",&kt);
    k[pos[i]].push_back(make_pair(i,kt));
  }
  dfs(0);
  REP(i,1,n)printf("%d\n",ans[i]);
  return 0;
}
