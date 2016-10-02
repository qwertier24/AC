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

#define N 60

int n, gt[N][N], g[N][N], g0[N][N];
void multi(int (*g)[N], int (*g0)[N]) {
    memset(gt, 0, sizeof(gt));
    FOR (i, n) {
	FOR (j, n) {
	    FOR (k, n) {
		gt[i][j] |= g[i][k] & g0[k][j];
	    }
	    //printf("gt[%d][%d]=%d\n", i, j, gt[i][j]);
	}
    }
    memcpy(g, gt, sizeof(gt));
}

int da[N], db[N], dc[N], ga[N][N], gb[N][N], gc[N][N], vis[N];
#define INF (1<<29)

int main() {
#ifdef LOCAL
    freopen("in2", "r", stdin);
#endif
    int m, a, b, c;
    scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
    FOR (i, m) {
	int u, v;
	scanf("%d%d", &u, &v);
	g0[u][v] = 1;
    }
    FOR (i, n)
	g[i][i] = 1;
    FOR (i, max(max(a, b), c)) {
	multi(g, g0);
	if (i == a) {
	    memcpy(ga, g, sizeof(ga));
	}
	if (i == b) {
	    memcpy(gb, g, sizeof(gb));
	}
	if (i == c) {
	    memcpy(gc, g, sizeof(gc));
	}
	/*
	FOR (j, n) {
	    FOR (k, n) {
		printf("%d ", g[j][k]);
	    }
	    puts("");
	}
	*/
    }
    memset(da, 0x3f, sizeof(da));
    memset(db, 0x3f, sizeof(db));
    memset(dc, 0x3f, sizeof(dc));
    da[n] = db[n] = dc[n] = 0;
    vis[n] = 1;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
	int u = q.front();
	//printf("%d %d %d %d\n", u, da[u], db[u], dc[u]);
	q.pop();
	int dd = max(max(da[u], db[u]), dc[u]);
	if (u == 1) {
	    printf("%d\n", dd);
	    return 0;
	}
	FOR (v, n) {
	    if (ga[v][u]) {
		da[v] = min(da[v], dd + 1);
	    }
	    if (gb[v][u]) {
		db[v] = min(db[v], dd + 1);
	    }
	    if (gc[v][u]) {
		dc[v] = min(dc[v], dd + 1);
	    }
	    if (da[v] <= INF && db[v] <= INF && dc[v] <= INF && !vis[v]) {
		vis[v] = 1;
		q.push(v);
	    }
	}
    }
    puts("IMPOSSIBLE");
    return 0;
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | Current Style: Cerulean.

Select Style:   Fluid Width?
 