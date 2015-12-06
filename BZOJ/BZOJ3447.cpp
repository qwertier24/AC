#include<stdio.h>
#include<algorithm>
#define INF (1<<30)
#define N 200010
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

typedef long long LL;
using namespace std;

struct Node{
  Node* ch[2];
  int mina,maxa,a,minus,dec,r,s;
  Node(int,int);
  inline int getmina(){
    if(r<0)return INF;
    return mina-dec;
  }
  inline int getmaxa(){
    if(r<0)return -INF;
    return maxa-dec;
  }
  inline int getminus(){
    return minus+dec;
  }
  inline int geta(){
    return a-dec;
  }
  inline void maintain(){
    if(r<0)return;
    s=ch[0]->s+ch[1]->s+1;
    mina=min(a,min(ch[0]->getmina(),ch[1]->getmina()));
    maxa=max(a,max(ch[0]->getmaxa(),ch[1]->getmaxa()));
  }
  inline void pushdown(){
    if(r<0)return;
    ch[0]->dec+=dec;
    ch[1]->dec+=dec;
    minus+=dec;
    mina-=dec;
    maxa-=dec;
    a-=dec;
    dec=0;
  }
}*null,*root;
Node::Node(int a,int b){
  this->a=a,this->minus=b;
  r=rand();
  ch[0]=ch[1]=null;
  mina=maxa=a;
  dec=0;
  s=1;
}
void rotate(Node* &o,int d){
  Node* k=o->ch[d];
  o->pushdown();
  k->pushdown();
  o->ch[d]=k->ch[1^d];
  k->ch[1^d]=o;
  o->maintain();
  k->maintain();
  o=k;
}
int x,y;
int find(Node* &o){
  //printf("find:%d %d %d\n",o->a,o->minus+o->a,o->ch[1]->getmina());
  o->pushdown();
  if(o->geta()<=x){
    if(o->ch[1]->getmina()>x)
      return o->getminus();
    else
      return find(o->ch[1]);
  }else
    return find(o->ch[0]);
}
void update(Node* &o){
  o->pushdown();
  if(o==null)return;
  if(o->getmaxa()<=x){
    o->dec++;
    return;
  }
  if(o->ch[1]->getmina()<=x)update(o->ch[1]);
  if(o->geta()<=x)o->a--,o->minus++;
  update(o->ch[0]);
}
bool modify(Node* &o){
  o->pushdown();
  bool ret;
  if(o->getmaxa()<x)return false;
  if(o->geta()>=x){
    if(o->ch[0]->getmaxa()<x){
      if(o->getminus()<=y){
	//printf("modify:%d %d %d\n",o->geta(),o->ch[0]->getmaxa(),x);
	if(o->ch[0]==null || o->ch[1]==null){
	  Node* k=o;
	  if(o->ch[0]==null)
	    o=o->ch[1];
	  else
	    o=o->ch[0];
	  delete k;
	}else{
	  int d=o->ch[0]->r<o->ch[1]->r;
	  rotate(o,d);
	  ret=modify(o->ch[1^d]);
	}
	ret=true;
      }else
	ret=false;
    }else
      ret=modify(o->ch[0]);
  }else
    ret=modify(o->ch[1]);
  o->maintain();
  return ret;
}
void insert(Node* &o){
  o->pushdown();
  if(o==null){
    o=new Node(x,y);
    return;
  }
  int d=o->geta()<x;
  insert(o->ch[d]);
  if(o->ch[d]->r > o->r)rotate(o,d);
  o->maintain();
}
void init(){
  null=new Node(0,0);
  null->r=-1;
  null->s=0;
  null->ch[0]=null->ch[1]=null;
  root=null;
}

int n,s[N],t[N],v[N],ans;
int main(){
#ifndef ONLINE_JUDGE
  freopen("boarding.in","r",stdin);
  freopen("boarding.out","w",stdout);
#endif 
  init();
  scanf("%d",&n);
  For(i,n)
    scanf("%d%d",&s[i],&t[i]);

  x=0,y=0;
  insert(root);

  for(int i=n; i; --i){
    x=s[i]-1;
    v[i]=find(root)+s[i]+t[i];
    ans=max(ans,v[i]);

    update(root);

    y=v[i]-x;
    while(modify(root));
    insert(root);
  }
  
  printf("%d",ans);
  return 0;
}
