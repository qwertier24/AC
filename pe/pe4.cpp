#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<math.h>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

int p10[7]={1,10,100,1000,10000,100000,1000000};
inline int getdigit(int n,int p){
  return (n/p10[p])%10;
}
bool check(int n){
  int l=log10(n)+1;
  REP(i,l)
    if(getdigit(n,i)!=getdigit(n,l-1-i))
      return false;
  return true;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int ans=0;
  for(int i=100; i<1000; i++)
    for(int j=100; j<1000; j++)
      if(check(i*j))
        ans=max(ans,i*j);
  printf("%d\n",ans);
  return 0;
}
