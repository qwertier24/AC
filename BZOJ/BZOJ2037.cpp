#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB
using namespace std;
typedef int LL;
#define N 1010
#define x first
#define v second
#define MP make_pair
#define For(i,n) for(int i=1; i<=n; i++)
#define INF (1<<29)

pair<int,int> ball[N];
int sum[N],ans,n,x0;
LL dp[N][N][2];
#define L 0
#define R 1
inline LL getsum(int l,int r){
	return sum[n]-sum[r]+sum[l-1];
}
inline void update(LL &x,LL xt){
	x=min(x,xt);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&x0);
	For(i,n)
		scanf("%d\n",&ball[i].x);
	For(i,n){
		int yt;
		scanf("%d",&yt);
		ans+=yt;
	}
	For(i,n)
		scanf("%d",&ball[i].v);
	ball[++n]=MP(x0,0);
	sort(ball+1,ball+n+1);
	For(i,n)
		sum[i]=sum[i-1]+ball[i].v;
	For(i,n)if(ball[i].x==x0){
		x0=i;
		break;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[x0][x0][0]=dp[x0][x0][1]=0;
	For(i,n-1){
		for(int l=1; l+i-1<=n; l++){
			int r=l+i-1;
			if(l>1){
				update(dp[l-1][r][L],dp[l][r][L]+getsum(l,r)*(ball[l].x-ball[l-1].x));
				update(dp[l-1][r][L],dp[l][r][R]+getsum(l,r)*(ball[r].x-ball[l-1].x));
			}
			if(r<n){
				update(dp[l][r+1][R],dp[l][r][L]+getsum(l,r)*(ball[r+1].x-ball[l].x));
				update(dp[l][r+1][R],dp[l][r][R]+getsum(l,r)*(ball[r+1].x-ball[r].x));
			}
		}
	}
	printf("%.3f\n",(ans-min(dp[1][n][L],dp[1][n][R]))/1000.0);
	return 0;
}

