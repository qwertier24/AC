#include<stdio.h>
#include<algorithm>
#include<iostream>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1000010

using namespace std;
typedef long long LL;

int cost[N],b[N],n;
LL sumx[N],sum[N],d[N];
double getk(LL x1,LL y1,LL x2,LL y2){
  return (y1-y2)/double(x1-x2);
}
int q[N],front,rear;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  For(i,n)scanf("%d",&cost[i]);
  For(i,n)scanf("%d",&b[i]);
  For(i,n){
    sum[i]=sum[i-1]+b[i];
    sumx[i]=sumx[i-1]+b[i]*(LL)i;
    while(front<rear&&getk(sum[q[front+1]],d[q[front+1]]+sumx[q[front+1]],
	       sum[q[front]],d[q[front]]+sumx[q[front]])<=i)
      front++;
    d[i]=cost[i]+d[q[front]]+(sum[i]-sum[q[front]])*i-(sumx[i]-sumx[q[front]]);
    while(front<rear&&getk(sum[i],d[i]+sumx[i],sum[q[rear]],d[q[rear]]+sumx[q[rear]])<=
	  getk(sum[q[rear]],d[q[rear]]+sumx[q[rear]],sum[q[rear-1]],d[q[rear-1]]+sumx[q[rear-1]]))
      rear--;
    q[++rear]=i;
  }
  cout<<d[n];
  return 0;
}
