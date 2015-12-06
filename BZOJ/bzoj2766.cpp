#include<stdio.h>
#include<algorithm>
#include<string.h>
#define FOR(i,n) for(int i=1; i<=n; i++)
#define REP(i,n) for(int i=0; i<n; i++)

using namespace std;
#define N 1000
#define M 27
#define INF (1<<29)

int dp[N][M],s,t,n,m;
char g[N][M];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif
  int first=1,kase=1;
  while(scanf("%d%d",&n,&m)&&n){
    FOR(i,n)scanf("%s",g[i]);
    scanf("%d%d",&s,&t);
    t--;
    memset(dp,0x3f,sizeof(dp));
    memset(dp[t+1],0,sizeof(dp[t+1]));
    for(int i=t; i>=s; i--){
      REP(j,m){
	if(g[i][j]=='O')
	  REP(k,m)
	    dp[i][j]=min(dp[i][j],dp[i+1][k]+(j!=k));
	//printf("%d %d %d\n",i,j,dp[i][j]);
      }
    }
    int mind=1<<30;
    REP(i,m)
      mind=min(mind,dp[s][i]);
    if(first)first=0;
    else puts("\n");
    printf("Case %d:\n\n",kase++);
    if(mind>INF){
      printf("Not available");
      continue;
    }
    int lst,lsti=s;
    REP(i,m)
      if(dp[s][i]==mind){
	lst=i;
	break;
      }
    for(int i=s+1; i<=t; i++){
      REP(j,m)
	if(dp[i][j]+(j!=lst)==dp[i-1][lst]){
	  if(lst!=j){
	    printf("%c: %d-%d\n",'A'+lst,lsti,i);
	    lsti=i;
	    lst=j;
	  }
	  break;
	}
    }
    printf("%c: %d-%d",'A'+lst,lsti,t+1);
  }
  return 0;
}
