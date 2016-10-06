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

bool check(int x) {
    int lst = -1;
    while (x) {
        int c = x % 10;
        if (lst != -1 && c != lst-1)
            return false;
        x /= 10;
        lst = c;
    }
    return true;
}

#define N 1010
int a[N];
int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    int ans = -1, n;
    scanf("%d", &n);
    FOR (i, n) {
        scanf("%d", &a[i]);
        FOR (j, i - 1) {
            if (check(a[i] * a[j]))
                ans = max(ans,a[i] * a[j]);
        }
    }
    printf("%d", ans);
    return 0;
}
