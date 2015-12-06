#include<stdio.h>
#include<algorithm>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define M 100
#define N 15 

typedef long long LL;
using namespace std;

double d[M+1][1<<N];
int need[N],sc[N];
int m,n;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&m,&n);
  Rep(i,n){
    scanf("%d",&sc[i]);
    int t;
    while(scanf("%d",&t)&&t)
      need[i]|=(1<<(t-1));
  }
  double P=1.0/n;
  for(int i=m-1; i>=0; i--){
    Rep(j,1<<n){
      Rep(k,n){
	if((j|need[k])==j)
	  d[i][j]+=max(d[i+1][j|(1<<k)]+sc[k],d[i+1][j])*P;
	else
	  d[i][j]+=d[i+1][j]*P;
      }
    }
  }
  printf("%f",d[0][0]);
  return 0;
}
