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
const int rc=3;
int MOD;

struct Mat{
  int num[rc][rc];
  Mat(int o=0){
    memset(num,0,sizeof(num));
    if(o)REP(i,0,rc-1)num[i][i]=1;
  }
  Mat operator*(Mat &r){
    Mat ret;
    REP(i,0,rc-1)REP(k,0,rc-1)if(num[i][k])REP(j,0,rc-1)if(r[k][j])ret[i][j]=(ret[i][j]+num[i][k]*(LL)r[k][j])%MOD;
    return ret;
  }
  int* operator[](int x){
    return num[x];
  }
  void print(){
    REP(i,0,rc-1)REP(j,0,rc-1)printf("%10d%s",num[i][j],j==rc-1?"\n":"");
    puts("");
  }
}a,b,c;

Mat fPow(Mat t,LL p){
  Mat ret(1);
  while(p){
    if(p&1)ret=ret*t;
    t=t*t;
    p>>=1;
  }
  return ret;
}

int l;
LL n;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%lld%d",&n,&MOD);
  LL nt=n;
  while(nt){
    nt/=10;
    l++;
  }
  a[0][0]=a[0][1]=a[1][1]=a[2][0]=a[2][2]=1;
  b[0][0]=b[0][2]=1;
  LL po=9;
  REP(i,1,l){
    a[1][1]=(a[1][1]*10ll)%MOD;
    c=fPow(a,i==l?n:po);
    n-=po;
    b=b*c;
    //b.print();
    po*=10;
  }
  printf("%d\n",b[0][1]);
  return 0;
}
