#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<iostream>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 1000010

int maxa[N];
LL sumb[N];
int a[N],b[N],c[N];
#define T 1000001

int to[N], len[N], vis[N];
LL getlen(int u0){
    int u = u0;
    LL ret = 0;
    while(u!=T){
        if(vis[u])
            return -1;
        vis[u] = 1;
        ret += len[u];
        u = to[u];
    }
    return ret;
}
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    int n,M;
    scanf("%d%d",&n,&M);
    FOR(i,n){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        sumb[i] = sumb[i-1] + b[i];
        maxa[i] = max((LL)maxa[i-1], a[i] - sumb[i-1]);
        //printf("%d %d\n",i,maxa[i]);
    }
    REP(i,1000001){
        int dest = lower_bound(maxa+1, maxa+n+1, i) - maxa;
        if(dest == n + 1){
            to[i] = T;
            len[i] = dest - 1;
        }else{
            to[i] = max((LL)0, i + sumb[max(0,dest-1)] - c[dest]);
            len[i] = dest;
            //printf("%d %d %d %d\n", i, to[i], len[i], dest);
        }
    }
    printf("%lld\n",getlen(M));
    return 0;
}
