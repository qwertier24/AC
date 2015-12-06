#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
typedef long long LL;
#define N 21

long double fact[N],mul[N],C[N][N];
int l[N],c[N],pos[N][20],len[1<<N],ones[1<<N];
int n,m;
inline int calc(int L,int M,int R){
  //printf("L:%d M:%d R:%d m:%d cnt:%d\n",L,M,R,m,min(L+m,L+M+R)-max(m,L+M));
  return max(0,min(L+m,L+M+R)-max(m,L+M));
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  fact[0]=1;
  FOR(i,20)fact[i]=fact[i-1]*i;
  REP(i,20){
    C[i][0]=1;
    FOR(j,i)
      C[i][j]=C[i-1][j-1]+C[i-1][j];
  }
  REP(i,20)
    REP(j,i+1)
      mul[i]+=C[i][j]*fact[j]*fact[i-j];
  int T;
  scanf("%d",&T);
  while(T--){
    long double ans=0,ans2=0;
    memset(pos,0,sizeof(pos));
    scanf("%d%d",&n,&m);
    REP(i,n){
      scanf("%d%d",&l[i],&c[i]);
      pos[c[i]][++pos[c[i]][0]]=i;
    }
    REP(i,(1<<n)){
      len[i]=ones[i]=0;
      REP(j,n)
        if((i>>j)&1){
          len[i]+=l[j];
          ones[i]++;
        }
    }
    REP(i,n)
      if(l[i]>m)
        ans2+=l[i]-m;
    FOR(i,n){
      if(pos[i][0]==2){
        int &u=pos[i][1],&v=pos[i][2];
        int S0=((1<<n)-1)^(1<<u)^(1<<v);
        for(int S=S0; ; S=(S-1)&S0){
          ans+=fact[ones[S]]*mul[n-2-ones[S]]*calc(l[u],len[S],l[v])*2;
          if(!S)break;
        }
      }
    }
    printf("%.7f\n",double(ans/fact[n]+ans2));
  }
  return 0;
}
