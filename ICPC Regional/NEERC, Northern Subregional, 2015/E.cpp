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


char in[2333] , out[23333] ;

int main() {
    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);

    scanf("%s",in);
    int len = strlen(in) , l = 0;
    for (int i = 0 ; i < len ; ++i)
        if (in[i] == '-') {
            out[l++] = in[i++];
            out[l++] = in[i++];
            for (i ; in[i] == '0' ; ++i) {
                out[l++] = '+' ; out[l++] = in[i];
            }
            if (in[i] >= '0' && in[i] <= '9') out[l++] = '+';
            for (i ; in[i] >= '0' && in[i] <= '9' ; ++i) out[l++] = in[i];
            --i;
        }
        else out[l++] = in[i];

    out[l] = '\0';
    
    cout << out << endl;
    
    return 0;
}
close