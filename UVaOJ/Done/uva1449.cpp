#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#include<string>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 160
#define M 80
#define SIGMA_SIZE 26

using namespace std;
typedef long long LL;

int ch[N*M][SIGMA_SIZE],sz,val[N*M],fail[N*M],prev[N*M];
int idx(char c){
  return c-'a';
}
void init(){
  sz=0;
  memset(ch[0],0,sizeof(ch[0]));
}
void insert(char* s,int ord){
  int cur=0;
  while(*s){
    int c=idx(*s++);
    if(!ch[cur][c]){
      ch[cur][c]=++sz;
      memset(ch[sz],0,sizeof(ch[sz]));
      fail[sz]=0;
      prev[sz]=0;
      val[sz]=0;
    }
    cur=ch[cur][c];
  }
  val[cur]=ord;
}
void getfail(){
  queue<int> q;
  Rep(i,SIGMA_SIZE)
    if(ch[0][i]){
      fail[ch[0][i]]=0;
      q.push(ch[0][i]);
      prev[ch[0][i]]=0;
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
void back(int r){
  if(!r)return;
  cnt[val[r]]++;
  back(prev[r]);
}
void match(char *s){
  int r=0;
  while(*s){
    int c=idx(*s++);
    while(r&&!ch[r][c])r=fail[r];
    r=ch[r][c];
    //printf("%c %d\n",*(s-1),r);
    if(val[r])back(r);
    else if(prev[r])back(prev[r]);
  }
}

char str[N][M],s[1000010];
map<string,int> mp;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  int n;
  while(scanf("%d",&n)&&n){
    init();
    mp.clear();
    For(i,n){
      scanf("%s",str[i]);
      mp[str[i]]=i;
      insert(str[i],i);
      cnt[i]=0;
    }
    getfail();
    scanf("%s",s);
    match(s);
    int maxc=0;
    For(i,n)
      maxc=max(maxc,cnt[i]);
    printf("%d\n",maxc);
    For(i,n)if(cnt[mp[str[i]]]==maxc)printf("%s\n",str[i]);
  }
  return 0;
}
