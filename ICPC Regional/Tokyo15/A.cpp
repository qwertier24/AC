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

const int m = 1000000;
#define N 1010

int mark[m+1], a[N];
int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    FOR (i, n) {
	scanf("%d", &a[i]);
    }
    FOR (i, n) {
	if (a[i] != 0) {
	    int s = a[i];
	    mark[s] = 1;
	    for (int j = i + 1; j <= n; j++) {
		s = s * 10 + a[j];
		if (s > m)
		    break;
		mark[s] = 1;
	    }
	} else {
	    mark[0] = 1;
	}
    }
    int ans = 0;
    while (mark[ans])
	ans++;
    printf("%d\n", ans);
    return 0;
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | Current Style: Cerulean.

Select Style:   Fluid Width?
 