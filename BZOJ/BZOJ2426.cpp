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

int k;
int n,m,b,c[50010][60],h[60],cap[50010],id[50010],tot;
bool cmp(const int& i,const int& j){
  return c[i][k]-c[i][0]<c[j][k]-c[j][0];
}
int ansk;
LL ans=1ll<<60;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d%d",&m,&b,&h[0],&n);
  REP(i,1,m){
    scanf("%d",&cap[i]);
    tot+=cap[i];
    id[i]=i;
  }
  REP(i,1,n)scanf("%d",&h[i]);
  REP(j,0,n)REP(i,1,m)scanf("%d",&c[i][j]);
  for(k=1; k<=n; k++){
    LL cur=0;
    REP(i,1,m)cur+=c[i][0]*cap[i];
    sort(id+1,id+m+1,cmp);
    int rem=tot-b;
    REP(i,1,m){
      cur+=(c[id[i]][k]-c[id[i]][0])*min(rem,cap[id[i]]);
      rem-=min(rem,cap[id[i]]);
    }
    if(ans>cur+h[0]+h[k]){
      ans=cur+h[0]+h[k];
      ansk=k;
    }
  }
  printf("%d\n%lld\n",ansk,ans);
  return 0;
}
