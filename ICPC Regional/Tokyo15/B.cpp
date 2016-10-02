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

#define N 510
int r[N];
double pos[N];
double calc(int j, int i) {
    return pos[j] + sqrt(sqr(r[i]+r[j]) - sqr(r[i]-r[j]));
}

double ans;
int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    ans = 0;
    FOR (i, n) {
	scanf("%d", &r[i]);
	pos[i] = r[i];
	FOR (j, i-1) {
	    pos[i] = max(pos[i], calc(j, i));
	}
	ans = max(ans, pos[i] + r[i]);
    }
    printf("%.10f\n", ans);
    return 0;
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | Current Style: Cerulean.

Select Style:   Fluid Width?
 