#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 110

int m,sg[100010],mark[100010],vis[100010];
void calc(int n){
  if(n<m)return;
  if(vis[n])return;
  vis[n]=1;
  REP(i,2,n){
    if(n/i+1<m)break;
    if(1&(i-n%i))
      calc(n/i);
    if(1&(n%i))
      calc(n/i+1);
  }
  memset(mark,0,sizeof(mark));
  REP(i,2,n){
    if(n/i+1<m){mark[0]=1;break;}
    int cur=0;
    if(1&(i-n%i))
      cur^=sg[n/i];
    if(1&(n%i))
      cur^=sg[n/i+1];
    mark[cur]=1;
  }
  int t=0;
  while(mark[t])t++;
  sg[n]=t;
}
int n,a[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d%d",&T,&m);
  while(T--){
    scanf("%d",&n);
    int ans=0;
    REP(i,1,n){
      scanf("%d",&a[i]);
      calc(a[i]);
      ans^=sg[a[i]];
    }
    printf("%d%s",ans>0,T?" ":"");
  }
  return 0;
}
