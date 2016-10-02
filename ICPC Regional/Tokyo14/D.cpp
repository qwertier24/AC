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

#define sqr(x) ((x)*(x))

#define N 20

int n;
int p[N], h[N];

double calc_y(double vy, double vx, double x) {
    return -(0.5)  * sqr(x/vx) + (vy/vx) * x;
}
bool check(double vy, double xy, double len) {
    double curp = 0;
    FOR (i, n) {
	while (p[i] > curp + len)
	    curp += len;
	if (h[i] >= calc_y(vy, xy/vy, p[i] - curp)) {
	    return false;
	}
    }
    return true;
}
double d;
double calc(int b) {
    double xy = d / 2.0 / double(b+1);
    double len = d / double(b+1);
    double lo = 1e-18, hi = 1e18;

    REP (i, 10000) {
	double mi = (lo + hi) / 2.0;
	if (check(mi, xy, len))
	    hi = mi;
	else
	    lo = mi;
    }
    double vy = lo;
    if (vy < sqrt(xy))
	vy = sqrt(xy);
    return sqrt(sqr(vy) + sqr(xy/vy));
}

int main() {
#ifdef LOCAL
    freopen("D.in", "r", stdin);
#endif
    int b;
    scanf("%lf%d%d", &d, &n, &b);
    FOR( i,n ) {
	scanf("%d%d", &p[i], &h[i]);
    }
    double ans = 1e18;
    REP (i, b+1) {
	ans = min(ans, calc(i));
    }
    printf("%.10f\n", ans);
    return 0;
}
close