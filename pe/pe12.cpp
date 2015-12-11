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
  LL cur=0;
  for(LL i=1; ;i++){
    cur+=i;
    int cnt=0;
    for(LL j=1; j*j<=cur; j++){
      if(cur%j==0){
        cnt++;
        if(j*j!=cur)
          cnt++;
      }
    }
    if(cnt>500){
      printf("%lld\n",cur);
      break;
    }
  }
  return 0;
}
