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

int cnt_even(int l, int r) {
    return r/2 - (l-1)/2;
}
int main() {
#ifdef LOCAL
    freopen("J.in", "r", stdin);
#endif
    int n;
    ll ans = 0;
    scanf("%d", &n);
    FOR (i, n) {
	int e = cnt_even(i+1, n), o = n - i - e;
	//printf("%d %d\n", o, e);
	if (i % 2 == 1) {
	    ans += o * (ll)e;
	} else {
	    ans += e * (ll) (e - 1) / 2 + o * (ll) (o - 1) / 2;
	}
    }
    cout << ans << endl;
    return 0;
}
close