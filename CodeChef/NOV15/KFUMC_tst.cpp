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

int f(int x){
  if(x<10)return x;
  int x1=0;
  while(x){
    x1+=x%10;
    x/=10;
  }
  return f(x1);
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif 
  for(int i=19; i<200; i+=7)
    printf("%d\n",f(i));
  return 0;
}
