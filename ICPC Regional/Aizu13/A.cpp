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

int n, m, s, dp[21][11][160];
int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    int flag = 0;
    while (scanf("%d%d%d", &n, &m, &s) && n) {
        dp[0][0][0] = 1;
        FOR (i, n) {
            dp[i][0][0] = 1;
            FOR (j, m) {
                FOR (k, s) {
                    dp[i][j][k] = dp[i-1][j][k] + (k>=i ? dp[i-1][j-1][k-i] : 0);
                }
            }
        }
        printf("%d\n", dp[n][m][s]);
    }
    return 0;
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | Current Style: Cerulean.

