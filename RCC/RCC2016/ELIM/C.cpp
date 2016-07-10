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

#define N 200010
#define MOD 1000000007
int mind = 1<<30, minu = 0;
int maxd[N][2];
vector<int> adj[N];
void update(int u, int d){
    if(maxd[u][0] <= d){
        maxd[u][1] = maxd[u][0];
        maxd[u][0] = d;
    }else if(maxd[u][1] < d){
        maxd[u][1] = d;
    }
}
void dfs(int u,int fa){
    maxd[u][0] = maxd[u][1] = 0;
    for(auto &v : adj[u]){
        if(v == fa)continue;
        dfs(v,u);
        int d = maxd[v][0] + 1;
        update(u, d);
    }
}
int deg[N];
void dfs2(int u,int fa){
    if(fa){
        if(maxd[fa][0] == maxd[u][0] + 1){
            update(u, maxd[fa][1] + 1);
        }else{
            update(u, maxd[fa][0] + 1);
        }
    }
    if(deg[u] < 3 && (maxd[u][0] < mind || (maxd[u][0] == mind && u < minu))){
        minu = u;
        mind = maxd[u][0];
    }
    for(auto &v : adj[u]){
        if(v == fa)continue;
        dfs2(v,u);
    }
    //printf(" %d %d %d %d\n", u, maxd[u][0],mind,minu);
}
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d",&n);
        mind = 1<<30;
        minu = -1;
        FOR(i,n)
            adj[i].clear(),deg[i]=0;
        FOR(i,n-1){
            int u,v;
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u] ++;
            deg[v]++;
        }
        int flag = 0;
        FOR(i,n){
            if(deg[i] > 3){
                puts("-1");
                flag = 1;
                break;
            }
        }
        if(flag)continue;
        dfs(1,0);
        dfs2(1,0);
        int add = 1;
        FOR(i,mind + 1)
            add = add * 2 % MOD;
        add = (add - 1) % MOD;
        add = (add - n + MOD) % MOD;
        printf("%d %d\n", minu, add);
    }
    return 0;
}
