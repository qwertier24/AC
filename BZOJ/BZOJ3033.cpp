#include<stdio.h>
#include<cstring>
#include<vector>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 11

int n;
#define FULL ((1<<n)-1)
int vis[1<<N];
vector<int> ans;
void dfs(int u){
  if(vis[u])return;
  vis[u]=1;
  dfs((u<<1)&FULL);
  dfs((u<<1|1)&FULL);
  ans.push_back(u&1);
}
int main(){
  scanf("%d",&n);
  printf("%d ",1<<n);
  dfs(0);
  REP(i,1,n-1)putchar('0');
  RREP(i,ans.size()-1,n-1)
    putchar('0'+ans[i]);
  return 0;
}
