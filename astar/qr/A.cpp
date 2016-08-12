#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

#define MOD 9973

int rev(int a){
    int p = MOD - 2, ret = 1;
    while(p){
        if(p&1)
            ret = ret * a % MOD;
        a = a * a % MOD;
        p>>=1;
    }
    return ret;
}

#define N 100010
char s[N];
int h[N];
int main(){
#ifdef QWERTIER
    freopen("in","r",stdin);
#endif
    int Q;
    while(scanf("%d%s",&Q,s)!=EOF){
        int n = strlen(s);
        REP(i,n){
            if(i)
                h[i] = h[i-1] * (s[i] - 28) % MOD;
            else
                h[i] = s[i]-28;
        }
        REP(i,Q){
            int l, r;
            scanf("%d%d",&l,&r);
            l--, r--;
            if(l)
                printf("%d\n",h[r] * rev(h[l-1]) % MOD);
            else
                printf("%d\n",h[r]);
        }
    }
    return 0;
}
