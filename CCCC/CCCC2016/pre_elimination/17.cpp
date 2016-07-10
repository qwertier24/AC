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
  freopen("in.txt","r",stdin);
#endif 
  int n;
  scanf("%d",&n);
  int odd = 0;
  FOR(i,n){
      int a ;
      scanf("%d",&a);
      if(a % 2)
          odd ++;
  }
  printf("%d %d\n", odd, n - odd);
  return 0;
}
