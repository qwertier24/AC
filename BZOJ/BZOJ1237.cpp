#include<stdio.h>
#include<algorithm>
#include<string.h>
#define N 100010

typedef long long LL;
using namespace std;

LL d[N];
int a[N],b[N],n;
void update(LL &x,LL dx){
	x=min(x,dx);
}
LL sub(LL c){
	if(!c)return (1ll<<41);
	return abs(c);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d%d",&a[i],&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	memset(d,0x1f,sizeof(d));
	d[0]=0;
	d[1]=sub(a[1]-b[1]);
	d[2]=min(d[1]+sub(a[2]-b[2]),(LL)sub(a[2]-b[1])+sub(a[1]-b[2]));
	for(int i=3; i<=n; i++){
		update(d[i],d[i-1]+sub(a[i]-b[i]));
		update(d[i],d[i-2]+sub(a[i]-b[i-1])+sub(a[i-1]-b[i]));
		update(d[i],d[i-3]+sub(a[i]-b[i-2])+sub(a[i-1]-b[i-1])+sub(a[i-2]-b[i]));
		update(d[i],d[i-3]+sub(a[i]-b[i-1])+sub(a[i-1]-b[i-2])+sub(a[i-2]-b[i]));
		update(d[i],d[i-3]+sub(a[i]-b[i-2])+sub(a[i-1]-b[i])+sub(a[i-2]-b[i-1]));
	}
	if(d[n]>(1ll<<40))printf("-1");
	else printf("%lld\n",d[n]);
	return 0;
}
