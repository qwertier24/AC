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

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    ll b;
    cin >> b;
    vector<int> ans;
    b--;
    for (ll a = 1; a * a <= b; a++) {
        if (b % a == 0) {
            ans.push_back(a);
            if (b / a != a) {
                ans.push_back(b/a);
            }
        }
    }
    sort(ans.begin(), ans.end());
    REP (i, ans.size())
        printf("%d ", ans[i]);
    return 0;
}
close