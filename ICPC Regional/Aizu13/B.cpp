#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, n) for(int i = 1; i <= n; i++)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
#define fi first
#define se second
#define pb push_back
#define MP make_pair

#ifdef LOCAL
#define err(x) cerr << #x << ":" << x << endl
#else
#define err(x)
#endif

int L;
pip proc(vector<pip> &v) {
    if (v.size() == 0)
        return MP(0, MP(0, 0));
    // 1 means L, 0 means R
    int L=0, Li=-1, R=0, Ri=(int)v.size();
    for (int i = 0; i < v.size(); i++) {
        pip x = v[i];
        if (x.first == -1) {
            L = x.second.first;
            Li++;
        }
    }
    for (int i = int(v.size()) - 1; i >= 0; i--) {
        pip x = v[i];
        if (x.first == 1) {
            R = ::L - x.second.first;
            Ri--;
        }
    }
    if (L>=R) {
        return MP(L, MP(1, v[Li].second.second));
    } else {
        return MP(R, MP(0, v[Ri].second.second));
    }
}

int n, l, a[1000];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    while (scanf("%d%d", &n, &L) && n) {
        vector<pip> v0, v1;
        FOR (i, n) {
            char dir;            
            scanf(" %c%d", &dir, &a[i]);
            int d = dir == 'L' ? -1 : 1;
            if (a[i] % 2 == 0) {
                v0.pb(MP(d, MP(a[i], i)));
            } else {
                v1.pb(MP(d, MP(a[i], i)));
            }
        }
        pip ans = max(proc(v0), proc(v1));
        printf("%d %d\n", ans.first, ans.second.second);
    }
    return 0;
}