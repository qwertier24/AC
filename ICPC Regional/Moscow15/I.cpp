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
int a[2020];int n;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d",&n);
    for (int i = 1;i <= n;i++){
        int beg,end;
        scanf("%d%d",&beg,&end);
        for (int j = beg;j <=end;j++)
            a[j]++;
    }
    int tm = 0,o = 1;;
    for (int i = 1;i <= 180;i++)
        tm += a[i];
    if (tm > 90) o = 0;
    for (int i = 181;i <= 1826 && o;i++){
        tm += a[i] - a[i - 180];
        if (tm > 90) o = 0;
    }
    if (o) printf("Yes\n");else printf("No\n");
    return 0;
}
close