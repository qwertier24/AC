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

#define N 100010
#define MOD 1000000009
int n,a[N],vis[N];

LL fPow(LL t, int p){
    LL ret = 1;
    while(p){
        if(p&1)ret = ret * t % MOD;
        t = t *t % MOD;
        p>>=1;
    }
    return ret;
}
LL rfact[N],fact[N];
void init(){
    rfact[0] = 1;
    FOR(i,100000){
        rfact[i] = rfact[i-1] * fPow(i, MOD - 2) % MOD;
    }
    fact[0] = 1;
    FOR(i,100000)
        fact[i] = fact[i-1] * i % MOD;
}
LL A(int i, int j){
    return fact[i] * rfact[i - j] % MOD;
}
int main(){
#ifdef QWERTIER
    freopen("c1.in","r",stdin);
    //freopen("c1.out","w",stdout);
#endif 
    init();
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        FOR(i,n){
            scanf("%d",&a[i]);
        }
        LL ans = 1;
        int tot = 0;
        memset(vis,0,sizeof(vis));
        FOR(i,n){
            if(vis[i])continue;
            int p = i, curs = 0;
            while(!vis[p]){
                vis[p] = 1;
                p = a[p];
                curs++;
            }
            printf("curs:%d\n",curs);
            tot += curs - 1;
            ans = ans * rfact[curs - 1] % MOD;
            if(curs >= 2)
                ans = ans * A(curs, curs - 2) % MOD;
        }
        ans = ans * fact[tot] % MOD;
        printf("%d\n", (int)ans);
    }
    return 0;
}
