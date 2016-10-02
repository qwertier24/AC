#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, n) for(int i = 1; i <= (int)(n); i++)

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second

#ifdef LOCAL
#define err(x) cerr << #x << ":" << x << endl
#else
#define err(x)
#endif

#define N 10010

int mark[N];
vector<pii> merge(vector<pii> &u, vector<pii> &v, int M) {
    int p1 = 0, p2 = 0;
    vector<pii> ret;
    REP (i, M) {
	while (p1 < u.size() && mark[u[p1].second])
	    p1++;
	while (p2 < v.size() && mark[v[p2].second])
	    p2++;
	if (p1 == u.size()) {
	    ret.push_back(v[p2++]);
	} else if (p2 == v.size()) {
	    ret.push_back(u[p1++]);
	} else {
	    if (u[p1] < v[p2]) {
		ret.push_back(u[p1++]);
	    } else {
		ret.push_back(v[p2++]);
	    }
	}
	mark[ret.rbegin()->second] = 1;
    }
    REP (i, ret.size())
	mark[ret[i].second] = 0;
    return ret;
}

#define ESZ 1500010
int le[N], pe[ESZ], ev[ESZ], ew[ESZ], ecnt;
void addEdge(int u, int v, int w) {
    ecnt++;
    pe[ecnt] = le[u];
    le[u] = ecnt;
    ev[ecnt] = v;
    ew[ecnt] = w;
}

int n;
ll dis[N];
int inq[N], inq_cnt[N], pre[N];
bool spfa() {
    memset(dis, 0x3f, sizeof(dis));
    dis[n] = 0;
    queue<int> q;
    q.push(n);
    inq_cnt[n] = 1;
    inq[n] = 1;
    while (!q.empty()) {
	int u = q.front();
	q.pop();
	inq[u] = 0;
	for (int i = le[u]; i; i = pe[i]) {
	    int v = ev[i];
	    if (dis[v] > dis[u] + ew[i]) {
		dis[v] = dis[u] + ew[i];
		pre[v] = u;
		if (!inq[v]) {
		    q.push(v);
		    inq[v] = 1;
		    inq_cnt[v]++;
		    if (inq_cnt[v] == n)
			return false;
		}
	    }
	}
    }
    return true;
}

vector<int> xp[2010], yp[2010];
int x[N], y[N], M[N], D[N];

int main() {
#ifdef LOCAL
    freopen("D.in", "r", stdin);
#endif
    scanf("%d", &n);
    FOR (i, n) {
	scanf("%d%d%d%d", &x[i], &y[i], &M[i], &D[i]);
	x[i]+=1000;
	y[i]+=1000;
	xp[x[i]].push_back(i);
	yp[y[i]].push_back(i);
    }
    FOR (i, n) {
	vector<pii> v0, v1, v2, v3;
	int M = ::M[i];
	
	for (int j = x[i]; j >= 0 && (int)v0.size() < M; j--) {
	    for (auto p : xp[j]) {
		if (p == i)
		    continue;
		v0.push_back(pii(x[i] - j + 1, p));
		if ((int)v0.size() == M)
		    break;
	    }
	}

	for (int j = x[i] + 1; j <= 2000 && (int)v1.size() < M; j++) {
	    for (auto p : xp[j]) {
		if (p == i)
		    continue;
		v1.push_back(pii(j - x[i] + 1, p));
		if ((int)v1.size() == M)
		    break;
	    }
	}
	
	for (int j = y[i]; j >= 0 && (int)v2.size() < M; j--) {
	    for (auto p : yp[j]) {
		if (p == i)
		    continue;
		v2.push_back(pii(y[i] - j + 1, p));
		if ((int)v2.size() == M)
		    break;
	    }
	}
	
	for (int j = y[i] + 1; j <= 2000 && (int)v3.size() < M; j++) {
	    for (auto p : yp[j]) {
		if (p == i)
		    continue;
		v3.push_back(pii(j - y[i] + 1, p));
		if ((int)v3.size() == M)
		    break;
	    }
	}

	v0 = merge(v0, v1, M);
	v2 = merge(v2, v3, M);
	v0 = merge(v0, v2, M);
	if ((int)v0.size() != M)
	    while(true);
	
	REP (j, v0.size()) {
	    int w = floor(sqrt(v0[j].first)+0.5), u = i, v = v0[j].second;
	    if (D[u] == -1 && D[v] != -1) {
		w -= D[v];
	    } else {
		w += D[v] == -1 ? 0 : D[v];
		w += D[u] == -1 ? 0 : D[u];
	    }
	    addEdge(u, v, w);
	}
    }

    if (!spfa()) {
	puts("-1");
    } else {
	int cur = 1;
	vector<int> ans;
	while (cur) {
	    ans.push_back(cur);
	    cur = pre[cur];
	}
	for (int i = (int)ans.size() - 1; i >= 0; i--) {
	    printf("%d ", ans[i]);
	}
    }
    
    return 0;
}
close