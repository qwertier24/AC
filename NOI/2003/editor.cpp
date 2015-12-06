#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;
const int msz=20000,mbn=2048*1024/msz+100;
char cont[mbn+10][msz];
int sz[mbn+10],nxt[mbn+10];
int head=1;

inline void pr_str(char*,int);
int pool[mbn],top;
inline void init(){
  For(i,mbn)
    pool[++top]=i;
}
inline int newBlock(char *str,int size,int nt=0){
  int ret=pool[top];
  top--;
  memcpy(cont[ret],str,size);
  sz[ret]=size;
  nxt[ret]=nt;
  return ret;
}
inline void delBlock(int idx){
  pool[++top]=idx;
}
inline void unionBlock(int a,int b){
  nxt[a]=nxt[b];
  memcpy(cont[a]+sz[a],cont[b],sz[b]);
  sz[a]+=sz[b];
  delBlock(b);
}
inline int findPos(int &p){
  int cur=head;
  while(p>sz[cur]){
    p-=sz[cur];
    cur=nxt[cur];
  }
  return cur;
}
inline void split(int o,int k){
  int p2=newBlock(cont[o]+k,sz[o]-k,nxt[o]);
  sz[o]=k;
  nxt[o]=p2;
}
inline void maintain(){
  int cur=head;
  while(nxt[cur]){
    if(sz[cur]+sz[nxt[cur]]<=msz)
      unionBlock(cur,nxt[cur]);
    else
      cur=nxt[cur];
  }
}
inline void erase(int p,int len){
  int L=findPos(p);
  split(L,p);
  
  int R=nxt[L];
  while(len>sz[R]){
    len-=sz[R];
    R=nxt[R];
  }
  
  split(R,len);
  R=nxt[R];
  for(int i=nxt[L]; i!=R; i=nxt[i]){
    delBlock(i);
  }
  nxt[L]=R;
  maintain();
}
inline void insert(int p,char* str,int len){
  int L=findPos(p);
  split(L,p);
  int R=nxt[L];
  
  int lblk=L;
  while(len){
    int curlen=min(len,msz);
    nxt[lblk]=newBlock(str,curlen);
    lblk=nxt[lblk];
    str+=curlen;
    len-=curlen;
  }
  nxt[lblk]=R;
  maintain();
}
inline void pr_str(char *str,int len){
  while(len--)
    putchar(*str++);
}
inline void print(int p,int len){
  int cur=findPos(p);
  pr_str(cont[cur]+p,min(sz[cur]-p,len));
  len-=min(len,sz[cur]-p);
  cur=nxt[cur];
  while(len){
    int curlen=min(sz[cur],len);
    pr_str(cont[cur],curlen);
    len-=curlen;
    cur=nxt[cur];
  }
}

inline void get_str(char *str,int len){
  while(len){
    char c=getchar();
    if(32<=c && c<=126){
      len--;
      *str=c;
      str++;
    }
  }
}
int len,cursor,q;
char op[10],str[3000000];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
  freopen("out","w",stdout);
#endif
  init();
  scanf("%d",&q);
  while(q--){
    scanf("%s",op);
    switch(op[0]){
    case 'M':              //move the cursor
      scanf("%d",&cursor);
      break;
    case 'I':              //Insert
      scanf("%d",&len);
      get_str(str,len);
      insert(cursor,str,len);
      break;
    case 'D':              //Delete
      scanf("%d",&len);
      erase(cursor,len);
      break;
    case 'G':              //Get
      scanf("%d",&len);
      print(cursor,len);
      putchar('\n');
      break;
    case 'P':              //Prev
      cursor--;
      break;
    case 'N':              //Next
      cursor++;
      break;
    }
  }
  return 0;
}
