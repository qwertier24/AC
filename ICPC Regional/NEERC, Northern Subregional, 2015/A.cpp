#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, n) for(int i = 1; i <= n; i++)

typedef long long ll;
typedef pair<int,int> pii;
#define first fi
#define second se

#ifdef LOCAL
#define err(x) cerr << #x << ":" << x << endl
#else
#define err(x)
#endif

int main() {
    
    freopen("alex.in", "r", stdin);
    freopen("alex.out", "w", stdout);
    
    double n, m;
    scanf("%lf%lf", &n, &m);
    double ans = 0;
    ans = max(ans, min(n/2, m/2));
    ans = max(ans, min(n/3, m));
    ans = max(ans, min(m/3, n));
    printf("%.10f\n", ans);
    return 0;
}