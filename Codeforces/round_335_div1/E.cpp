#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 1010

int n;
double A[N],B[N];
double p[N][N];
double dis(int u){
  return (B[u]+1)/(1-A[u]);
}
int mark[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  FOR(i,n)FOR(j,n){
    scanf("%lf",&p[i][j]);
    p[i][j]/=100;
  }
  FOR(i,n-1)
    A[i]=1;
  A[n]=0,B[n]=-1;
  FOR(k,n){
    int u=-1;
    FOR(i,n){
      if( (u==-1 || dis(i)<dis(u)&& !mark[i]))
        u=i;
    }
    mark[u]=1;
    FOR(v,n){
      if(mark[v])continue;
      B[v] += A[v]*p[v][u]*dis(u);
      A[v] *= (1-p[v][u]);
    }
  }
  printf("%.10f\n",dis(1));
  return 0;
}
