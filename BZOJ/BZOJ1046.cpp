#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define INF 1<<30
#define N 10000

using namespace std;

int g[N+10],d[N+10],a[N+10],m,n;
bool cmp(const int& a,const int& b){
  return a>b;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  For(i,n)g[i]=-INF;
  For(i,n)
    scanf("%d",&a[i]);
  for(int i=n; i; --i){
    int k=lower_bound(g+1,g+n+1,a[i],cmp)-g;
    g[k]=a[i];
    d[i]=k;
  }
  scanf("%d",&m);
  For(i,m){
    int len,la;
    bool flag=false;
    scanf("%d",&len);
    int cur=1;
    while(cur<=n&&d[cur]<len)cur++;
    if(cur>n)puts("Impossible");
    else{
      printf("%d",a[cur]);
      len--;
      la=a[cur++];
      while(len){
	while(cur<=n&&(a[cur]<=la||d[cur]<len))cur++;
	printf(" %d",a[cur]);
	len--;
	la=a[cur++];
      }
      puts("");
    }
  }
  return 0;
}
