#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair
#define seed 233u

#define N 5010
LL psd[N];
void init(){
  psd[0]=1;
for(int i=1; i<=5000; i++)
  psd[i]=psd[i-1]*seed;
}
int n,a[N];
LL h[N];

/*
1: s[i..j]>s[j..n]
0: s[i..j]==s[j..n]
-1:s[i..j]<s[j..n]
*/
int comp(int i,int j){
  if(n-j+1 < j-i)
    return 1;
  if(a[i]!=a[j]){
    if(a[i]<a[j])
      return -1;
    else
      return 1;
  }
  int lo=1,hi=j-i;
  while(lo<hi){
    int mi=(lo+hi+1)>>1;
    if(h[i+mi-1]-h[i-1]*psd[mi] == h[j+mi-1]-h[j-1]*psd[mi])
      lo=mi;
    else
      hi=mi-1;
  }
  if(lo==j-i)
    return 0;
  else if(a[i+lo]<a[j+lo])
    return -1;
  else
    return 1;
}
char s[N];
int cmp[N][N],dp[N][N],sumd[N][N];
#define MOD 1000000007
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
init();
  scanf("%d",&n);
  scanf("%s",s+1);
  FOR(i,n){
    a[i]=s[i]-'0';
    h[i]=h[i-1]*seed+a[i];
  }
  FOR(i,n)
    for(int j=i+1; j<=n; j++){
      cmp[i][j]=comp(i,j);
    }
  for(int r=1; r<=n; r++){
    for(int l=r; l>=1; l--){
      if(a[l]!=0){
        if(l==1){
          dp[l][r]=1;
        }else{
          dp[l][r]=sumd[l-1][r-l];
          if(l-1-(r-l+1)+1>0 && cmp[l-1-(r-l+1)+1][l]==-1)
            dp[l][r]=(dp[l][r]+dp[l-1-(r-l+1)+1][l-1])%MOD;
        }
      }
      sumd[r][r-l+1]=(sumd[r][r-l+1-1]+dp[l][r])%MOD;
    }
    for(int i=r+1; i<=n; i++)
      sumd[r][i]=sumd[r][i-1];
  }
  printf("%d\n",sumd[n][n]);
  return 0;
}
