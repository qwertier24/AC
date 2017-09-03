#include <bits/stdc++.h>
const int MOD = 998244353;
int dp[100010];
void init()
{
  memset(dp,0,sizeof(dp)); dp[0] = 1;
  for(int i = 1;i <= 100000;i++)
    {
      for(int j = 1, r = 1; i - (3 * j * j - j) / 2 >= 0; j++, r *= -1)
        {
          dp[i] += dp[i -(3 * j * j - j) / 2] * r; dp[i] %= MOD;
          dp[i] = (dp[i]+MOD)%MOD;
          if( i - (3 * j * j + j) / 2 >= 0 )


            {
              dp[i] += dp[i - (3 * j * j + j) / 2] * r; dp[i] %= MOD;
              dp[i] = (dp[i]+MOD)%MOD;
            }
        }
    }
}
int main()
{
  freopen("in.txt", "r", stdin);
  int T; int n; init();
  scanf("%d",&T);
  while(T--)
    {
      scanf("%d",&n);
      printf("%d\n",dp[n]);
    }
  return 0;
}
