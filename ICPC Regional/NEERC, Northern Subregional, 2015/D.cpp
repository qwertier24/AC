#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, n) for(int i = 1; i <= n; i++)

typedef long long ll;
typedef long long LL;
typedef pair<int,int> pii;

#ifdef LOCAL
#define err(x) cerr << #x << ":" << x << endl
#else
#define err(x)
#endif

LL ans[233] , maxans; 

int main() {
    freopen("distribution.in", "r", stdin);
    freopen("distribution.out", "w", stdout);

    srand(time(0));
    int t ; cin >> t ; while (t--) {
        LL n , base = 1 ; cin >> n ; maxans = 0;
        while (n%2 == 0) {n /= 2 ; base *= 2;}
        while (n%3 == 0) {n /= 3 ; base *= 3;}
        while (n) {
            LL a = 1;
            while (a*3 <= n) a *= 3;
            n -= a;
            ans[++maxans] = a*base;
            while (n && n%2 == 0) {
                n /= 2;
                base *= 2;
            }
        }
        sort(ans+1,ans+maxans+1);

        cout << maxans << endl;
        for (int i = 1 ; i < maxans ; ++i)
            printf("%I64d ",ans[i]);
        cout << ans[maxans] << endl;
    }
    
    return 0;
}

close