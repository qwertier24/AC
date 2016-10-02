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


void gao ()
{
    int n , m;
    cin >> n >> m;
    if (n%2 == 0 && m%3 == 0) cout << "Yes" << endl;
    else if (n%3 == 0 && m%2 == 0) cout << "Yes" << endl;
    else if (n%6 == 0 && m > 1) cout << "Yes" << endl;
    else if (m%6 == 0 && n > 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int k;
    cin >> k;
    while (k--) gao();
    
    return 0;
}
close