#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
using namespace std;
#define N 310

int f[N][N],n,m,MOD,cnt[N];
LL C[N][N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&n,&m,&MOD);
    REP(i,0,n){
      C[i][0]=1;
      REP(j,1,i){
        C[i][j]=C[i-1][j-1]+C[i-1][j];
        if(C[i][j]>=MOD)C[i][j]-=MOD;
      }
    }
    memset(f,-1,sizeof(f));
    memset(cnt,0,sizeof(cnt));
    REP(i,1,m){
      int t,skip;
      scanf("%d%d",&skip,&t);
      cnt[t]++;
    }
    int s=0;
    f[0][0]=1;
    REP(i,1,n){
      s+=cnt[i];
      REP(j,max(i,s),n){
        REP(k,cnt[i],j){
          if(f[i-1][j-k]>-1){
            if(f[i][j]==-1)f[i][j]=0;
            f[i][j]+=f[i-1][j-k]*C[j-s][k-cnt[i]]%MOD;
            if(f[i][j]>=MOD)f[i][j]-=MOD;
          }
        }
      }
    }
    if(f[n][n]==-1)puts("NO");
    else printf("YES %d\n",f[n][n]);
  }
  return 0;
}
