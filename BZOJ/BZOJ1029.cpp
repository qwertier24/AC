#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 150000

using namespace std;

pair<int,int> seg[N+10];
int n;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  For(i,n){
    scanf("%d%d",&seg[i].second,&seg[i].first);
  }
  priority_queue<int> pq;
  sort(seg+1,seg+n+1);
  int curt=0,ans=0;
  For(i,n){
    if(curt+seg[i].second<=seg[i].first){
      curt+=seg[i].second;
      pq.push(seg[i].second);
      ans++;
    }else{
      if(pq.empty()||pq.top()<=seg[i].second)continue;
      curt-=pq.top()-seg[i].second;
      pq.pop();
      pq.push(seg[i].second);
    }
  }
  printf("%d",ans);
  return 0;
}
