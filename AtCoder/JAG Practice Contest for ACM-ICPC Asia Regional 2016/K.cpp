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

#define MP make_pair

#define N 100010

int ecnt, le[N], ev[N<<1], pe[N<<1], ew[N<<1];
void addEdge(int u, int v, int w) {
    ecnt++;
    pe[ecnt] = le[u];
    le[u] = ecnt;
    ev[ecnt] = v;
    ew[ecnt] = w;
}

int mark[N];
int findCore(int u, int fa, int &core, int &coreSz, int &tot) {
    int ret = 1, msz = 0;
    for (int i = le[u]; i; i = pe[i]) {
        int &v = ev[i];
        if (mark[v] || v == fa)
            continue;
        int tmp = findCore(v, u, core, coreSz, tot);
        msz = max(msz, tmp);
        ret += tmp;
    }
    if (coreSz > max(tot - ret, msz)) {
        coreSz = max(tot - ret, msz);
        core = u;
    }
    return ret;
}

int findSz(int u, int fa) {
    int ret = 1;
    for (int i = le[u]; i; i = pe[i]) {
        int &v = ev[i];
        if (mark[v] || v == fa)
            continue;
        ret += findSz(v, u);
    }
    return ret;
}

int a[N];
void dfs(int u, int fa, int dep, int len, int minUpLen, vector<pii> &up, int minDownLen, vector<pii> &down) {
    if (minUpLen >= 0) {
        up.push_back(MP(len, dep));
    }
    down.push_back(MP(minDownLen, dep));
    for (int i = le[u]; i; i = pe[i]) {
        int &v = ev[i], &w = ew[i];
        if (v == fa || mark[v])
            continue;
        dfs(v, u, dep+1, len-w+a[v], min(minUpLen-w+a[v], -w+a[v]), up, min(minDownLen, len-w), down);
    }
}

int ans = 0;
vector<pii> up[N], down[N];
vector<int> son;
set<pii> st;
set<pii>::iterator it;
void proc(int u) {

    mark[u] = 1;

    st.clear();
    st.insert(MP(0, 0));
    st.insert(MP(1<<30, -100000));
    st.insert(MP(-(1<<30), 100000));
    son.clear();
    for (int i = le[u]; i; i = pe[i]) {
        int &v = ev[i], &w = ew[i];
        if (mark[v])
            continue;
        son.push_back(v);
        vector<pii> &down = ::down[v], &up = ::up[v];
        down.clear();
        up.clear();
        dfs(v, u, 2, a[u]+a[v]-w, a[v]-w, up, a[u]-w, down);
        for (int j = 0; j < (int)down.size(); j++) {
            ans = max(ans, st.lower_bound(MP(-down[j].fi, 0))->se + down[j].se);
        }
        for (int j = 0; j < (int)up.size(); j++) {
            up[j].fi -= a[u];
            up[j].se--;
            
            it = st.lower_bound(MP(up[j].fi, 0));
            
            if (it == st.end() || it->se < up[j].se) {
                st.insert(up[j]);
                it = st.lower_bound(up[j]);
                  if (it == st.begin())
                    while (true);
                --it;
                while (it->se <= up[j].se) {
                  set<pii>::iterator it0 = it;
                  if (it == st.begin())
                    while (true);
                  --it;
                  st.erase(it0);
                }
            }
        }
    }
    ans = max(ans, st.lower_bound(MP(0, 0))->se + 1);
    
    st.clear();
    st.insert(MP(0, 0));
    st.insert(MP(1<<30, -100000));
    st.insert(MP(-(1<<30), 100000));
    for (int i = int(son.size())-1; i>=0; i--) {
        int &v = son[i];
        vector<pii> &down = ::down[v], &up = ::up[v];
        for (int j = 0; j < (int)down.size(); j++) {
            ans = max(ans, st.lower_bound(MP(-down[j].fi, 0))->se + down[j].se);
        }
        
        for (int j = 0; j < (int)up.size(); j++) {

            it = st.lower_bound(MP(up[j].fi, 0));
            
            if (it == st.end() || it->se < up[j].se) {
                st.insert(up[j]);
                it = st.lower_bound(up[j]);
                  if (it == st.begin())
                    while (true);
                --it;
                while (it->se <= up[j].se) {
                  set<pii>::iterator it0 = it;
                  if (it == st.begin())
                    while (true);
                  --it;
                  st.erase(it0);
                }
            }
        }
    }
    
    for (int i = le[u]; i; i = pe[i]) {
        int &v = ev[i];
        if (mark[v])
            continue;
        int core, coreSz = 1<<30, tot = findSz(v, u);
        findCore(v, u, core, coreSz, tot);
        proc(core);
    }
}

int main() {
#ifdef QWERTIER
    freopen("in.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    FOR (i, n)
        scanf("%d", &a[i]);
    FOR (i, n - 1) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    int core, coreSz = n;
    findCore((n+1)/2, 0, core, coreSz, n);
    proc(core);
    printf("%d", ans);
    return 0;
}
