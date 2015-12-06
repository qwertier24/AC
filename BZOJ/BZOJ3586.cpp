#include<stdio.h>
#include<algorithm>
#include<string.h>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;

#define SZ 60
#define N 10
#define M 10

int m,id[N];

int ch[SZ][M],sz;
inline void insert(char *s,int i){
  int u=0;
  while(*s){
    int c=*(s++)-'a';
    if(!ch[u][c])
      ch[u][c]=++sz;
    u=ch[u][c];
  }
  id[i]=u;
}
int q[SZ],fr,rr,fa[SZ];
void calc_fa(){
  fr=0,rr=-1;
  REP(i,m)if(ch[0][i])q[++rr]=ch[0][i];
  while(fr<=rr){
    int &u=q[fr++];
    REP(i,m){
      int &r=ch[0][i];
      if(!r){
	r=ch[fa[u]][i];
	continue;
      }
      fa[r]=ch[fa[u]][i];
      q[++rr]=r;
    }
  }
}
#define fabs(t) ((t)<0?(-t):(t))
double mat[SZ][SZ];
void gauss(int n){
  REP(i,n){
    int t=i;
    for(int j=i+1; j<n; j++)
      if(fabs(mat[j][i])>fabs(mat[t][i]))
	t=j;
    if(t!=i)
      for(int j=i; j<=n; j++)
	swap(mat[t][j],mat[i][j]);
    for(int j=i+1; j<n; j++)
      if(mat[j][i]<1e-9 && mat[j][i]>-1e-9)
	for(int k=i; k<=n; k++)
	  mat[j][k]-=mat[j][i]/mat[i][i]*mat[i][k];
  }
  for(int i=n-1; i>=0; i--){
    for(int j=i+1; j<n; j++)
      mat[i][n]-=mat[j][n]*mat[i][j];
    mat[i][n]/=mat[i][i];
  }
}

int n;

double exp[N][N],P[M];
inline void calc_exp(int i){
  memset(mat,0,sizeof(mat));
  for(int j=0; j<=sz; j++){
    mat[j][j]=1;
    if(j==id[i])
      continue;
    REP(k,m)
      mat[j][ch[j][k]]-=P[k];
    mat[j][sz+1]=1;
  }
  gauss(sz+1);
  for(int j=0; j<=n; j++)
    exp[j][i]=mat[id[j]][sz+1];
}

char str[20];
int L;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&L,&m);
    sz=0;
    memset(ch,0,sizeof(ch));
    REP(i,n){
      scanf("%s",str);
      insert(str,i);
    }
    REP(i,m){
      scanf("%lf",&P[i]);
      P[i]/=10000.0;
    }
    calc_fa();
    FOR(i,n)
      calc_exp(i);
    REP(S,(1<<n))REP(i,n)
      if((S>>i)&1){
	REP(j,n)
	  if(!((S>>j)&1))
	    dp[S|(1<<j)][j]=dp[S][i]+exp[i][j];
      }
    double ans=0;
    
  }
  return 0;
}
