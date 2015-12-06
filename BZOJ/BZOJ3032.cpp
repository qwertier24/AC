#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010

typedef long long LL;
using namespace std;

int c[N];
int calc(int *a,int n){
  int avg=0;
  For(i,n)avg+=a[i];
  avg/=n;
  For(i,n){
    c[i]=c[i-1]+avg-a[i];
  }
  sort(c+1,c+n+1);
  int bn=c[(n+1)/2];
  int ret=0;
  For(i,n)
    ret+=abs(bn-c[i]);
  return ret;
}

int n,m,t;
int cntx[N],cnty[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d",&n,&m,&t);
  if(t%n && t%m){
    printf("impossible");
    return 0;
  }
  else if(t%n)
    printf("column ");
  else if(t%m)
    printf("row ");
  else
    printf("both ");
  LL ans=0;
  For(i,t){
    int x,y;
    scanf("%d%d",&x,&y);
    cntx[x]++;
    cnty[y]++;
  }
  if(t%n==0)
    ans+=calc(cntx,n);
  if(t%m==0)
    ans+=calc(cnty,m);
  printf("%lld\n",ans);
  return 0;
}
