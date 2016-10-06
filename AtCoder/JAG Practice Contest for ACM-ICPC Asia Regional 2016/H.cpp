#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, n) for(int i = 1; i <= n; i++)

typedef long long LL;
typedef long long ll;
typedef pair<int,int> pii;

#ifdef LOCAL
#define err(x) cerr << #x << ":" << x << endl
#else
#define err(x)
#endif

vector<int> DOG[10004] ;
bool visit[10004] ;

int main() {
    int w , h , k , n , x , y ; cin >> w >> h >> k >> n;

    FOR(i,n) {
        scanf("%d%d",&x,&y);
        DOG[y].push_back(x);
    }

    k -= (w + 1) / 2;
    if (k < 0) {
        cout << -1 << endl;
    }
    else {
        int ans = 0;
        for (int x = 2 ; x < h ; x += 2) {
            memset(visit,0,sizeof(visit));
            for (int i = 0 ; i < DOG[x].size() ; ++i)
                visit[DOG[x][i]] = true;
            visit[0] = visit[w+1] = true;
            bool flag = false , flag2 = false;
            for (int i = 1 ; i <= w ; i += 2) {
                if (i > 1 && flag2 && visit[i-1] == 0)
                    ans += 1;
                else if (flag && visit[i-1] == 0)
                    ans += 1;
                else if (visit[i] == 0) {
                    ans += 1;
                    flag = false;
                    flag2 = !visit[i+1];
                }
                else if (i < w && visit[i+1] == 0) {
                    i += 2;
                    ans += 2;
                    flag = false;
                    flag2 = false;
                }
                else if (k > 0) {
                    --k;
                    flag = true;
                    flag2 = false;
                }
                else {
                    ans += 2;
                    flag = false;
                    flag2 = false;
                }
            }
        }

        if (k > 0) ans = max(0,ans-k);
        
        cout << ans << endl;
    }
    
    return 0;
}
