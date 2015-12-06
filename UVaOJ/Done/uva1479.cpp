#include<stdio.h>
#include<algorithm>
#include<cstring>
#define N 20000
#define M 60000
#define Q 600000
#define INF (1<<29)
#define For(i,n) for(int i=1; i<=n; i++)
#define CLR(t) memset(t,0,sizeof(t))

using namespace std;

//UnionSet
int pa[N+10];
int findset(int x){
  if(x!=pa[x])
    pa[x]=findset(pa[x]);
  return pa[x];
}

//Treap
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
    return v<=x;
  }
}*null,*pNode[N+10];
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
  if(o->v==x){
    if(o->ch[0]!=null&&o->ch[1]!=null){
      int d=o->ch[0]->r<o->ch[1]->r;
      rotate(o,d);
      erase(o->ch[1^d]);
    }else{
      Node* t=o;
      if(o->ch[1]==null)o=o->ch[0];
      else o=o->ch[1];
      delete t;
    }
  }else
    erase(o->ch[o->cmp(x)]);
  o->maintain();  
}
void destroy(Node* &o){
  if(o==null)return;
  destroy(o->ch[0]);
  destroy(o->ch[1]);
  delete o;
  o=null;
}
int kth(Node* o,int k){
  if(o==null||k>o->s||k<=0)return 0;
  if(k<=o->ch[1]->s)return kth(o->ch[1],k);
  if(k<=o->ch[1]->s+1)return o->v;
  return kth(o->ch[0],k-o->ch[1]->s-1);
}
void print(Node* o){
  printf("node:%d %d\n",o->v,o->s);
  if(o->ch[0]!=null)print(o->ch[0]);
  if(o->ch[1]!=null)print(o->ch[1]);
}
void mergeto(Node* &src,Node* &dest){
  if(src==null)return;
  mergeto(src->ch[0],dest);
  mergeto(src->ch[1],dest);
  x=src->v;
  insert(dest);
  delete src;
  src=null;
}

void Union(int s1,int s2){
  int px=findset(s1),py=findset(s2);
  if(px==py)return;
  if(pNode[px]->s>pNode[py]->s)swap(px,py);
  mergeto(pNode[px],pNode[py]);
  pa[px]=py;
}

//Problem Details
struct OPT{
  char type;
  int x,y;
}opt[Q+10];
pair<int,int> e[M+10];
int w[N+10],n,m,q,del[M+10];
char t[10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  null=new Node();
  null->ch[0]=null->ch[1]=null;
  null->s=0;;
  null->r=-1;
  int kase=1;
  For(i,N)pNode[i]=null;
  while(scanf("%d%d",&n,&m)&&n+m){
    double ans=0;
    CLR(del);
    For(i,n){
      scanf("%d",&w[i]);
      pa[i]=i;
    }
    For(i,m)scanf("%d%d",&e[i].first,&e[i].second);
    q=0;
    while(scanf("%s",t)&&t[0]!='E'){
      ++q;
      opt[q].type=t[0];
      if(opt[q].type=='D'){
	scanf("%d",&opt[q].x);
	del[opt[q].x]=1;
      }else if(opt[q].type=='C'){
	scanf("%d%d",&opt[q].x,&opt[q].y);
	swap(opt[q].y,w[opt[q].x]);
      }else{
	scanf("%d%d",&opt[q].x,&opt[q].y);
      }
    }
    int qcnt=0;
    long long qsum=0;
    For(i,n){
      if(pNode[i]!=null)destroy(pNode[i]);
      pNode[i]=new Node(w[i],null);
      pNode[i]->maintain();
    }
    For(i,m)if(!del[i])Union(e[i].first,e[i].second);
    for(int i=q; i; i--){
      if(opt[i].type=='C'){
	x=w[opt[i].x];
	erase(pNode[findset(opt[i].x)]);
	x=w[opt[i].x]=opt[i].y;
	insert(pNode[findset(opt[i].x)]);
      }else if(opt[i].type=='D'){
	Union(e[opt[i].x].first,e[opt[i].x].second);
      }else{
	qcnt++;
	qsum+=kth(pNode[findset(opt[i].x)],opt[i].y);
      }
    }
    printf("Case %d: %.6lf\n",kase++,qsum/(double)qcnt);
  }
  return 0;
}
