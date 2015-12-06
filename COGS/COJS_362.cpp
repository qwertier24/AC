#include<stdio.h>
#include<algorithm>
#include<iostream>
#define N 20000
#define For(i,n) for(int i=1; i<=n; i++)

using namespace std;

long long p[N+10],w[N+10],total=0,x[N+10],y[N+10];
int n,front=0,rear=-1,q[N+10];
bool check(int j,int k,int i){
	return w[k]*p[k]-w[j]*p[j]>=p[i]*(w[k]-w[j]);
}
bool cmp(int j,int k,int l){
	return (y[k]-y[j])*(x[l]-x[k])>=(y[l]-y[k])*(x[k]-x[j]);
}
int main(){
#ifndef ONLINE_JUDGE
	//freopen("prob.txt","r",stdin);
#endif
	//freopen("two.in","r",stdin);
	//freopen("two.out","w",stdout);
	scanf("%d",&n);
	For(i,n){
		scanf("%lld%lld",&w[i],&p[i+1]);
		p[i]+=p[i-1];
	}
	long long L=p[n+1]+p[n];
	For(i,n){
		total+=w[i]*(L-p[i]);
		w[i]+=w[i-1];
	}
	//cout<<total<<endl;
	q[++rear]=1;
	long long ans=1ll<<60;
	for(int i=2; i<=n; i++){
		y[i]=w[i]*p[i];
		x[i]=w[i];
		while(front<rear&&!check(q[front],q[front+1],i))
			front++;
		ans=min(ans,total-w[i]*(L-p[i])-w[q[front]]*(p[i]-p[q[front]]));
		while(front<rear&&cmp(q[rear-1],q[rear],i))
			rear--;
		q[++rear]=i;
	}
	printf("%lld\n",ans);
	return 0;
}
