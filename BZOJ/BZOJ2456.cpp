#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

typedef long long LL;
using namespace std;

int n;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  int cur,t=0;
  For(i,n){
    int a;
    scanf("%d",&a);
    if(t==0){
      cur=a;
      t=1;
    }else if(cur==a){
      t++;
    }else{
      t--;
      if(t==0){
        cur=a;
        t++;
      }
    }
  }
  printf("%d\n",cur);
  return 0;
}
