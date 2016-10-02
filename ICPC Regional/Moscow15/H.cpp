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


char s[33] ;
int getnum ()
{
    scanf("%s",s);
    if (s[0] >='A' && s[0] <= 'Z') s[0] = s[0]-'A'+10;
    else s[0] = s[0] - '0';
    if (s[1] >= 'A' && s[1] <= 'Z') s[1] = s[1] - 'A' + 10;
    else s[1] = s[1] - '0';
    return s[0]*16+s[1];
}

int a[100005] ;
ll F[2][12345] ;
int main() {
    int MAXN = 30;

    int n ; cin >> n;
    MAXN = min(n,(n+100000000)/n);
    
    ll res = 0;
    FOR(i,n) a[i] = getnum ();
    
    FOR(i,n) {
        if (i <= MAXN) F[i&1][i] = 0;
        F[i&1][0] = F[(i-1)&1][0] + ((i-1)^(a[i]));
        for (int j = 1 ; j <= MAXN && j < i ; ++j)
            F[i&1][j] = max(F[(i-1)&1][j-1],F[(i-1)&1][j] + ((i-j-1)^a[i]));
    }
    REP(i,MAXN+1) res = max(res,F[n&1][i]);
        
    cout << res << endl;

    return 0;
}
close