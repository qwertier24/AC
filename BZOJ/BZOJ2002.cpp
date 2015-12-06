#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 200010
 
using namespace std;
 
struct Node{
  int ch[2],fa,path_fa,sz;
  void maintain();
}nodes[N];
void Node::maintain(){
  sz=1+nodes[ch[0]].sz+nodes[ch[1]].sz;
}
 
void rotate(int o,int d){
  int k=nodes[o].ch[d];
  int k2=nodes[k].ch[1^d];
   
  nodes[k].path_fa=nodes[o].path_fa;
  nodes[o].path_fa=0;
 
  nodes[nodes[o].fa].ch[o==nodes[nodes[o].fa].ch[1]]=k;
  nodes[o].ch[d]=k2;
  nodes[k].ch[1^d]=o;
 
  nodes[k2].fa=o;
  nodes[k].fa=nodes[o].fa;
  nodes[o].fa=k;
   
  nodes[o].maintain();
  nodes[k].maintain();
}
 
void splay(int x){
  while(nodes[x].fa){
    int fa=nodes[x].fa,gfa=nodes[fa].fa;
    int d1=nodes[fa].ch[1]==x,d2=nodes[gfa].ch[1]==fa;
    //printf("splay:%d\n",x);
    if(!gfa){
      rotate(fa,d1);
      continue;
    }
    if(d1==d2){
      rotate(gfa,d2);
      rotate(fa,d1);
    }else{
      rotate(fa,d1);
      rotate(gfa,d2);
    }
  }
}
void access(int x){
  if(!x)return;
  splay(x);
  nodes[nodes[x].ch[1]].path_fa=x;
  nodes[nodes[x].ch[1]].fa=0;
  nodes[x].ch[1]=0;
  nodes[x].maintain();
  for(int y=nodes[x].path_fa; y; y=nodes[x].path_fa){
    splay(y);
    nodes[nodes[y].ch[1]].path_fa=y;
    nodes[nodes[y].ch[1]].fa=0;
    nodes[y].ch[1]=x;
    nodes[x].fa=y;
    nodes[x].path_fa=0;
    nodes[y].maintain();
    //printf("%d %d %d\n",x,y,nodes[y].sz);
    x=y;
  }
}
int getDep(int x){
  access(x);
  splay(x);
  return nodes[x].sz;
}
 
int pa[N],n,m,k,x,y,op;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d",&n);
  For(i,n){
    scanf("%d",&k);
    pa[i]=i+k>n?0:i+k;
    nodes[i].path_fa=pa[i];
    nodes[i].sz=1;
    //printf("%d path_fa: %d\n",i,nodes[i].path_fa);
  }
  scanf("%d",&m);
  while(m--){
    scanf("%d",&op);
    if(op==1){
      scanf("%d",&x);
      x++;
      printf("%d\n",getDep(x));
    }else{
      scanf("%d%d",&x,&y);
      x++;
      access(pa[x]);
      pa[x]=x+y>n?0:x+y;
      splay(x);
      nodes[x].path_fa=pa[x];
      nodes[x].fa=0;
    }
    /*
    For(i,n)printf("%d:fa:%d ch[0]:%d ch[1]:%d path_fa:%d sz:%d\n",i,nodes[i].fa,
                   nodes[i].ch[0],nodes[i].ch[1],nodes[i].path_fa,nodes[i].sz);
    */
  }
  return 0;
}
