#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
#define FI first
#define SE second
#define VI vector<int>
#define CLR(x) memset(x, 0, sizeof(x))
#define SZ(x) (x.size())
#ifdef QWERTIER
#define err(x) cerr<<x<<endl;
#else
#define err(x)
#endif

typedef long long LL;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    LL r=exgcd(b,a%b,x,y);
    LL t=x;
    x=y;
    y=t-a/b*y;
    return r;
}

int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    int x, y, p, q;
    scanf("%d%d%d%d", &x, &y, &p, &q);
    if ((x < y && p == q) || (x > 0 && p == 0)) {
      puts("-1");
    } else {
      LL lo = (y+q-1)/q, hi = 1e9+1;
      while (lo < hi) {
        LL mi = (lo + hi) >> 1;
        if (x <= p * mi && x + q * mi - y >= p * mi)
          hi = mi;
        else
          lo = mi + 1;
      }
      //printf("%I64d\n", lo);
      printf("%I64d\n", lo * (LL)q - y);
    }
  }
  return 0;
}
