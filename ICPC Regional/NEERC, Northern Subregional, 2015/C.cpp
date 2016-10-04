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

#define N 100010

char a[N], b[N];
int na, nb, ca[26], cb[26];
int main() {
    freopen("concatenation.in", "r", stdin);
    freopen("concatenation.out", "w", stdout);
    scanf("%s%s", a, b);
    int na = strlen(a), nb = strlen(b);
    FOR (i, na-1) {
        ca[a[i]-'a']++;
    }
    REP (i, nb-1) {
        cb[b[i]-'a']++;
    }
    ll ans = na * (ll) nb;
    REP (i, 26)
        ans -= ca[i] * (ll)cb[i];
    cout << ans;
    return 0;
}
close