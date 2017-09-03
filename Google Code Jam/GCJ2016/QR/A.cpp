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

int main(){
#ifdef QWERTIER
  freopen("a.in2.txt","r",stdin);
  freopen("a.out2.txt","w",stdout);
#endif 
  int T;
  scanf("%d",&T);
  FOR(kase,T){
    int n,mark[10]={0},c=0;
    scanf("%d",&n);
    printf("Case #%d: ",kase);
    if(n==0){
      puts("INSOMNIA");
      continue;
    }
    FOR(i,100000){
      LL j = i*n;
      while(j){
        if(!mark[j%10]){
          c++;
          mark[j%10]=1;
        }
        j/=10;
      }
      if(c==10){
        printf("%lld\n",i*(LL)n);
        break;
      }
    }
  }
  return 0;
}
