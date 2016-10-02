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

#define MOD 1000003
LL fPow(LL t, LL p, LL mod = MOD) {
  LL ret = 1;
  while (p) {
    if (p&1)
      ret = ret * t % mod;
    t = t * t % mod;
    p>>=1;
  }
  return ret;
}

LL twos(LL x) {
  if (x == 0)
    return 0;
  return x/2 + twos(x/2);
}
int factor[1000010];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  LL n, k;
  scanf("%I64d%I64d", &n, &k);
  if (n <= 60 && k > (1ll<<n)) {
    puts("1 1");
    return 0;
  }
  if (k > MOD) {
    LL x = fPow(fPow(2, n), k-1) * fPow(fPow(2, MOD-2), twos(k-1)) % MOD;
    printf("%I64d %I64d\n", x, x);
    return 0;
  }
  LL a = 1, b = 1;
  int tot2 = 0;
  for (LL i = 1; i <= k-1; i++) {
    //printf("%d\n", i);
    LL j = i;
    while (j % 2 == 0) {
      j /= 2;
      tot2++;
    }
    a = a * (fPow(2, n)-i) % MOD;
    a+=MOD;
    a%=MOD;
    //printf("j:%d %d\n", j, rem2);
  }
  a = a * fPow(fPow(2, MOD - 2), tot2) % MOD;
  b = fPow(fPow(2, n), k-1) * fPow(fPow(2, MOD -2), tot2) % MOD;
  //printf("%I64d %I64d\n", a, b);
  printf("%I64d %I64d\n", ((b - a)%MOD+MOD)%MOD, b);
  return 0;
}
