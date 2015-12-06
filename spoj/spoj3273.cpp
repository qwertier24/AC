#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define INF ((int)(1e9)+1)

using namespace std;
struct Node{
  int v,r,s;
  Node* ch[2];
  inline void maintain(){
    if(r>-1)
      s=ch[0]->s+ch[1]->s+1;
  }
  Node(){}
  Node(int a,Node* b){
    ch[0]=ch[1]=b;
    s=0;
    v=a,r=rand();
  }
  inline int cmp(int x){
    return v<x;
  }
}*null,*root;
int x;
void rotate(Node* &o,int d){
  Node* k=o->ch[d];
  o->ch[d]=k->ch[1^d];
  k->ch[1^d]=o;
  o->maintain();
  k->maintain();
  o=k;
}
void insert(Node* &o){
  if(o->v==x)return;
  if(o==null)o=new Node(x,null);
  else{
    int d=o->cmp(x);
    insert(o->ch[d]);
    if(o->ch[d]->r>o->r)rotate(o,d);
  }
  o->maintain();
}
void erase(Node* &o){
  if(o==null)return;
  if(o->v==x){
    if(o->ch[1]==null){
      delete o;
      o=o->ch[0];
    }else if(o->ch[0]==null){
      delete o;
      o=o->ch[1];
    }else{
      int d=o->ch[0]->r<o->ch[1]->r;
      rotate(o,d);
      erase(o->ch[1^d]);
    }
  }else
    erase(o->ch[o->cmp(x)]);
  o->maintain();
}
int kth(Node* o,int k){
  if(o==null||k>o->s||k<=0)return INF;
  if(k==o->ch[1]->s+1)return o->v;
  if(k<=o->ch[1]->s)return kth(o->ch[1],k);
  return kth(o->ch[0],k-o->ch[1]->s-1);
}
int count(Node* o){
  if(o==null)return 0;
  if(o->v==x)return o->ch[0]->s;
  if(o->cmp(x))return count(o->ch[1])+o->ch[0]->s+1;
  return count(o->ch[0]);
}
void print(Node* o){
  if(o==null)return;
  printf("node:%d %d\n",o->v,o->s);
  print(o->ch[0]);
  print(o->ch[1]);
}

int n;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  null=new Node();
  null->ch[0]=null->ch[1]=null;
  null->r=-1;
  null->v=INF;
  root=null;
  scanf("%d",&n);
  char opt[10];
  For(i,n){
    scanf("%s%d",opt,&x);
    if(opt[0]=='I')insert(root);
    else if(opt[0]=='D')erase(root);
    else if(opt[0]=='K'){
      int t=kth(root,root->s-x+1);
      if(t==INF)printf("invalid\n");
      else printf("%d\n",t);
    }else{
      printf("%d\n",count(root));
    }
    //print(root);
  }
  return 0;
}
