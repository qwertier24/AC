#include<stdio.h>
#include<algorithm>
#include<set>
#include<map>
#include<queue>

#define FOR(i,n) for(int i=1; i<=n; i++)
#define REP(i,n) for(int i=0; i<n; i++)

using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

typedef long long LL;

int dp[510];
int c[110],v[110],ti[20];
int n,m;
bool check(int l,int r){
    FOR(i,n)
        if(l<ti[i] && ti[i]<r)
            return false;
    return true;
}

int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        int L;
        scanf("%d%d%d",&L,&n,&m);
        FOR(i,n)scanf("%d",&ti[i]);
        FOR(i,m)scanf("%d%d",&c[i],&v[i]);
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=L; i++){
            dp[i]=dp[i-1];
            for(int j=1; j<=m; j++)
                if(i>=c[j] && check(i-c[j],i))
                    dp[i]=max(dp[i],dp[i-c[j]]+v[j]);
        }
        printf("%d\n",dp[L]);
    }

    return 0;
}