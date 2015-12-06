#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)

using namespace std;
#define N 100010
#define MP make_pair
#define INF 1000000001

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
int a[N],n,m,lft[N],rgt[N],del[N];
long long ans;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  REP(i,n){
    scanf("%d",&a[i]);
    if(i)pq.push(MP(a[i]-a[i-1],i));
    lft[i]=i-1;
    rgt[i]=i+1;
  }
  n--;
  for(int i=n; i; i--)
    a[i]-=a[i-1];
  a[0]=a[n+1]=INF;
  while(m--){
    while(del[pq.top().second])pq.pop();
    int i=pq.top().second;
    pq.pop();
    ans+=a[i];
    a[i]=a[lft[i]]+a[rgt[i]]-a[i];
    del[lft[i]]=1;
    del[rgt[i]]=1;
    lft[i]=lft[lft[i]];
    rgt[i]=rgt[rgt[i]];
    pq.push(MP(a[i],i));
  }
  printf("%lld",ans);
  return 0;
}
