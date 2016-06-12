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

#define N 1000010
LL fact[N], rfact[N];

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
void init(){
    fact[0] = 1;
    FOR(i,(1e6))
        fact[i] = fact[i-1] * i % MOD;
    rfact[0] = 1;
    FOR(i,(1e6))
        rfact[i] = rfact[i-1] * fPow(i, MOD-2) % MOD;
}
LL C(int i, int j){
    return fact[i] * rfact[j] % MOD * rfact[i-j] % MOD;
}
void add(int &x,int dx){
    x += dx;
    x %= MOD;
}
int m, w, p;
int getans(int pn,int gn,int gn2){
    return C(p,pn) * fact[pn] % MOD
        * C((w-pn) + gn -1, gn - 1) % MOD * fact[w-pn] % MOD
        * C((m-pn)+gn2-1, gn2-1) % MOD * fact[m-pn] % MOD;
}
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    init();
    scanf("%d%d%d",&m,&w,&p);
    int ans = 0;
    if(p == 0){
        if(m && w){
            puts("0");
        }else{
            printf("%d\n",fact[m+w]);
        }
        return 0;
    }
    //wwwwwwmmmm..mmm
    REP(i,(p+1)/2){
        int pn = i*2+1, gn = i + 1, gn2 = i + 1;
        add(ans, getans(pn,gn,gn2));
    }
    add(ans, ans);

    //mmmmm...mmmm
    FOR(i,p/2){
        int pn = i * 2, gn = i, gn2 = i + 1;
        add(ans, getans(pn,gn,gn2));
    }

    //wwww...www
    FOR(i,p/2){
        int pn = i * 2, gn = i + 1, gn2 = i;
        add(ans, getans(pn,gn,gn2));
    }
    
    printf("%d\n",ans);
    return 0;
}
