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
    int m, n;
    scanf("%d", &m);
    for (n = 1; n*(n+1)/2<m; n++);
    int rgt = 0, remL = n, remR = n;
    n *= 2;
    for (int i = 1; i <= n; i++) {
        int rem = (n-i+rgt-1)/2;
        //printf("%d %d %d %d %d ", rem, rgt, remL, remR, m);
        if (rgt && remL && rgt + rem * (rem + 1) / 2 >= m) {
            m -= rgt;
            rgt--;
            putchar('(');
            remL--;
        } else {
            rgt++;
            putchar(')');
            remR--;
        }
        //puts("");
    }
    return 0;
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | Current Style: Cerulean.

Select Style:   Fluid Width?
 
