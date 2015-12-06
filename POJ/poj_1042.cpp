#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int dp[30][400],f[30],d[30],T[30],fn[30][400]={0},t,n;
vector<int> ans;
int main()
{
	bool first_case=true;
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&t);
		ans.clear();
		memset(dp,0,sizeof(dp));
		t*=12;
		for(int i=1; i<=n; i++)
			scanf("%d",&f[i]);
		for(int i=1; i<=n; i++)
			scanf("%d",&d[i]);
		for(int i=1; i<n; i++)
			scanf("%d",&T[i]);
		T[n]=0;
		for(int i=1; i<=n; i++)
		{
			int fc=f[i];
			for(int j=1; j<=t; j++)
			{
				fn[i][j]=fn[i][j-1]+fc;
				if(fc<d[i])
					fc=0;
				else
					fc-=d[i];
			}
		}
		for(int i=n; i>=1; i--)
		{
			for(int j=1; j<=t; j++)
			{
				if(j>=T[i])
					dp[i][j]=dp[i+1][j-T[i]];
				for(int k=1; k<=j; k++)
				{
					if(j-k>=T[i])
						dp[i][j]=max(dp[i][j],dp[i+1][j-k-T[i]]+fn[i][k]);
					else
						dp[i][j]=max(dp[i][j],fn[i][k]);
				}
			}
		}
		int remain_t=t,p=1,fish_num=dp[1][t];
		//printf("   %d\n",remain_t);
		while(remain_t)
		{
			int t0=remain_t;
			if(p!=n)
				while(fn[p][t0]+(remain_t-t0>=T[p]?dp[p+1][remain_t-t0-T[p]]:0)!=fish_num)
				{
					//if(p==1)
					//printf("%d %d %d\n",p,t0,fn[p][t0]+(remain_t-t0>=T[p]?dp[p+1][remain_t-t0-T[p]]:0));
					t0--;
				}
			//printf("%d\n",t0);
			ans.push_back(t0);
			remain_t-=t0;
			if(remain_t>=T[p])
				remain_t-=T[p];
			else
				remain_t=0;
			fish_num-=fn[p][t0];
			p++;
		}
		//printf("OK");
		if(!first_case)
			printf("\n");
		else
			first_case=false;
		for(int i=0; i<ans.size()-1; i++)
			printf("%d, ",ans[i]*5);
		if(ans.size()<n)
		{
			printf("%d, ",ans[ans.size()-1]*5);
			for(int i=1; i<n-ans.size(); i++)
				printf("0, ");
			printf("0\n");
		}
		else
			printf("%d\n",ans[ans.size()-1]*5);
		printf("Number of fish expected: %d\n",dp[1][t]);
	}
	return 0;
}
/*
2

25
16
20 23 65  88 11 12 13 144 15   6 117 118  49  140  142  142  142 44 45 146  47  118  99  190  188
1  2  3   4  5   6  7  8   9  10 12  12   22  4     5    6   7   18  9  10  12  10   9    1    1
4  11 2  133 4   5  6  7   8   9 10  12   12  22    4    5   6   7  18  9   10  112  32   8

25
16
120 23 65  88 11 12 13 144 15   6 117 118  49  140  142  142  142 44 45 46  47  118  99  110  188
1  2  3   4  5   6  7  8   9  10 12  12   22  0     5    6   7   18  9  0  12  10   9    8    2
1  1  12  13 4   5  6  7   8   9 10  12   12  22    4    5   6   7  18  9   10  12  32   8

25
16
120 23 65  88 11 12 13 34 15   6 17 192  49  140  142  142  24 44 145 46  47  118  99  180  18
5  2  1   4  5   6  7  8   9  10 12  12   22  0     5    6   7   18  9  0  12  10   9    2    2
11  2  0  33 4   5  6  7   8   9 10  12   12  22    4    5   6   7  8  9   1  12  32   8

0

2
16
123 65
1  1
1

3
16
1 31 192
1 1 11
1 1

3
16
2 191 125
1 1 1
1 1

0
*/
