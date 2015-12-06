#include<stdio.h>
#include<algorithm>
#include<iostream>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 9

using namespace std;
typedef long long LL;

int n,m;
int status[1<<N],cnt,lline[1<<N],ones[1<<N];
bool check(int S){
  Rep(i,n)
    if((S&(1<<i)) && (S&(1<<(i+1))))
      return false;
  return true;
}
int getlline(int S){
  int ret=(1<<n)-1;
  Rep(i,n){
    if(S&(1<<i)){
      if(ret&(1<<(i+1)))
	ret^=(1<<(i+1));
      if(i&&(ret&(1<<(i-1))))
	ret^=(1<<(i-1));
      if(ret&(1<<i))
	ret^=(1<<i);
    }
  }
  return ret;
}
int getones(int S){
  int ret=0;
  while(S){
    ret+=1&S;
    S>>=1;
  }
  return ret;
}
LL d[N+1][N*N+1][1<<N];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  Rep(i,(1<<n))
    if(check(i)){
      status[cnt++]=i;
      lline[i]=getlline(i);
      ones[i]=getones(i);
    }
  Rep(i,(1<<n))d[0][0][i]=1;
  int S;
  LL ans=0;
  For(i,n)For(j,m){
    Rep(l,cnt){
      S=status[l];
      if(ones[S]>j)continue;
      d[i][j][S]=d[i-1][j-ones[S]][lline[S]];
    }
    Rep(k,n){
      Rep(l,(1<<n)){
	if(l&(1<<k))
	  d[i][j][l]+=d[i][j][l^(1<<k)];
      }
    }
    if(j==m)ans+=d[i][j][(1<<n)-1];
  }
  printf("%lld",ans);
  return 0;
}
