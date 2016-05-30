#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

int K,C,S;
LL num[200];
int main(){
#ifdef QWERTIER
  freopen("d.in2.txt","r",stdin);
  freopen("d.out2.txt","w",stdout);
#endif
  int T;
  scanf("%d",&T);
  FOR(kase,T){
    scanf("%d%d%d",&K,&C,&S);
    printf("Case #%d: ",kase);
    int n = K, m = 0;
    memset(num,0,sizeof(num));
    while(n > 0){
      REP(i,C){
        num[m] = num[m] * K + n - 1;
        n--;
        if(n<=0)
          break;
      }
      m++;
    }
    if(S<m){
      puts("Impossible");
    }else{
      REP(i,m)
        printf("%lld ",num[i]+1);
      puts("");
    }
  }
  return 0;
}
