#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define MAXN 6010
#define SIGMA 26
#define MOD 10007

using namespace std;

inline int idx(char c){
  return c-'A';
}
int ch[MAXN][SIGMA],mark[MAXN],sz;
void insert(char *s){
  int cur=0;
  while(*s){
    int c=idx(*s++);
    if(!ch[cur][c]){
      sz++;
      ch[cur][c]=sz;
      mark[sz]=0;
    }
    cur=ch[cur][c];
  }
  mark[cur]=1;
}
int fail[MAXN];
void getfail(){
  queue<int> q;
  Rep(i,SIGMA)if(ch[0][i]){
    q.push(ch[0][i]);
    fail[ch[0][i]]=0;
  }
  while(!q.empty()){
    int r=q.front();
    q.pop();
    Rep(c,SIGMA){
      int u=ch[r][c];
      if(!u){
	ch[r][c]=ch[fail[r]][c];
	continue;
      }
      q.push(u);
      fail[u]=ch[fail[r]][c];
      mark[u]|=mark[fail[u]];
    }
  }
}
inline void add(int &tar,int addv){
  tar+=addv;
  if(tar>=MOD)tar-=MOD;
}
int d[MAXN][110];
int dp(int u,int L){
  if(!L)return 1;
  if(d[u][L]!=-1)return d[u][L];
  d[u][L]=0;
  Rep(i,SIGMA)if(!mark[ch[u][i]])add(d[u][L],dp(ch[u][i],L-1));
  return d[u][L];
}
char s[110];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  memset(d,-1,sizeof(d));
  int n,L;
  scanf("%d%d",&n,&L);
  int maxlen=0;
  For(i,n){
    scanf("%s",s);
    maxlen=max(maxlen,(int)strlen(s));
    insert(s);
  }
  getfail();
  int ans=1;
  For(i,L)ans=(ans*26)%MOD;
  //printf("%d\n",dp(0,L));
  printf("%d\n",(ans-dp(0,L)+MOD)%MOD);
  return 0;
}
