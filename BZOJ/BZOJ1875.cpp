#include<stdio.h>
#include<algorithm>
#include<cstring>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 30
#define M 130
#define MOD 45989

int le[N],ev[M],pe[M],ecnt;
void addEdge(int u,int v){
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ecnt++;
}
int rc;
struct Mat{
  int val[M][M];
  int* operator[](int x){
    return val[x];
  }
  void print(){
    REP(i,0,rc-1)REP(j,0,rc-1)
      printf("%3d%s",val[i][j],j==rc-1?"\n":"");
    puts("");
  }
  void init(){REP(i,0,rc-1)val[i][i]=1;}
  Mat(){memset(val,0,sizeof(val));}
  Mat operator*(Mat &r){
    Mat ret;
    REP(i,0,rc-1)REP(k,0,rc-1)if(val[i][k])REP(j,0,rc-1)ret[i][j]=(ret[i][j]+val[i][k]*r[k][j])%MOD;
    return ret;
  }
}mat,a;

Mat fPow(Mat t,int p){
  Mat ret;
  ret.init();
  while(p){
    if(p&1)ret=ret*t;
    t=t*t;
    p>>=1;
  }
  return ret;
}

int n,m,d,s,t;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  memset(le,-1,sizeof(le));
  scanf("%d%d%d%d%d",&n,&m,&d,&s,&t);
  if(d==0){
    puts("0");
    return 0;
  }
  while(m--){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  REP(i,0,ecnt-1){
    for(int j=le[ev[i]]; j!=-1; j=pe[j])
      if((i^1)!=j)
        mat[i][j]=1;
  }
  rc=ecnt;
  mat=fPow(mat,d-1);
  for(int i=le[s]; i!=-1; i=pe[i])
    a[0][i]=1;
  a=a*mat;
  int ans=0;
  for(int i=le[t]; i!=-1; i=pe[i])
    ans=(ans+a[0][i^1])%MOD;
  printf("%d\n",ans);
  return 0;
}
