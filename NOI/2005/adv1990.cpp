#include<stdio.h>
#include<string.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define max(x,y) (x)>(y)?(x):(y)

typedef long long LL;
#define N 210

char g[N][N];
int dp[N][N][N],n,m,x0,y0,k,s[N],t[N],d[N];
int fr,rr,q[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d%d%d%d",&n,&m,&x0,&y0,&k);
	REP(i,1,n)scanf("%s",g[i]+1);
	REP(i,1,k){
		scanf("%d%d%d",&s[i],&t[i],&d[i]);
		t[i]-=s[i]-1;
	}
	memset(dp,0xcf,sizeof(dp));
	dp[0][x0][y0]=0;
	REP(i,1,k){
		if(d[i]==1){//up
			REP(y,1,m){
				fr=0,rr=-1;
				RREP(x,n,1){
					if(g[x][y]=='x'){
						fr=0,rr=-1;
						continue;
					}
					while(fr<=rr && q[fr]-x>t[i])
						fr++;
					while(fr<=rr && dp[i-1][x][y]+x>=dp[i-1][q[rr]][y]+q[rr])
						rr--;
					q[++rr]=x;
					dp[i][x][y]=dp[i-1][q[fr]][y]+q[fr]-x;
				}
			}
		}else if(d[i]==2){
			REP(y,1,m){
				fr=0,rr=-1;
				REP(x,1,n){
					if(g[x][y]=='x'){
						fr=0,rr=-1;
						continue;
					}
					while(fr<=rr && x-q[fr]>t[i])
						fr++;
					while(fr<=rr && dp[i-1][x][y]-x>=dp[i-1][q[rr]][y]-q[rr])
						rr--;
					q[++rr]=x;
					dp[i][x][y]=dp[i-1][q[fr]][y]+x-q[fr];
				}
			}
		}else if(d[i]==3){
			REP(x,1,n){
				fr=0,rr=-1;
				RREP(y,m,1){
					if(g[x][y]=='x'){
						fr=0,rr=-1;
						continue;
					}
					while(fr<=rr && q[fr]-y>t[i])
						fr++;
					while(fr<=rr && dp[i-1][x][y]+y>=dp[i-1][x][q[rr]]+q[rr])
						rr--;
					q[++rr]=y;
					dp[i][x][y]=dp[i-1][x][q[fr]]+q[fr]-y;
				}
			}
		}else{
			REP(x,1,n){
				fr=0,rr=-1;
				REP(y,1,m){
					if(g[x][y]=='x'){
						fr=0,rr=-1;
						continue;
					}
					while(fr<=rr && y-q[fr]>t[i])
						fr++;
					while(fr<=rr && dp[i-1][x][y]-y>=dp[i-1][x][q[rr]]-q[rr])
						rr--;
					q[++rr]=y;
					dp[i][x][y]=dp[i-1][x][q[fr]]+y-q[fr];
				}
			}
		}
	}
	int ans=0;
	REP(i,1,n)REP(j,1,m)ans=max(ans,dp[k][i][j]);
	printf("%d",ans);
	return 0;
}

