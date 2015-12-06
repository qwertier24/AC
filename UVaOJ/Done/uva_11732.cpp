#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<ctype.h>
#define MAXNODE 4000000

using namespace std;

long long ans;

inline int idx(char c){
  if(islower(c))return c-'a';
  else if(isupper(c))return c-'A'+26;
  else return c-'0'+52;
}
struct Node{
  int son,bro,val,chr,sum;
  void init(){
    son=val=sum=bro=0;
    chr=-1;
  }
}node[MAXNODE<<1];
int cnt=0;
void insert(char* s){
  int u=0;
  node[u].sum++;
  while(*s){
    int c=idx(*s),t=node[u].son;
    while(node[t].chr!=c){
      if(t==0){
	cnt++;
	node[cnt].init();
	node[cnt].bro=node[u].son;
	node[u].son=cnt;
	node[cnt].chr=c;
	t=cnt;
      }else
	t=node[t].bro;
    }
    node[t].sum++;
    u=t;
    s++;
  }
  node[u].val++;
}
void calc(int u,long long dep){
  int t=node[u].son;
  long long ret=0;
  ans+=node[u].val*dep*((long long)node[u].val-1);
  ret+=node[u].val*(node[u].sum-node[u].val)*(dep*2-1);
  while(t){
    ret+=(node[u].sum-node[t].sum)*(dep*2-1)*(long long)node[t].sum;
    calc(t,dep+1);
    t=node[t].bro;
  }
  ret/=2;
  //printf("%d %c %d %d %I64d %I64d\n",u,node[u].chr+'a',node[u].val,node[u].sum,dep,ret);
  ans+=ret;
}

int n;
char s[1010];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  int kase=1;
  while(scanf("%d",&n)&&n){
    cnt=0;
    ans=0;
    node[0].init();
    for(int i=1; i<=n; i++){
      scanf("%s",s);
      insert(s);
    }
    calc(0,1);
    printf("Case %d: %lld\n",kase++,ans);
  }
  return 0;
}
