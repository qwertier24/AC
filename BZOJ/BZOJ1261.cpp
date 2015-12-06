#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 40
#define INF (1e60)

typedef long long LL;
using namespace std;

int n;
double K,c,s,a[N],d[N][N][N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%lf%lf",&n,&K,&c);
  For(i,n){
    scanf("%lf",&a[i]);
    s+=a[i];
  }
  For(i,n)
    a[i]/=s;
  Rep(i,n){
    For(j,n)
      d[i][j][j]=((i+1)*K+c)*a[j];
  }
  for(int dep=n-1; dep>=0; dep--){
    for(int len=2; len<=n; len++){
      For(i,n-len+1){
        int j=i+len-1;
        d[dep][i][j]=INF;
        for(int k=i; k<=j; k++){
          if(d[dep][i][j]>d[dep+1][i][k-1]+a[k]*((dep+1)*K+c)+d[dep+1][k+1][j]){
            d[dep][i][j]=d[dep+1][i][k-1]+a[k]*((dep+1)*K+c)+d[dep+1][k+1][j];
          }
        }
      }
    }
  }
  printf("%.3f\n",d[0][1][n]);
  return 0;
}
