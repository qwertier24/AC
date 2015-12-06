#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<string>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define MP make_pair
#define N 500009

using namespace std;

void readint(char *s,int &x){
  x=0;
  while(*s){
    x=x*10+*s-'0';
    s++;
  }
}
int dig[20],len;
void writeint(int x){
  len=0;
  while(x){
    dig[++len]=x%10;
    x/=10;
  }
  for(int i=len; i; --i)
    putchar(dig[i]+'0');
}
void readstr(char *s){
  len=0;
  char c=getchar();
  while(c!='+'&&c!='?'&&!isdigit(c)&&!isalpha(c))c=getchar();
  while(c=='+'||c=='?'||isdigit(c)||isalpha(c)){
    s[len++]=c;
    c=getchar();
  }
  s[len]=0;
}
void writestr(char *s){
  while(*s)putchar(*s++);
}

char name[N][20];
int score[N],ord[N],lh[N],ph[N],hcnt;
unsigned int hash(char *s){
  unsigned int ret=0;
  while(*s)ret=(*s++)+(ret<<6)+(ret<<16)-ret;
  return ret&0x7FFFFFFF;
}

struct Node{
  Node* ch[2];
  int r,s,sc,ord,idx;
  Node(int,int,int);
  inline void maintain(){
    s=ch[0]->s+ch[1]->s+1;
  }
  int cmp(int a,int b){
    if(sc==a&&ord==b)return -1;
    return sc>a||(sc==a&&ord<b);
  }
}*null,*root;
Node::Node(int a,int b,int c){
  this->sc=a;
  this->ord=b;
  this->idx=c;
  this->r=rand();
  this->s=1;
  ch[0]=ch[1]=null;
}
void rotate(Node* &o,int d){
  Node *k=o->ch[d];
  o->ch[d]=k->ch[1^d];
  k->ch[1^d]=o;
  o->maintain();
  k->maintain();
  o=k;
}
int xsc,xord;
void insert(Node* &o,int idx){
  if(o==null){
    o=new Node(xsc,xord,idx);
    return;
  }
  int d=o->cmp(xsc,xord);
  insert(o->ch[d],idx);
  if(o->r<o->ch[d]->r)
    rotate(o,d);
  o->maintain();
}
void erase(Node* &o){
  int d=o->cmp(xsc,xord);
  if(d==-1){
    if(o->ch[0]!=null&&o->ch[1]!=null){
      int d2=(o->ch[1]->r>o->ch[0]->r);
      rotate(o,d2);
      erase(o->ch[1^d2]);
    }else{
      Node *tmp=o;
      if(o->ch[0]==null)
    o=o->ch[1];
      else
    o=o->ch[0];
      delete tmp;
    }
  }else
    erase(o->ch[d]);
  if(o!=null)o->maintain();
}
int rank(Node* &o){
  int d=o->cmp(xsc,xord);
  if(d==-1)return o->ch[0]->s+1;
  return (o->ch[0]->s+1)*d+rank(o->ch[d]);
}
int L,R;
void print(Node* &o,int k){
  if(o==null)return;
  if(L<=k+o->ch[0]->s)print(o->ch[0],k);
  if(k+o->ch[0]->s+1==R)writestr(name[o->idx]);
  else if(L<=k+o->ch[0]->s+1&&k+o->ch[0]->s+1<R){writestr(name[o->idx]);putchar(' ');}
  if(R>k+o->ch[0]->s+1)print(o->ch[1],k+o->ch[0]->s+1);
}
void init(){
  null=new Node(-1,-1,0);
  null->r=-1;
  null->ch[0]=null->ch[1]=null;
  null->s=0;
  root=null;
}

int n;
char opt[20];
char numt[20];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  init();
  scanf("%d",&n);
  For(i,n){
    readstr(opt);
    if(opt[0]=='+'){
      int h=hash(opt+1)%N;
      int idx=0;
      for(int j=lh[h]; j; j=ph[j])
    if(!strcmp(name[j],opt+1)){
      xsc=score[j];
      xord=ord[j];
      idx=j;
      break;
    }
      if(idx)
    erase(root);
      readstr(numt);
      readint(numt,xsc);
      xord=i;
      if(!idx){
	hcnt++;
	idx=hcnt;
	ph[hcnt]=lh[h];
	strcpy(name[hcnt],opt+1);
	lh[h]=hcnt;
      }
      score[idx]=xsc;
      ord[idx]=xord;
      insert(root,idx);
    }else{
      if(isdigit(opt[1])){
	readint(opt+1,L);
	R=min(L+9,root->s);
	print(root,0);
	putchar('\n');
      }else{
	int h=hash(opt+1)%N;
	int idx=0;
	for(int j=lh[h]; j; j=ph[j])
	  if(!strcmp(name[j],opt+1)){
	    xsc=score[j];
	    xord=ord[j];
	    idx=j;
	    break;
	  }
	writeint(rank(root));
	putchar('\n');
      }
    }
  }
  return 0;
}
