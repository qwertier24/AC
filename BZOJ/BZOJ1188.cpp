#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 65

int n,mark[N],a[N],ans,sg[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    ans=0;
    scanf("%d",&n);
    REP(i,1,n){
      scanf("%d",&a[i]);
    }
    RREP(i,n,1){
      memset(mark,0,sizeof(mark));
      REP(j,i+1,n)REP(k,j,n)
        mark[sg[j]^sg[k]]=1;
      REP(j,0,N-1)if(!mark[j]){sg[i]=j;break;}
      if(a[i]&1)ans^=sg[i];
    }
    int flag=0,cnt=0;
    REP(i,1,n)REP(j,i+1,n)REP(k,j,n){
      if(!(ans^sg[j]^sg[k]^sg[i])){
        if(!flag)printf("%d %d %d\n",i-1,j-1,k-1);
        flag=1;
        cnt++;
      }
    }
    if(!flag)puts("-1 -1 -1");
    printf("%d\n",cnt);
  }
  return 0;
}
