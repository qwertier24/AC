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

#define N 50

int n;

int a[N],b[N];
vector<int> c[N];
void dfs(int dep, int l1, int r1, int l2, int r2){
    //printf("%d %d %d %d\n",l1,r1,l2,r2);
    if(l1 > r1)
        return;
    int cur = b[l2];
    ///printf("%d %d\n",l2,cur);
    c[dep].push_back(cur);
    for(int i = l1; i <= r1; i++)
        if(a[i] == cur){
            dfs(dep+1, l1, i-1, l2+1, l2+i-l1);
            dfs(dep+1, i+1, r1, l2+i-l1+1, r2);
        }
}
vector<int> ans;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  FOR(i,n){
      scanf("%d",&a[i]);
  }
  FOR(i,n)
      scanf("%d",&b[i]);
  dfs(0, 1,n, 1,n);
  REP(i,N){
      if(c[i].size() == 0)
          continue;
      for(int j = c[i].size()-1; j>=0; j--)
          ans.push_back(c[i][j]);
  }
  printf("%d",ans[0]);
  FOR(i,ans.size()-1)
      printf(" %d", ans[i]);
  return 0;
}
