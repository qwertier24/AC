#include<stdio.h>
#include<algorithm>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100

using namespace std;
typedef long long LL;

struct Node{
  int lc,rc;
  Node(){lc=-1,rc=-1;}
}node[N];

int n,fa[N],ans[N],cur;
void dfs(int &o){
  if(o==-1)return;
  if(node[o].rc==-1){
    if(node[o].lc!=-1 && node[node[o].lc].lc==-1){
      ans[cur]=node[o].lc;
      node[o].lc=-1;
    }else{
      ans[cur]=o;
      o=node[o].lc;
    }
  }else{
    dfs(node[o].lc);
    swap(node[o].lc,node[o].rc);
  }
}
int root=0;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  For(i,n){
    scanf("%d",&fa[i]);
    if(fa[i]<100)
      node[fa[i]].lc=i;
    else 
      node[fa[i]-100].rc=i;
  }
  for(int i=n; i>=0; i--){
    cur=i;
    dfs(root);
  }
  Rep(i,n)printf("%d ",ans[i]);
  printf("%d",ans[n]);
  return 0;
}
