#include<stdio.h>
#include<algorithm>
#include<cstring>
#define N 30000
#define For(i,n) for(int i=1; i<=n; i++)

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
  if(o==null)o=new Node(x,null);
  else{
    int d=o->cmp(x);
    insert(o->ch[d]);
    if(o->ch[d]->r>o->r)rotate(o,d);
  }
  o->maintain();
}
void erase(Node* &o){
  
  if(o->ch[0]==null&&o->ch[1]==null){
    delete o;
    o=null;
    return;
  }
  if(o->v==x)rotate(o,o->ch[0]->r<o->ch[1]->r);
  erase(o->ch[o->cmp(x)]);
  o->maintain();
  
  /*
    int d = o->cmp(x);  
    if (o->v==x)  
    {  
        Node* u = o;  
        if (o->ch[0] != null && o->ch[1] != null)  
        {  
            int d2 = o->ch[0] < o->ch[1] ? 1 : 0;  
            rotate(o, d2);  
            erase(o->ch[d2]);  
        }  
        else  
        {  
            if (o->ch[0] == null) o = o->ch[1];  
            else o = o->ch[0];  
  
            delete(u);  
        }  
    }  
    else erase(o->ch[d]);  
  
    if (o != null) o->maintain();  
  */
  
}
int kth(Node* o,int k){
  if(o==null||k>o->s||k<=0)return 0;
  if(k==o->ch[1]->s+1)return o->v;
  if(k<=o->ch[1]->s)return kth(o->ch[1],k);
  return kth(o->ch[0],k-o->ch[1]->s-1);
}

int add[N+10],query[N+10];
int n,m;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  null=new Node();
  null->ch[0]=null->ch[1]=null;
  null->r=-1;
  null->s=0;
  root=null;
  scanf("%d%d",&n,&m);
  For(i,n)scanf("%d",&add[i]);
  For(i,m)scanf("%d",&query[i]);
  int pq=1,j=0;
  For(i,n){
    x=add[i];
    insert(root);
    while(pq<=n&&query[pq]==i){
      j++;
      printf("%d\n",kth(root,root->s-j+1));
      pq++;
    }
  }
  return 0;
}
