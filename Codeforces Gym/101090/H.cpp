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

int Arr[100005] ;
char str[100005] ;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    memset(Arr,-1,sizeof(Arr));
    int ans1 = -1 , ans2 = -1 , k;
    cin >> k >> str;
    int len = strlen(str);
    for (int i = 0 ; i < len ; ++i)
	if (str[i] == '1') {
	    if (Arr[(i-1+k)%k] != -1) {
		ans1 = Arr[(i-1+k)%k];
		ans2 = i;
		break;
	    }
	    Arr[i%k] = i;
	}
    cout << ans1 + 1 << ' ' << ans2 + 1 << endl;
    
    return 0;
}
close