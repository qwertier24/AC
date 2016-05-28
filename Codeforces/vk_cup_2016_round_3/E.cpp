#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define M 50
#define N 500010

int n = 1, Q;
pii q[N];

vector<int> adj[N];
int fa[N];
void dfs(int u,int f){
    for(auto &v : adj[u]){
        if(v == f)continue;
        fa[v] = u;
        dfs(v,u);
    }
}


double dp[N][M+10];
int cnt[N][M+10];
double query(int u){
    double ret = 0;
    FOR(i,M)
        ret += (dp[u][i] - dp[u][i-1]) * i;
    return ret;
}
void insert(int u){
    int f = u, gf = fa[u];
    dp[f][0] = 1;
    FOR(i,M)
        dp[f][i] = 1;
    double tmp = 1;
    REP(i,M){
        if(!gf || !f)
            break;
        double tmp2 = dp[gf][i] * .5 + .5;
        dp[gf][i] = dp[gf][i] / tmp * ((i?dp[f][i - 1]:0) * .5 + .5);
        gf = fa[gf];
        f = fa[f];
        tmp = tmp2;
    }
}

int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    scanf("%d",&Q);
    FOR(i,Q){
        int op, u;
        scanf("%d%d",&op,&u);
        q[i] = MP(op,u);
        if(op == 1){
            q[i] = MP(op, ++n);
            adj[u].push_back(n);
        }else{
            q[i] = MP(op,u);
        }
    }
    REP(i,M+1)
        dp[1][i] = 1;
    dfs(1,0);
    FOR(i,Q){
        int op = q[i].first, u = q[i].second;
        if(op == 1)
            insert(u);
        else
            printf("%.10f\n", query(u));
    }
    return 0;
}
