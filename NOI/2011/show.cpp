#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 210
int cnt[N<<1][N<<1],b[N<<1],m;

int n,d1[N<<1][N],d2[N<<1][N],st[N],ed[N],d3[N<<1][N<<1];
#define update(x,y) (x)=max((x),(y))
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n){
    scanf("%d%d",&st[i],&ed[i]);
    ed[i]+=st[i];
    b[++m]=st[i];
    b[++m]=ed[i];
  }
  sort(b+1,b+m+1);
  m=unique(b+1,b+m+1)-b-1;
  REP(i,1,n){
    st[i]=lower_bound(b+1,b+m+1,st[i])-b;
    ed[i]=lower_bound(b+1,b+m+1,ed[i])-b;
    REP(l,1,st[i])REP(r,ed[i],m)cnt[l][r]++;
  }
  memset(d1,0xcf,sizeof(d1));
  memset(d2,0xcf,sizeof(d2));
  d1[1][0]=d2[m][0]=0;
  REP(i,1,m)RREP(j,n,0){
    d1[i][j]=max(d1[i][j],d1[i][j+1]);
    REP(k,1,i-1)
      update(d1[i][j],max(d1[k][max(0,j-cnt[k][i])],d1[k][j]+cnt[k][i]));
  }
  RREP(i,m,1)RREP(j,n,0){
    d2[i][j]=max(d2[i][j+1],d2[i][j]);
    REP(k,i+1,m)
      update(d2[i][j],max(d2[k][max(0,j-cnt[i][k])],d2[k][j]+cnt[i][k]));
  }
  int ans=0;
  REP(i,1,n)ans=max(ans,min(i,d1[m][i]));
  printf("%d\n",ans);
  memset(d3,0xcf,sizeof(d3));
  REP(i,1,m)REP(j,i+1,m){
    int y=0;
    RREP(x,n,0){
      while(y<n && min(d1[i][x]+d2[j][y],x+y+cnt[i][j])<min(d1[i][x]+d2[j][y+1],x+y+1+cnt[i][j]))
        y++;
      update(d3[i][j],min(d1[i][x]+d2[j][y],x+y+cnt[i][j]));
    }
  }
  REP(i,1,n){
    int ans=0;
    REP(l,1,st[i])REP(r,ed[i],m)
      update(ans,d3[l][r]);
    printf("%d\n",ans);
  }
  return 0;
}
