#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 32100

int ch[N][26],sz;
void insert(char *s){
  int u=0;
  while(*s){
    int c=*(s++)-'A';
    if(!ch[u][c])ch[u][c]=++sz;
    u=ch[u][c];
  }
}

char str[32100];
int main(){
  freopen("trie.in","r",stdin);
  freopen("trie.out","w",stdout);
  while(scanf("%s",str)!=EOF){
    insert(str);
  }
  printf("%d\n",sz+1);
  return 0;
}
