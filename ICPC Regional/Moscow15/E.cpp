#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, n) for(int i = 1; i <= n; i++)

typedef long long LL;
typedef long long ll;
typedef pair<int,int> pii;

#ifdef LOCAL
#define err(x) cerr << #x << ":" << x << endl
#else
#define err(x)
#endif

const LL MOD = 1000000007;

LL Pow (LL a , LL b)
{
    LL r = 1;
    while (b) {
        if (b&1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return r;
}

LL Fac[(1<<18)+100] , aFac[(1<<18)+100];

LL C(LL a , LL b)
{
    if (a < 0) return 0;
    if (b < 0 || b > a) return 0;
    return Fac[a] * aFac[b] % MOD * aFac[a-b] % MOD;
}

int A[(1<<18)+100];

int main() {
    Fac[0] = aFac[0] = 1;
    FOR(i,(1<<18)) {
        Fac[i] = Fac[i-1] * i % MOD;
        aFac[i] = Pow(Fac[i],MOD-2);
    }
    int k ; cin >> k ; int n = 1 << k;
    FOR(i,n) scanf("%d",A+i);
    LL ans = 0;
    for (int h = 0 ; h < k ; ++h) {
        LL tmpsum = 0 , sum = 0 , t = 1 << h;
        for (int i = n ; i ; --i) {

            sum = (sum + A[i] * C(n-t-i,t-1) % MOD * tmpsum) % MOD;
            tmpsum = (tmpsum + A[i] * C(n-i,t-1)) % MOD;

        }
        LL a = C(n-1,t-1) * C(n-1-t,t-1) % MOD;
        a = Pow(a,MOD-2);
        ans = (ans + sum * a % MOD * Pow(n/t-1,MOD-2)) % MOD;

        

    }
    cout << ans << endl;
    return 0;
}
close