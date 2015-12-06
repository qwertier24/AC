#include<stdio.h>
#include<algorithm>
#include<iostream>
#define N 50000
#define For(i,n) for(int i=1; i<=n; i++)

using namespace std;

int q[N+10]={0},front=0,rear=-1,n;
long long sum[N+10]={0},y[N+10]={0},x[N+10]={0},d[N+10]={0},L;
inline bool check(int j,int k,int i){
	//printf("  %I64d\n",x[j]-x[k]);
	return (y[j]-y[k])/((double)x[j]-x[k])<=2*(sum[i]+i-L);
}
inline bool cmp(int j,int k,int l){
	//printf("  %I64d\n",x[j]-x[k]);
	return (y[j]-y[k])/((double)x[j]-x[k])<=(y[k]-y[l])/((double)x[k]-x[l]);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif
	scanf("%d%lld",&n,&L);
	For(i,n){
		cin>>sum[i];
		sum[i]+=sum[i-1];
	}
	For(i,n){
		y[i]=d[i-1]+(i+sum[i-1])*(i+sum[i-1]);
		x[i]=sum[i-1]+i;
		while(front<rear&&cmp(i,q[rear],q[rear-1]))
			rear--;
		q[++rear]=i;
		while(front<rear&&check(q[front],q[front+1],i))
			front++;
		d[i]=d[q[front]-1]
			+(sum[i]-sum[q[front]-1]+i-q[front]-L)
			*(sum[i]-sum[q[front]-1]+i-q[front]-L);
		//printf("%d %lld %lld %lld\n",i,d[i],x[i],y[i]);
	}
	printf("%lld",d[n]);
	return 0;
}
