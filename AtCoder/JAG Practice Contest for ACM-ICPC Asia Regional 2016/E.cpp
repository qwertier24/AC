#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, n) for(int i = 1; i <= n; i++)

typedef long long ll;
typedef long long LL;
typedef pair<int,int> pii;
#define first fi
#define second se

#ifdef LOCAL
#define err(x) cerr << #x << ":" << x << endl
#else
#define err(x)
#endif

const int MAXN = 100005 , PRIME = 23333;

int edge[MAXN][2] , head[MAXN] , maxe = 1;
LL HASH[MAXN] ;
void add_edge (int u , int v)
{
    edge[maxe][0] = v;
    edge[maxe][1] = head[u];
    head[u] = maxe++;
}

LL dfs (int p)
{
    HASH[p] = 1;
    for (int i = head[p] ; i ; i = edge[i][1])
        HASH[p] += dfs(edge[i][0])*PRIME;
    return HASH[p];
}

int main() {
    int n , u , v ; cin >> n;
    FOR(i,n-1) {
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    
    dfs(1);

    map<int,int> m;

    LL ans = 0;
    FOR(i,n) {
        ans += m[HASH[i]];
        ++m[HASH[i]];
    }
    cout << ans << endl;
    
    return 0;
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | Current Style: Cerulean.

Select Style:   Fluid Width?
 
