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
struct node{
    int t[4];
}a[55];
int lis[4][111];
int n;
int vis[210][210];
int check(int x,int y){
    if (vis[x][y]) return 0;
    if (x <= 0 || x > 202) return 0;
    if (y <= 0 || y > 202) return 0;
    for (int i = 1;i <= n;i++){
        if (x == a[i].t[0] * 2 || x == a[i].t[2] * 2){
            if (y >= a[i].t[3] * 2 && y <= a[i].t[1] * 2) return 0;
        }
        if (y == a[i].t[1] * 2 || y == a[i].t[3] * 2){
            if (x >= a[i].t[0] * 2 && x <= a[i].t[2] * 2) return 0;
        }
    }
    return 1;
}
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int x,int y){
    vis[x][y] = 1;
    for (int i = 0;i < 4;i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (check(nx,ny)) dfs(nx,ny);
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d",&n),n){
        for (int i = 1;i <= n;i++)
            for (int j = 0;j < 4;j++)
                scanf("%d",&a[i].t[j]);
        
        for (int tt = 0;tt < 2;tt++){
            lis[tt][0] = 0;
            
            for (int i = 1;i <= n;i++)
                lis[tt][i] = a[i].t[tt];
            for (int i = 1;i <= n;i++)
                lis[tt][i + n] = a[i].t[tt + 2];
            
            sort(lis[tt] + 1,lis[tt] + 2 * n + 1);
            lis[tt][0] = unique(lis[tt] + 1,lis[tt] + 2 * n + 1) - lis[tt] - 1;
            for (int t = tt;t <= tt + 2;t += 2)
                for (int i = 1;i <= n;i++)
                    a[i].t[t] = lower_bound(lis[tt] + 1,lis[tt] + lis[tt][0] + 1,a[i].t[t]) - lis[tt];
        }
        
        
        memset(vis,0,sizeof(vis));
        int cnt = 0;
        for (int i = 1;i <= 201;i++)
            for (int j = 1;j <= 201;j++)
                if (check(i,j))
                    dfs(i,j),cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}