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

#define N 200010
int deg[N], ans[N];
vector<int> adj[N];
int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    FOR (i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        deg[u]++;
        adj[v].push_back(u);
    }
    priority_queue<int> pq;
    FOR (i, n) {
        if (deg[i] == 0) {
            pq.push(i);
        }
    }
    for (int i = n; i >= 1; i--) {
        int u = pq.top();
        pq.pop();
        ans[i] = u;
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            deg[v]--;
            if (deg[v] == 0) {
                pq.push(v);
            }
        }
    }
    FOR (i, n)
        printf("%d%s", ans[i], i==n?"":" ");
    return 0;
}
close