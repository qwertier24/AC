#include<stdio.h>
#include<algorithm>
#include<iostream>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1000010

using namespace std;
typedef long long LL;

int x[N],p[N],c[N],n;
int q[N],front=0,rear=0;

double getk(LL x1,LL y1,LL x2,LL y2){
  return (y1-y2)/(double)(x1-x2);
}
LL sum[N],sumx[N],d[N];
int main(){
#ifndef ONLINE_JUDGE
  freopen("storage.in","r",stdin);
  freopen("storage.out","w",stdout);
#endif 
  scanf("%d",&n);
  For(i,n){
    scanf("%d%d%d",&x[i],&p[i],&c[i]);
    sumx[i]=sumx[i-1]+x[i]*(LL)p[i];
    sum[i]=sum[i-1]+p[i];
    while(front<rear&&getk(sum[q[front+1]],d[q[front+1]]+sumx[q[front+1]],
			   sum[q[front]],d[q[front]]+sumx[q[front]])<=x[i])
      front++;
    d[i]=d[q[front]]+x[i]*(sum[i]-sum[q[front]])-(sumx[i]-sumx[q[front]])+c[i];
    while(front<rear
	  &&getk(sum[i],d[i]+sumx[i],sum[q[rear]],d[q[rear]]+sumx[q[rear]])
	  <=getk(sum[q[rear]],d[q[rear]]+sumx[q[rear]],sum[q[rear-1]],d[q[rear-1]]+sumx[q[rear-1]]))
      rear--;
    q[++rear]=i;
  }
  cout<<d[n];
  return 0;
}
