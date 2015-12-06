#include<stdio.h>
#include<algorithm>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;
typedef long long LL;

int n,ans;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  while(n){
    ans++;
    n/=2;
  }
  printf("%d",ans);
  return 0;
}
