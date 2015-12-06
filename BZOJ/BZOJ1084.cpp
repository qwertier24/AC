#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 110
#define INF (1<<29)

typedef long long LL;
using namespace std;

int n,m,o,ans,a[N][3];
int d[N][N][20];
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d",&n,&m,&o);
  For(i,n)For(j,m){
    scanf("%d",&a[i][j]);
    a[i][j]+=a[i-1][j];
  }
  memset(d,0xcf,sizeof(d));
  Rep(i,n+1)Rep(j,n+1)d[i][j][0]=0;
  if(m==1){
    For(i,n){
      For(j,min(o,i)){
	d[i][i][j]=d[i-1][i-1][j];
	Rep(k,i)
	  d[i][i][j]=max(d[i][i][j],d[k][k][j-1]+a[i][1]-a[k][1]);
      }
    }
    printf("%d\n",d[n][n][o]);
  }else{
    Rep(i,n+1){
      Rep(j,n+1){
	if(i==0&&j==0)continue;
	For(k,min(i+j,o)){
	  d[i][j][k]=max(i&&j?d[i-1][j-1][k]:-INF,max(i?d[i-1][j][k]:-INF,j?d[i][j-1][k]:-INF));
	  int mark=0;
	  Rep(l,i){
	    if(d[i][j][k]<d[l][j][k-1]+a[i][1]-a[l][1])
	      mark=l;
	    d[i][j][k]=max(d[i][j][k],d[l][j][k-1]+a[i][1]-a[l][1]);
	  }
	  Rep(l,j){
	    if(d[i][j][k]<d[i][l][k-1]+a[j][2]-a[l][2])
	      mark=10+l;
	    d[i][j][k]=max(d[i][j][k],d[i][l][k-1]+a[j][2]-a[l][2]);
	  }
	  Rep(l,min(i,j)){
	    if(d[i][j][k]<d[l][l][k-1]+a[i][1]-a[l][1]+a[i][2]-a[l][2])
	      mark=20+l;
	    d[i][j][k]=max(d[i][j][k],d[l][l][k-1]+a[min(i,j)][1]-a[l][1]+a[min(i,j)][2]-a[l][2]);
	  }
	  //printf("%d %d %d %d %d\n",i,j,k,d[i][j][k],mark);
	}
      }
    }
    printf("%d\n",d[n][n][o]);
  }
  return 0;
}
