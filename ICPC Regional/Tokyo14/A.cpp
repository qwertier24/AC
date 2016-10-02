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

#define N 16

int n, m, b[N],c[N], a[N];

int _1(int i, int j) {
    return (i>>j)&1;
}

int dig[N], sz;
bool check(int x) {
    sz = 0;
    REP (i, n) {
	dig[i] = _1(x, i);
    }
    REP (i, n) {
	if (i && (dig[i] == dig[i-1])) {
	    c[sz-1]++;
	} else {
	    c[sz++] = 1;
	}
    }
    REP (i, m) {
	if (b[i] != c[i]) {
	    return false;
	}
	    
    }
    return true;
}

int dis[1<<N];
int bfs(int st) {
    memset(dis, -1, sizeof(dis));
    queue<int> q;
    q.push(st);
    dis[st] = 0;
    while (!q.empty()) {
	int u = q.front();
	q.pop();
	if (check(u)) {
	    return dis[u];
	}
	for (int i = 0; i < n - 1; i++) {
	    int j = _1(u,i), k = _1(u, i+1), v = u;
	    v-=j<<i;
	    v-=k<<(i+1);
	    swap(j, k);
	    v+=j<<i;
	    v+=k<<(i+1);
	    if (dis[v] == -1) {
		dis[v] = dis[u] + 1;
		q.push(v);
	    }
	}
    }
}

int main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    int st = 0;
    REP (i, n) {
	scanf("%d", &a[i]);
	st |= a[i] << i;
    }
    REP (i, m) {
	scanf("%d", &b[i]);
    }
    printf("%d\n", bfs(st));
    return 0;
}