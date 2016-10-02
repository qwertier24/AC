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

char Arr[33333] ; int len[10]  ;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    Arr[1] = '0' , len[0] = 1;
    for (int i = 1 ; i < 10 ; ++i) {
	len[i] = len[i-1] * 3 + 1;
	for (int j = len[i-1] + 1 ; j <= len[i-1] * 2 + 1 ; ++j)
	    Arr[j] = i+'0';
	for (int j = len[i-1]*2+2 ; j <= len[i-1]*3+1 ; ++j)
	    Arr[j] = Arr[j-len[i-1]*2-1];
    }

    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; ++i)
	putchar(Arr[i]);
    cout << endl;
	
    return 0;
}
close