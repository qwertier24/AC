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

#define N 100010
int dp[N],a[N];
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        dp[0]=0;
        int n;
        scanf("%d",&n);
        FOR(i,n){
            if(i!=n)scanf("%d",&a[i]);
            else a[i]=0;
            dp[i]=dp[i-1];
            for(int j=1; j>=1; j--)
                dp[i]=max(a[i-j]+dp[i-j*2],dp[i]);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
 