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

#define N 210

int n, m;
double p[N*2],dp[2][N];
double calc(int st){
    int cur = 0, lst = 1;
    double *a = p + st;
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    int cnt = 0;
    REP(i,m){
        cnt++;
        cur ^= 1;
        lst ^= 1;
        dp[cur][0] = dp[lst][0] * (1-a[i]);
        FOR(j,cnt){
            dp[cur][j] = dp[lst][j-1] * a[i] + dp[lst][j] * (1-a[i]);
        }
    }
    return dp[cur][m/2];
}

int main(){
#ifdef QWERTIER
    freopen("B_l2.in","r",stdin);
    freopen("B_l2.out","w",stdout);
#endif 
    int T;
    scanf("%d",&T);
    FOR(kase,T){
        printf("Case #%d: ",kase);
        scanf("%d%d",&n,&m);
        REP(i,n)scanf("%lf",&p[i]);
        sort(p,p+n);
        REP(i,n)p[i+n] = p[i];
        double ans =0;
        REP(i,n*2-m+1){
            //printf("%d %d\n",i,i+m-1);
            ans = max(ans, calc(i));
        } 
        printf("%.10f\n",ans);
    }
    return 0;
}
