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

int getNum(int y) {
  REP (x, 1000001) {
    if (1ll * x * (x-1) / 2 == y)
      return x;
  }
  return -1;
}

char* doit(LL a00, LL a01, LL a10, LL a11) {
  char *ans = new char[1000010];
  int *cnt = new int[1000010];
  LL zero = (a01+a10)?max(1,getNum(a00)):getNum(a00), one = (a01+a10)?max(1, getNum(a11)):getNum(a11);
  if (zero == -1 || one == -1) {
    strcpy(ans, "Impossible");
    return ans;
  }
  LL len = zero + one;
  if (len * (len - 1) / 2 != a00 + a01 + a10 + a11) {
    strcpy(ans, "Impossible");
    return ans;
  }
  if (a01 > zero * one || a10 > zero * one) {
    strcpy(ans, "Impossible");
    return ans;
  }
  //printf("%I64d %I64d %I64d %I64d\n", one, zero, a01/zero, a01%zero);
  if (zero == 0) {
    cnt[zero] = one;
  } else {
    cnt[zero]+=a01/zero;
    one-=a01/zero;
    if (a01 % zero) {
      cnt[a01%zero]++;
      one--;
    }
    cnt[0]+=one;
  }
  int cur = 0;
  for (int i = 0; i <= zero; i++) {
    REP (j, cnt[i])
        ans[cur++] = '1';
    if (i < zero)
      ans[cur++] = '0';
  }
  if (cur == 0)
    ans[cur++] = '0';
  return ans;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int a00, a01, a10, a11;
  scanf("%d%d%d%d", &a00, &a01, &a10, &a11);
  //doit(a00, a01, a10, a11);
  puts(doit(a00, a01, a10, a11));
  return 0;
}
