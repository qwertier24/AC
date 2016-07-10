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
#define MOD 1000000007

typedef pair<int,int> pii;
#define MP make_pair

#define N 1000010

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
LL fact[N], rfact[N], p2[N];
void init(){
    fact[0] = 1;
    FOR(i,100000)
        fact[i] = fact[i-1] * i % MOD;
    rfact[0] = 1;
    FOR(i,100000)
        rfact[i] = rfact[i-1] * fPow(i, MOD - 2) % MOD;
    p2[0] = 1;
    FOR(i,1000000)
        p2[i] = p2[i-1] * 2 % MOD;
}
LL C(int i, int j){
    return fact[i] * rfact[j] % MOD * rfact[i-j] % MOD;
}
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    init();
    int n,k;
    scanf("%d%d",&n,&k);
    int ans = 1 + n;
    for(int i = 2; i <= k; i++){
        ans = (ans + p2[i-2] * (n-i+1) % MOD) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}
