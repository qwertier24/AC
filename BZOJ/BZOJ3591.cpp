#include<stdio.h>
#include<algorithm>
#include<string.h>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
#define N 15

const int p3[N+2]={1,3,9,
		   27,81,243,
		   729,2157,6561,
		   19683,59049,177147,
		   531441,1594323,7482909,
		   14348907,0};

int dp[14348907],lst[N],n,m,a[N];
void print(int S){
  REP(i,n){
    printf("%d",S%3);
    S/=3;
  }
}
int done[14348907];
void calc(int S){
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  memset(lst,-1,sizeof(lst));
  REP(i,m){
    scanf("%d",&a[i]);
    a[i]--;
    if(i)lst[a[i]]=a[i-1];
  }
  dp[0]=1;
  calc(0);
  REP(S,p3[n]){
    if(!dp[S])continue;
  }
  int ans=0;
  REP(S,p3[n]-1){
    int cnt=0;
    REP(i,n)if((S/p3[i])%3==2)cnt++;
  }
  REP(i,p3[n]){
    print(S);
    printf(" %d\n",dp[S]);
    int upper=N+1;
    for(int i=n-1; i>=0; i--){
      if((S/p3[i])%3==2)
	upper=i;
      else if(!((S/p3[i])%3))
	if(lst[i]==-1 || (S/p3[lst[i]])%3){
	  dp[(S-p3[upper])+p3[i]*2]+=dp[S];
	  printf(" %d ",upper);
	  print(S);
	  putchar(' ');
	  print(S-p3[upper]+p3[i]*2);
	  putchar('\n');
	}
    }
    printf("%d\n",ans);
  }
  return 0;
}
