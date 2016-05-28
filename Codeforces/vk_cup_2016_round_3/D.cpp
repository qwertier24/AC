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
typedef pair<LL,int> pli;
#define MP make_pair
#define N 100010

LL sum[N], a[N];
int deg[N], fa[N];
set<pli> st[N], global;
inline LL income(int u){
    return sum[u] + a[fa[u]] / (deg[fa[u]] + 2);
}
inline LL divi(int u){
    return a[u] / (deg[u] + 2);
}

void global_insert(int u){
    if(st[u].size()){
        global.insert(MP(st[u].begin()->first+divi(u), st[u].begin()->second));
        global.insert(MP(st[u].rbegin()->first+divi(u), st[u].rbegin()->second));
    }
}
void global_erase(int u){
    if(st[u].size()){
        global.erase(MP(st[u].begin()->first+divi(u), st[u].begin()->second));
        global.erase(MP(st[u].rbegin()->first+divi(u), st[u].rbegin()->second));
    }
}

void erase(int u, int v){
    st[u].erase(MP(sum[v], v));
}
void insert(int u, int v){
    st[u].insert(MP(sum[v], v));
}

void modify(int u, int v){
    int w = fa[u];

    global_erase(w);
    global_erase(fa[w]);
    global_erase(fa[fa[w]]);
    global_erase(v);
    global_erase(fa[v]);
    global_erase(fa[fa[v]]);
    
    erase(w,u);
    erase(fa[w], w);
    erase(fa[fa[w]], fa[w]);
    erase(fa[v], v);
    erase(fa[fa[v]], fa[v]);

    sum[fa[w]] -= divi(w);
    sum[w] -= divi(u) + a[w] - divi(w) * (deg[w]+1);
    sum[fa[v]] -= divi(v);
    sum[v] -= a[v] - divi(v) * (deg[v] + 1);
    deg[w] --;
    deg[v] ++;
    sum[w] += a[w] - divi(w) * (deg[w] + 1);
    sum[fa[w]] += divi(w);
    sum[v] += a[v] - divi(v) * (deg[v] + 1) + divi(u);
    sum[fa[v]] += divi(v);
    


    insert(v, u);
    insert(fa[v], v);
    insert(fa[fa[v]], fa[v]);
    insert(fa[w], w);
    insert(fa[fa[w]], fa[w]);

    global_insert(w);
    global_insert(fa[w]);
    global_insert(fa[fa[w]]);
    global_insert(v);
    global_insert(fa[v]);
    global_insert(fa[fa[v]]);

    fa[u] = v;
}

int n;
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    int Q;
    scanf("%d%d",&n,&Q);
    FOR(i,n){
        scanf("%I64d",&a[i]);
    }
    FOR(i,n){
        scanf("%d",&fa[i]);
        deg[fa[i]] ++;
    }
    FOR(i,n){
        sum[i] += a[i] - divi(i) * (deg[i] + 1);
        sum[fa[i]] += divi(i);
    }
    FOR(i,n)
        insert(fa[i], i);
    FOR(i,n)
        global_insert(i);
    while(Q--){
        int op, u, v;
        scanf("%d",&op);
        if(op == 1){  // 1 i -> j
            scanf("%d%d",&u,&v);
            modify(u,v);
        }else if(op==2){ // 2 i
            scanf("%d",&u);
            printf("%I64d\n", income(u));
        }else{ // 3 
            printf("%I64d %I64d\n", global.begin()->first, global.rbegin()->first);
        }
    }
    return 0;
}
