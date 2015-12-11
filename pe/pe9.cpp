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
  freopen("in.txt","r",stdin);
#endif 
  int n=1000;
  FOR(i,n)FOR(j,n)
    if(i*i+j*j==(1000-i-j)*(1000-i-j))
      printf("%d %d %d %d\n",i,j,(1000-i-j),i*j*(1000-i-j));
  return 0;
}
