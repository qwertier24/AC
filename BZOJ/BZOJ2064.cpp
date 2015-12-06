#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 10

typedef long long LL;
using namespace std;

int n,m,s;
int a[N],b[N],d[1<<N][1<<N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  Rep(i,n){scanf("%d",&a[i]);s+=a[i];}
  scanf("%d",&m);
  Rep(i,m){scanf("%d",&b[i]);s-=b[i];}
  if(s!=0){
    puts("-1");
    return 0;
  }
  Rep(i,(1<<n))Rep(j,(1<<m)){
    if(i+j==0)continue;
    s=0;
    Rep(k,n)if((i>>k)&1)s+=a[k],d[i][j]=max(d[i][j],d[i^(1<<k)][j]);
    Rep(k,m)if((j>>k)&1)s-=b[k],d[i][j]=max(d[i][j],d[i][j^(1<<k)]);
    d[i][j]+=s==0;
  }
  printf("%d\n",n+m-2*d[(1<<n)-1][(1<<m)-1]);
  return 0;
}
