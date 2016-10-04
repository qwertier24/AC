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

char ans[10][10000];
int main() {
    freopen("black.in", "r", stdin);
    freopen("black.out", "w", stdout);
    
    int b, w;
    char cb = '@', cw = '.';
    scanf("%d%d", &b, &w);
    if (b > w) {
        swap(b, w);
        swap(cb, cw);
    }
    if (b == 1 && w == 1) {
        printf("1 2\n");
        printf("%c%c", cb, cw);
    } else if (b == 1 && w == 2) {
        printf("1 3\n");
        printf("%c%c%c", cw, cb, cw);
    } else {
        int m = (w-1)*2, n = 4;
        REP (i, w - 1) {
            ans[0][2*i] = cb;
            ans[0][2*i+1] = cw;
        }
        REP (i, (w - 1)*2) {
            ans[1][i] = cb;
        }
        REP (i, (w-1)*2) {
            ans[2][i] = cw;
        }
        REP (i, b-1) {
            ans[3][2*i] = cb;
            ans[3][2*i+1] = cw;
        }
        REP (i, n) {
            REP (j, m) {
                if (!ans[i][j])
                    ans[i][j] = cw;
            }
        }
        printf("%d %d\n", n, m);
        REP (i,n)
            puts(ans[i]);
    }
    return 0;
}