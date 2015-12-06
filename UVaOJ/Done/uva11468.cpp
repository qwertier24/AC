#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<ctype.h>
#include<queue>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define SIGMA 62
#define MAXN 1000

inline int idx(char c){
  if(isdigit(c))return c-'0';
  else if(islower(c))return c-'a'+10;
  else return c-'A'+36;
}

using namespace std;
int ch[MAXN][SIGMA],sz,mark[MAXN];
void insert(char *s){
  int cur=0;
  while(*s){
    int c=idx(*s++);
    if(!ch[cur][c]){
      sz++;
      ch[cur][c]=sz;
      mark[sz]=0;
      memset(ch[sz],0,sizeof(ch[sz]));
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
double d[MAXN][110],P[SIGMA];
int vis[MAXN][110],n,chr[SIGMA];
double dp(int cur,int L){
  if(!L)return 1.0;
  if(vis[cur][L])return d[cur][L];
  vis[cur][L]=1;
  d[cur][L]=0;
  Rep(i,n)
    if(!mark[ch[cur][chr[i]]])d[cur][L]+=P[i]*dp(ch[cur][chr[i]],L-1);
  return d[cur][L];
}
void init(){
  memset(ch[0],0,sizeof(ch[0]));
  memset(vis,0,sizeof(vis));
  sz=0;
}
int m,L;
char s[30];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
  freopen("out","w",stdout);
#endif
  int T,kase=1;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&m);
    init();
    For(i,m){
      scanf("%s",s);
      insert(s);
    }
    getfail();
    scanf("%d",&n);
    Rep(i,n){
      double a;
      scanf("%s%lf",s,&P[i]);
      chr[i]=idx(s[0]);
    }
    scanf("%d",&L);
    printf("Case #%d: %.6lf\n",kase++,dp(0,L));
  }
  return 0;
}
