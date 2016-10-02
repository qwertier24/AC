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

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    //try x
    int l = 0, r = 1e9,mid,ansx = -1,ansy = -1;
    while (l <= r){
        int dp,dm;
        mid = (l+r) >> 1;
        printf("%d 0\n",mid);
        fflush(stdout);
        scanf("%*d");
        if (mid < 1e9){
            printf("%d 0\n",mid+1);
            fflush(stdout);
            scanf("%d",&dp);
        }else dp = 0;
        printf("%d 0\n",mid);
        fflush(stdout);
        scanf("%*d");
        if (mid > 1){
            printf("%d 0\n",mid-1);
            fflush(stdout);
            scanf("%d",&dm);
        }else dm = 0;
        if (dm == 0 && dp == 0){ansx = mid;break;}
        if (dp == 1) l = mid + 1;
        else r = mid - 1;
    }
    l = 0,r = 1e9;
    while (l <= r){
        int dp,dm;
        mid = (l+r) >> 1;
        printf("%d %d\n",ansx,mid);
        fflush(stdout);
        scanf("%*d");
        if (mid < 1e9){
            printf("%d %d\n",ansx,mid + 1);
            fflush(stdout);
            scanf("%d",&dp);
        }else dp = 0;
        printf("%d %d\n",ansx,mid);
        fflush(stdout);
        scanf("%*d");
        if (mid > 1){
            printf("%d %d\n",ansx,mid - 1);
            fflush(stdout);
            scanf("%d",&dm);
        }else dm = 0;
        if (dm == 0 && dp == 0){ansy = mid;break;}
        if (dp == 1) l = mid + 1;
        else r = mid - 1;
    }
    printf("A %d %d\n",ansx,ansy);
    return 0;
}
close