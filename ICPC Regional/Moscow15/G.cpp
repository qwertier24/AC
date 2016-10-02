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

#define N 200010
#define double long double

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
#define MP make_pair

typedef pair<double, int> pdi;

#define INF (1e100)

pdi maxv[N<<2][2];
void initTree(int o, int l, int r) {
    maxv[o][0] = maxv[o][1] = MP(-INF, 0);
    if (l == r)
        return;
    initTree(lc, l, mid);
    initTree(rc, mid + 1, r);
}

void add(int o, int l, int r, int p, int i, pdi x) {
    if (l == r) {
        maxv[o][i] = max(maxv[o][i], x);
        return;
    }
    if (p <= mid)
        add(lc, l, mid, p, i, x);
    else
        add(rc, mid + 1, r, p, i, x);
    REP (i, 2)
        maxv[o][i] = max(maxv[lc][i], maxv[rc][i]);
}

pdi query(int o, int l, int r, int L, int R, int i) {
    L = max(L, l);
    R = min(R, r);
    if (L > R)
        return MP(-INF, 0);
    if (L <= l && r <= R) {
        return maxv[o][i];
    }
    return max(query(lc, l, mid, L, R, i), query(rc, mid + 1, r, L, R, i));
}

int n, b[N], m, id[N];
pii p[N];
bool cmp(const int &i, const int &j) {
    return p[i] < p[j];
}
pair<double, pii> proc() {
    FOR (i, n)
        id[i] = i;
    sort(id+1, id+n+1, cmp);
    m=0;
    FOR (i, n) {
        b[++m] = p[i].fi - p[i].se;
    }
    sort(b + 1, b + m + 1);
    m = unique(b + 1, b + m + 1) - b - 1;
    initTree(1, 1, m);
    
    pair<double, pii> ret;
    double sq2 = sqrt(2);
    FOR (k, n) {
        int i = id[k];
        int j = lower_bound(b + 1, b + m + 1, p[i].fi - p[i].se) - b;
        pdi m1 = query(1, 1, m, 1, j, 0);
        pdi m2 = query(1, 1, m, j + 1, m, 1);
        m1.fi += p[i].fi + (p[i].se) * (sq2 - 1);
        m2.fi += p[i].se + (p[i].fi) * (sq2 - 1);
        ret = max(ret, max(MP(m1.fi, MP(i, m1.se)),
                           MP(m2.fi, MP(i, m2.se))));
        add(1, 1, m, j, 0, MP(-p[i].fi - p[i].se * (sq2 - 1), i));
        add(1, 1, m, j, 1, MP(-p[i].fi * (sq2 - 1) - p[i].se, i));
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);
    FOR (i, n) {
        scanf("%d%d", &p[i].fi, &p[i].se);
    }
    pair<double, pii> ans = proc();
    FOR (i, n) {
        p[i].fi = -p[i].fi;
    }
    ans = max(ans, proc());
    printf("%d %d\n", ans.se.fi, ans.se.se);
    return 0;
}
close