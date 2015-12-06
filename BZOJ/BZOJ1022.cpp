#include<stdio.h>
#include<algorithm>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;

char ans[2][10]={"John","Brother"};
int a,n,T;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&T);
  while(T--){
    int flag=0,sg=0;
    scanf("%d",&n);
    For(i,n){
      scanf("%d",&a);
      if(a>1)flag=1;
      sg^=a;
    }
    printf("%s\n",ans[(sg>0)^flag]);
  }
  return 0;
}
