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
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    double h1, t1, h2, t2;
    scanf("%lf%lf%lf%lf", &h1, &t1, &h2, &t2);
    if (h2 < h1) {
        swap(h1, h2);
        swap(t1, t2);
    }
    long double a = (h2 - h1),
        b = 2 * (h2 * t1 - h1 * t2),
        c = -h1 * t2 * t2 + h2 * t1 * t1;
    printf("%f\n", (double)((b - sqrt(b*b - 4 * a * c)) / (2 * a)));
    return 0;
}
close