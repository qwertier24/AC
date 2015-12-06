#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#define maxn 200
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
int color[maxn+10],cnt[maxn+10],d[maxn+10][maxn+10][maxn+10],bn,calc_cnt=0;
int dp(int l,int r,int b)
{
	if(r<l)
		return 0;
	if(d[l][r][b]!=-1)
		return d[l][r][b];
	calc_cnt++;
	int& ret=d[l][r][b];
	ret=dp(l,r-1,0)+(cnt[r]+b)*(cnt[r]+b);
	For(i,l,r-1)
		if(color[i]==color[r])
			ret=max(ret,dp(l,i,b+cnt[r])+dp(i+1,r-1,0));
	return ret;
}
int main()
{
	int T,n;
	scanf("%d",&T);
	For(kase,1,T){
		bn=0;
		scanf("%d",&n);
		For(i,1,n){
			int t;
			scanf("%d",&t);
			if(t==color[bn]){
				cnt[bn]++;
			}
			else{
				bn++;
				cnt[bn]=1;
				color[bn]=t;
			}
		}
		memset(d,-1,sizeof(d));
		printf("Case %d: %d\n",kase,dp(1,bn,0));
	}
	return 0;
}
