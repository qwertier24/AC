#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 10000
#define K first
#define B second

using namespace std;

typedef long long LL;

pair<int,int> c[N+10];
bool check(int i,int j,int k){
  return (c[i].B-c[k].B)*((LL)c[j].K-c[i].K)<(c[i].B-c[j].B)*((LL)c[k].K-c[i].K);
}
bool cmp(const int& a,const int& b){
  return c[a]<c[b];
}
int n,q[N+10],front=0,rear=-1,idx[N+10];
int ans[N+10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  For(i,n)idx[i]=i;
  For(i,n)scanf("%d",&c[i].B);
  For(i,n)scanf("%d",&c[i].K);
  sort(idx+1,idx+n+1,cmp);
  q[++rear]=idx[1];
  q[++rear]=idx[2];
  for(int i=3; i<=n; i++){
    while(front<rear&&check(q[rear-1],q[rear],idx[i]))
      rear--;
    q[++rear]=idx[i];
  }
  for(int i=front; i<rear; i++){
    if(c[q[i]].B<c[q[i+1]].B)continue;
    ans[++ans[0]]=q[i];
  }
  ans[++ans[0]]=q[rear];
  sort(ans+1,ans+ans[0]+1);
  printf("%d\n",ans[0]);
  For(i,ans[0]-1)printf("%d ",ans[i]);
  printf("%d\n",ans[ans[0]]);
  return 0;
}
