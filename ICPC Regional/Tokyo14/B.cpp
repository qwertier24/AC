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

char str[233] ;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    int res , r1 , r2;
    cin >> str >> res;
    int len = strlen(str);
    r1 = str[0] - '0';
    for (int i = 1 ; i < len ; i += 2)
	if (str[i] == '+') r1 += str[i+1] - '0';
        else r1 *= str[i+1] - '0';
    r2 = 0; int b = str[0]-'0';
    for (int i = 1 ; i < len ; i += 2)
	if (str[i] == '+')
	{
	    r2 += b; b = str[i+1] - '0';
	}
        else b *= str[i+1] - '0';
    r2 += b;

    if (r1 == res && r2 == res) cout << "U" << endl;
    else if (r1 == res) cout << "L" << endl;
    else if (r2 == res) cout << "M" << endl;
    else cout << "I" << endl;
    
    return 0;
}