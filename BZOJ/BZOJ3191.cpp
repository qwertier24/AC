#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define M 60

using namespace std;

int n,m;
int card[M];
double d[M][M];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  For(i,m)scanf("%d",&card[i]);
  For(c,n){
    memset(d,0,sizeof(d));
    d[n][((1-c)%n+n)%n]=1;
    for(int i=n-1; i; i--){
      Rep(j,n){
	For(k,m){
	  if((j+card[k]-1)%(i+1)==0)continue;
	  d[i][(j+card[k]-1)%(i+1)%i]+=d[i+1][j]/m;
	}
      }
    }
    printf("%.2f%%%c",d[1][0]*100,c==n?'\n':' ');
  }
  return 0;
}
