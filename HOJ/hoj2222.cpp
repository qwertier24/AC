#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#include<string>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 10000
#define M 50
#define SIGMA_SIZE 26

using namespace std;
typedef long long LL;

int sz,val[250000],fail[250000],prev[250000],ch[250000][26];
int idx(char c){
  return c-'a';
}
void init(){
  sz=0;
  memset(ch[0],0,sizeof(ch[0]));
}
void insert(char* s){
  int cur=0;
  while(*s){
    int c=idx(*s++);
    if(!ch[cur][c]){
      ch[cur][c]=++sz;
      memset(ch[sz],0,sizeof(ch[sz]));
      fail[sz]=prev[sz]=val[sz]=0;
    }
    cur=ch[cur][c];
  }
  val[cur]++;
}
void getfail(){
  queue<int> q;
  Rep(i,SIGMA_SIZE)
    if(ch[0][i]){
      int r=ch[0][i];
      fail[r]=0;
      q.push(r);
      prev[r]=0;
    }
  while(!q.empty()){
    int r=q.front();
    q.pop();
    Rep(c,SIGMA_SIZE){
      int u=ch[r][c];
      if(!u)continue;
      q.push(u);
      int v=fail[r];
      while(v&&!ch[v][c])v=fail[v];
      fail[u]=ch[v][c];
      prev[u]=val[fail[u]]?fail[u]:prev[fail[u]];
    }
  }
}
int cnt[N];
int ans;
inline void back(int r){
  if(!r)return;
  ans+=val[r];
  val[r]=0;
  back(prev[r]);
}
void match(char *s){
  int r=0;
  while(*s){
    int c=idx(*s++);
    while(r&&!ch[r][c])r=fail[r];
    r=ch[r][c];
    //printf("%c %d %d %d\n",*(s-1),r,val[r],val[prev[r]]);
    back(r);
  }
}

char str[N][M],s[1000010];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  int n;
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    init();
    For(i,n){
      scanf("%s",str[i]);
      cnt[i]=0;
      insert(str[i]);
    }
    getfail();
    scanf("%s",s);
    ans=0;
    match(s);
    printf("%d\n",ans);
  }
  return 0;
}
