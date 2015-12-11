#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

int m=1000000,n=10,f[10],mark[10];
void init(){
  f[0]=1;
  for(int i=1; i<n; i++)
    f[i]=f[i-1]*i;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  init();
  m--;
  for(int i=n-1; i>=0; i--){
    int t=m/f[i]+1,c;
    REP(j,n){
      if(!mark[j])
        t--;
      if(t==0){
        c=j;
        break;
      }
    }
    printf("%d",c);
    mark[c]=1;
    m%=f[i];
  }
  return 0;
}
