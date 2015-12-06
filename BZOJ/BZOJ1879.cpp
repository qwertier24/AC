#include<stdio.h>
#include<algorithm>
#include<cstring>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 15
#define MOD 1000003

char s[N][60];
int n,maxl,d[2][1<<N],ones[1<<N],m;
void solve(){
  scanf("%d%d",&n,&m);
  maxl=0;
  REP(i,0,n-1){
    scanf("%s",s[i]);
    maxl=max(maxl,(int)strlen(s[i]));
  }
  int cur=0,nxt=1,ans=0;
  memset(d[cur],0,sizeof(d[cur]));
  d[cur][(1<<n)-1]=1;
  REP(i,0,maxl-1){
    memset(d[nxt],0,sizeof(d[nxt]));
    REP(j,0,(1<<n)-1){
      if(ones[j]<m || !d[cur][j])continue;
      for(char c='a'; c<='z'; c++){
        int S=0;
        REP(k,0,n-1)
          if((1&(j>>k)) && (s[k][i]==c||s[k][i]=='?'))
            S|=(1<<k);
        d[nxt][S]+=d[cur][j];
        if(d[nxt][S]>=MOD)d[nxt][S]-=MOD;
      }
    }
    cur^=1,nxt^=1;
    REP(j,0,(1<<n)-1){
      if(ones[j]==m){
        int flag=1;
        REP(k,0,n-1)
          if(s[k][i+1]){
            flag=0;
            break;
          }
        //printf("%d %d\n",j,flag);
        if(flag){
          //printf("%d %d %d\n",i,j,d[cur][j]);
          ans+=d[cur][j];
          if(ans>=MOD)ans-=MOD;
        }
      }
    }
  }
  printf("%d\n",ans);
}

inline int cnt_ones(int x){
  int ret=0;
  while(x){ret+=x&1;x>>=1;}
  return ret;
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  REP(i,0,(1<<15)-1)
    ones[i]=cnt_ones(i);
  int T;
  scanf("%d",&T);
  while(T--)solve();
  return 0;
}
