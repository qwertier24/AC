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

int a[3], b[3];
bool check_a(){
    return a[2] == a[1] + b[1];
}
bool check_b(){
    return b[2] == a[1] + b[1];
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int n, cnta= 0 ,cntb = 0, ans;
  scanf("%d%d",&a[0],&b[0]);
  scanf("%d",&n);
  FOR(i,n){
      scanf("%d%d%d%d",&a[1],&a[2],&b[1],&b[2]);
      if(check_a() && check_b())
          continue;
      else if(check_b()){
          cntb++;
          if(cntb > b[0]){
              ans = 1;
              break;
          }
      }else if(check_a()){
          cnta++;
          if(cnta > a[0]){
              ans = 0;
              break;
          }
      }
  }    
  printf("%c\n",ans+'A');
  if(ans)
      printf("%d\n", cnta);
  else
      printf("%d\n", cntb);
  return 0;
}
