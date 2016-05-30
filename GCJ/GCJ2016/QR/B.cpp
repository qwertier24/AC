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

char s[100],n;
int main(){
#ifdef QWERTIER
  freopen("b.in2.txt","r",stdin);
  freopen("b.out2.txt","w",stdout);
#endif 
  int T;
  scanf("%d",&T);
  FOR(kase,T){
    scanf("%s",s);
    n = strlen(s);
    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
      if(s[i] == '-'){
        ans++;
        REP(j, i+1){
          if(s[j] == '-')
            s[j] = '+';
          else
            s[j] = '-';
        }
      }
    }
    printf("Case #%d: %d\n",kase,ans);
  }
  return 0;
}
