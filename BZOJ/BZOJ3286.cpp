#include<stdio.h>
#include<cstring>
#define REP(i,b,e) for(int i=b; i<=e; ++i)
#define RREP(i,b,e) for(int i=b; i>=e; --i)

typedef long long LL;
typedef unsigned long long uint;
#define MOD 2012182013

const int rc=3;
struct Mat{
  uint val[rc][rc];
  uint* operator[](int x){
    return val[x];
  }
  void init(){val[0][0]=val[1][1]=val[2][2]=1;}
  Mat(){memset(val,0,sizeof(val));}
  Mat operator*(Mat &r){
    Mat ret;
    REP(i,0,rc-1)REP(k,0,rc-1)if(val[i][k])REP(j,0,rc-1)if(r[k][j])ret[i][j]=(ret[i][j]+val[i][k]*r[k][j])%MOD;
    return ret;
  }
  Mat p10(){
    Mat t1,ret;
    t1=*this**this;
    ret=t1;
    t1=t1*t1;
    t1=t1*t1;
    ret=ret*t1;
    return ret;
  }
}mat1,mat2,mat3,A,R,C,T;

Mat fPow(Mat t,int* p){
  Mat ret,pt[10];ret.init();
  pt[0].init();
  REP(i,1,9)pt[i]=pt[i-1]*t;
  int cur=p[0];
  while(cur){
    ret=ret.p10()*pt[p[cur]];
    cur--;
  }
  return ret;
}

int a,b,c,d,e,f;
void read(int &x){
  LL ret=0;
  char c=getchar();
  while(c<'0' || c>'9')c=getchar();
  while('0'<=c && c<='9'){
    ret=(ret*10ll+c-'0')%MOD;
    c=getchar();
  }
  x=ret;
}
int n[1000010],m[1000010];
void read1(int *num){
  char c=getchar();
  num[0]=0;
  while(c<'0' || c>'9')c=getchar();
  while('0'<=c && c<='9'){
    num[++num[0]]=c-'0';
    c=getchar();
  }
  int t;
  for(int i=1; i*2<=num[0]; i++){
    t=num[i];
    num[i]=num[num[0]-i+1];
    num[num[0]-i+1]=t;
  }
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  read1(n);read1(m);read(a);read(b);read(c);read(d);read(e);read(f);
  mat1[1][0]=1;mat1[0][1]=a;mat1[1][1]=b;mat1[2][1]=c;mat1[2][2]=1;
  mat2[1][0]=1;mat2[0][1]=d;mat2[1][1]=e;mat2[2][1]=f;mat2[2][2]=1;
  m[1]-=2;
  for(int i=1; m[i]<0; i++)m[i]+=10,m[i+1]--;
  if(!m[0])m[0]--;
  T=fPow(mat1,m);
  mat2=mat2*mat2;
  R=T*mat2;
  n[1]--;
  for(int i=1; n[i]<0; i++)n[i]+=10,n[i+1]--;
  if(!n[0])n[0]--;
  C=fPow(R,n);
  A=C*T;
  printf("%llu\n",((A[0][1]+A[1][1])%MOD+A[2][1])%MOD);
  return 0;
}
