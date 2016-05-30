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
int mark[N],n;
int kth(int k){
    FOR(i,n){
        if(!mark[i])
            k--;
        if(k==0)
            return i;
    }
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
      int Q;
      scanf("%d%d",&n,&Q);
      memset(mark, 0, sizeof(mark));
      while(Q--){
          char op;
          int u;
          scanf(" %c %d",&op, &u);
          if(op == '-'){
              mark[u] = mark[n-u+1] = 1;
          }else{
              printf("%d\n",kth(u));
          }
      }
  }
  return 0;
}
