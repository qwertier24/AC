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

#define MOD 1000000007
#define N 100010
LL fPow(LL t,int p){
    LL ret = 1;
    while(p){
        if(p&1)
            ret = ret * t % MOD;
        t = t * t % MOD;
        p>>=1;
    }
    return ret;
}


LL fact[N],rfact[N];
LL rp26[N],p25[N];
void init(){
    fact[0] = 1;
    FOR(i,100000)
        fact[i] = fact[i-1] * i % MOD;
    rfact[0] = 1;
    FOR(i,100000)
        rfact[i] = fPow(fact[i], MOD - 2);
    p25[0]=1;
    FOR(i,100000)
        p25[i] = p25[i-1] * 25 % MOD;
    rp26[0]=1;
    rp26[1] = fPow(26, MOD-2);
    FOR(i,100000)
        rp26[i] = rp26[i-1] * rp26[1] % MOD;
}
LL get(int l,int n){
    return fact[n-1] * rfact[n-l] % MOD * rfact[l-1] % MOD * p25[n-l] % MOD * rp26[n-l] % MOD;
}
LL sum[N];
void gao(int l){
    memset(sum,0,sizeof(sum));
    for(int i = l; i<= 100000; i++){
        sum[i] = (sum[i-1] + get(l,i)) % MOD;
    }
}

vector<pii> q[N];
char s[N];
int ans[N];
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    init();
    int Q;
    scanf("%d%s",&Q,s);
    int curl = strlen(s);
    memset(ans,-1,sizeof(ans));
    FOR(i,Q){
        int op;
        scanf("%d",&op);
        if(op == 1){
            scanf("%s",s);
            curl = strlen(s);
        }else{
            int n;
            scanf("%d",&n);
            q[curl].push_back(MP(n,i));
        }
    }
    FOR(i,100000){
        if(!q[i].size())
            continue;
        gao(i);
        for(auto query:q[i]){
            int n = query.first;
            if(n<i)
                ans[query.second] = 0;
            else
                ans[query.second] = sum[n] * fPow(26, n-i) % MOD;
        }
    }
    FOR(i,Q)if(ans[i]!=-1)
        printf("%d\n",ans[i]);
    return 0;
}

