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

#define N 110

int a[N], b[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
      int n, m;
      scanf("%d%d", &n, &m);
      FOR(i,n){
          scanf("%d",&a[i]);
      }
      sort(a+1,a+n+1);
      reverse(a+1,a+n+1);
      FOR(i,m){
          scanf("%d",&b[i]);
      }
      sort(b+1,b+m+1);
      int p1 = 1, p2 = 1;
      int cur = 0, ans = 0;
      REP(i,n+m){
          char op;
          scanf(" %c", &op);
          if(op == '+'){
              cur += a[p1++];
          }else{
              if(b[p2] > cur){
                  ans++;
              }else{
                  cur -= b[p2++];
              }
          }
      }
      printf("%d\n",ans);
  }
  return 0;
}
