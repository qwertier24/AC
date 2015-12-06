#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#include<vector>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define RC 126
#define MOD 30031

typedef long long LL;
using namespace std;

int rc;
struct Mat{
  int num[RC][RC];
  Mat(){
    memset(num,0,sizeof(num));
  }
  int* operator[](int x){
    return num[x];
  }
  Mat operator*(Mat r){
    Mat ret;
    Rep(i,rc)Rep(j,rc)Rep(k,rc)
      ret[i][j]=(ret[i][j]+num[i][k]*r[k][j])%MOD;
    return ret;
  }
  void init(){
    Rep(i,rc)num[i][i]=1;
  }
};
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

int cnt_1(int x){
  int ret=0;
  while(x)ret+=x&1,x>>=1;
  return ret;
}
int n,m,p;
vector<int> state;
int mark[1<<10],maxd;
Mat a,b;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  memset(mark,-1,sizeof(mark));
  scanf("%d%d%d",&n,&m,&maxd);
  Rep(i,(1<<maxd)){
    if(cnt_1(i)==m&&(i&1)){
      mark[i]=state.size();
      state.push_back(i);
    }
  }
  
  rc=state.size();
  Rep(i,state.size()){
    int t=state[i]>>1;
    Rep(j,maxd)
      if(mark[(1<<j)|t]!=-1){
        b[i][mark[(1<<j)|t]]=1;
        //printf("%d %d\n",i,mark[(1<<j)|t]);
      }
  }
  a[0][mark[(1<<m)-1]]=1;
  a=a*fPow(b,n-m);
  printf("%d\n",a[0][mark[(1<<m)-1]]);
  return 0;
}
