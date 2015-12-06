#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
using namespace std;
#define M 210
#define MOD 1000000007

int rc;
struct Mat{
  int val[M][M];
  int* operator[](int x){
    return val[x];
  }
  void init(){val[0][0]=val[1][1]=val[2][2]=1;}
  Mat(){memset(val,0,sizeof(val));}
  Mat operator*(Mat &r){
    Mat ret;
    REP(i,0,rc-1)REP(k,0,rc-1)if(val[i][k])REP(j,0,rc-1)if(r[k][j])ret[i][j]=(ret[i][j]+val[i][k]*(LL)r[k][j])%MOD;
    return ret;
  }
  void print(){
    REP(i,0,rc-1)REP(j,0,rc-1)printf("%5d%s",val[i][j],j==rc-1?"\n":"");
  }
}mat;

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

int C[M][M],m,n;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  REP(i,0,m){
    C[i][0]=1;
    REP(j,1,i)
      C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
  }
  REP(i,0,m)REP(j,0,i)
    mat[j][i]=C[i][j]*(LL)m%MOD;
  rc=m+2;
  mat[rc-1][rc-1]=mat[rc-2][rc-1]=1;
  mat=fPow(mat,n+1);
  printf("%d\n",mat[0][rc-1]);
  return 0;
}
