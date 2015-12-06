#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 2010

typedef long long LL;
using namespace std;

int n,h,dh;
int mark[N][N],d[N][N],maxd[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d",&n,&h,&dh);
  For(i,n){
    int nt,ht;
    scanf("%d",&nt);
    while(nt--){
      scanf("%d",&ht);
      mark[i][ht]++;
    }
  }
  for(int i=h; i; i--){
    For(j,n){
      d[i][j]=d[i+1][j]+mark[j][i];
      if(i+dh<=h)
        d[i][j]=max(d[i][j],maxd[i+dh]+mark[j][i]);
      maxd[i]=max(maxd[i],d[i][j]);
    }
  }
  printf("%d\n",maxd[1]);
  return 0;
}
