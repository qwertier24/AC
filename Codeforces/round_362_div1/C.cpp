#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 100010
#define MOD 1000000007

int k;
LL a[N];
LL fPow(LL t, LL p) {
  LL ret = 1;
  while(p) {
    if (p&1)
      ret = ret * t % MOD;
    t = t * t % MOD;
    p >>= 1;
  }
  return ret;
}
LL mod(LL m) {
  return (m%MOD+MOD)%MOD;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &k);
  int n_div_2 = 1;
  FOR(i,k){
    scanf("%I64d", &a[i]);
    n_div_2 *= (a[i] & 1);
  }
  LL p = 1;
  FOR(i,k){
    p = p * (a[i] % (MOD - 1)) % (MOD - 1);
  }
  //printf("%I64d\n", p);
  LL _2_n_1 = fPow(2, MOD-2) * fPow(2,p) % MOD;
  //printf("%d\n", n_div_2);
  //printf("%I64d %I64d %I64d\n", _2_n_1 + 1, fPow(3,MOD-2), fPow(3,MOD-2)*3%MOD);
  LL a,b;
  if (n_div_2 == 0) {
    a = mod((_2_n_1 + 1) * fPow(3, MOD-2) % MOD);
  } else {
    a = mod((_2_n_1 - 1) * fPow(3, MOD-2) % MOD);
  }
  b = _2_n_1;
  printf("%I64d/%I64d\n", a, b);
  return 0;
}