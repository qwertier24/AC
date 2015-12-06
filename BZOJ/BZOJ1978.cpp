#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#include<vector>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 50010
#define M 1000010

typedef long long LL;
using namespace std;

int n,d[N],maxd[M],a[N],L,mark[M],ans,b[M];
vector<int> f[M];
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&L);
  int maxa=0;
  For(i,n){
    scanf("%d",&a[i]);
    maxa=max(maxa,a[i]);
    b[a[i]]=1;
  }
  for(int i=L; i<=maxa; i++)
    for(int j=i; j<=maxa; j+=i){
      if(b[j]){
        f[j].push_back(i);
        mark[j]=1;
      }
    }
  For(i,n){
    Rep(j,f[a[i]].size())
      d[i]=max(d[i],maxd[f[a[i]][j]]+1);
    Rep(j,f[a[i]].size())
      maxd[f[a[i]][j]]=max(maxd[f[a[i]][j]],d[i]);
    ans=max(ans,d[i]);
  }
  printf("%d\n",ans);
  return 0;
}
