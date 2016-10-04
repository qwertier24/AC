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
int n,m,ans;
int a[111][111];
int main() {
    freopen("lucky.in","r",stdin);
    freopen("lucky.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            scanf("%d",&a[i][j]);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++){
            int o = 1;
            for (int k = 1;k < i;k++)
                if (a[k][j] >= a[i][j]) {o = 0;break;}
            ans += o;o = 1;
            for (int k = i + 1;k <= n;k++)
                if (a[k][j] >= a[i][j]) {o = 0;break;}
            ans += o;o = 1;
            for (int k = 1;k < j;k++)
                if (a[i][k] >= a[i][j]) {o = 0;break;}
            ans += o;o = 1;
            for (int k = j + 1;k <= m;k++)
                if (a[i][k] >= a[i][j]) {o = 0;break;}
            ans += o;
        }
    cout << ans << endl;
    return 0;
}
close