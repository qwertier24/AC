#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, n) for(int i = 1; i <= n; i++)

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second

#ifdef LOCAL
#define err(x) cerr << #x << ":" << x << endl
#else
#define err(x)
#endif


int n, w, d;

#define N 1010
pii p[N];
bool cmp(const pii &i, const pii &j) {
    return i.se < j.se;
}
bool contain(int pos, int i) {
    return (p[i].first <= pos && pos <= p[i].se) ||
	(p[i].first <= pos + w + w + d + d && pos + w + w + d + d <= p[i].se);
}
int calc(int pos) {
    int cnt = 0;
    vector<pii> v;
    FOR (i, n) {
	if (p[i].fi < pos) {
	    p[i].fi += w + w + d + d;
	    p[i].se += w + w + d + d;
	}
	if (!contain(pos, i)) {
	    v.push_back(p[i]);
	}
    }
    sort(v.begin(), v.end(), cmp);
    int r = pos;
    REP (i, v.size()) {
	if (r < v[i].fi) {
	    r = v[i].se;
	    cnt++;
	}
    }
    return cnt;
}
int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    cin >> n >> w >> d;
    vector<int> t;
    FOR (i,n) {
	int x, y;
	char dir;
	scanf("%d%d %c",&x,&y,&dir);
	if (dir == 'N') {
	    p[i] = pii(w + d + w - x - (d - y),
		       w + d + w - x + (d - y));
	} else if (dir == 'E') {
	    p[i] = pii(w + y - (w - x), w + y + (w - x));
	} else if (dir == 'S') {
	    p[i] = pii(x - y, x + y);
	} else {
	    p[i] = pii(w + d + w + d - y - (x),
		       w + d + w + d - y + (x));
	}
	t.push_back(p[i].fi);
	t.push_back(p[i].se);
    }
    sort(t.begin(), t.end());
    int ans = 1<<30;
    REP (i, t.size()) {
	ans = min(ans, calc(t[i]) + 1);
    }
    printf("%d\n", ans);
    return 0;
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | Current Style: Cerulean.

Select Style:   Fluid Width?
 