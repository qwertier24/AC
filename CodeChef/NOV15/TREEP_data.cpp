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

int main(){
#ifdef QWERTIER
  freopen("in","w",stdout);
#endif
  int T=5;
  printf("%d\n",T);
  while(T--){
    int n=100000;
    printf("%d\n",n);
    FOR(i,n-1){
      printf("%d %d %c\n",i+1,rand()%i+1,rand()%26+'a');
    }
    int Q=100000;
    printf("%d\n",Q);
    FOR(i,Q){
      int u=rand()%n+1,v=rand()%n+1;
      while(u==v)v=rand()%n+1;
      printf("1 %d %d\n",u,v);
      //printf("2 %d %d %c\n",u,v,rand()%26+'a');
    }
  }
  return 0;
}
