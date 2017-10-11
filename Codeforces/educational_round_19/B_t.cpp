#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100005;
int n,a[maxn],dp[maxn][2];
int main()
{
  freopen("in.txt", "r", stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    dp[0][1]=-0x3f3f3f3f;
    for (int i=1;i<=n;++i)
        if (a[i]&1) {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+a[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+a[i]);
        } else {
            dp[i][0]=max(dp[i-1][0],dp[i-1][0]+a[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][1]+a[i]);
        }
    printf("%d\n",dp[n][1]);
    return 0;
}
