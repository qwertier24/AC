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

#define N 10010
#define M 20

int n, m, l;
bool dp[N][M];

int a[N];

int ch[N*31][2], cnt[N*31], sz;
void erase(int x){
    int u = 0;
    for(int i = 29; i>=0; i--){
        int c = (x>>i)&1;
        cnt[u] -- ;
        u = ch[u][c];
    }
    cnt[u] --;
}
void insert(int x){
    int u = 0;
    for(int i = 29; i>=0; i--){
        int c = (x>>i)&1;
        cnt[u]++;
        if(!ch[u][c]){
            ch[u][c] = ++sz;
            ch[sz][0] = ch[sz][1] = 0;
            cnt[sz] = 0;
        }
        u = ch[u][c];
    }
    cnt[u] ++;
}
int find(int x){
    int u = 0;
    if(!cnt[u])
        return 0;

    int ret = 0;
    for(int i = 29; i>=0; i--){
        int c = (x>>i)&1;
        if(ch[u][c^1] && cnt[ch[u][c^1]]){
            u = ch[u][c^1];
            ret<<=1;
            ret+=1;
        }else{
            u = ch[u][c];
            ret <<=1;
        }
    }
    return ret;
}
bool check(int x){
    dp[0][0] = 1;
    FOR(j,m){
        memset(ch[0],0,sizeof(ch[0]));
        cnt[0] = 0;
        sz = 0;
        FOR(i,n){
            if(dp[i-1][j-1])
                insert(a[i-1]);
            if(i-l-1 >= 0 && dp[i-l-1][j-1])
                erase(a[i-l-1]);
            dp[i][j] = (find(a[i]) >= x);
        }
    }
    return dp[n][m];
}
int main(){
#ifdef QWERTIER
    freopen("D.in","r",stdin);
#endif 
    int T;
    scanf("%d",&T);
    FOR(kase,T){
        scanf("%d%d%d",&n,&m,&l);
        FOR(i,n){
            scanf("%d",&a[i]);
            a[i] ^= a[i-1];
        }
        int lo = 0, hi = (~0u>>1);
        while(lo < hi){
            int mi = ((LL)lo + (LL)hi + 1) >> 1;
            if(check(mi))
                lo = mi;
            else
                hi = mi -1;
        }
        printf("Case #%d:\n%d\n",kase,lo);
    }
    return 0;
}
