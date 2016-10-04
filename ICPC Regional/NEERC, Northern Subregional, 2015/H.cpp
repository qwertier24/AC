#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, n) for(int i = 1; i <= n; i++)

typedef long long ll;
typedef pair<int,int> pii;


#ifdef LOCAL
#define err(x) cerr << #x << ":" << x << endl
#else
#define err(x)
#endif

char str[2333] ;

int main() {
    freopen("hash.in", "r", stdin);
    freopen("hash.out", "w", stdout);

    int n ; cin >> n;
    
    for (int i = 0 ; i < n ; ++i) str[i] = 'b';
    str[n] = '\0';
    printf("%s\n",str);
    for (int i = 1 ; i < n ; ++i) {
        str[i-1] = 'c'; str[i] = 'C';
        printf("%s\n",str);
        str[i-1] = str[i] = 'b';
    }
    
    return 0;
}
close