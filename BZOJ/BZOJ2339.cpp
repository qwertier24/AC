#include <algorithm>
#include <stdio.h>
#include <string.h>
#define N 1000010
#define For(i,n) for(int i=1; i<=n; i++)
#define MOD 100000007
using namespace std;

int n,m;
long long d[N],f[N],p2,inv_fact,inv[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	inv_fact=inv[1]=1;
	for(int i=2; i<=m; i++){
		inv[i]=-MOD/i*inv[MOD%i]%MOD;
		inv_fact=inv_fact*inv[i]%MOD;
	}
	p2=1;
	For(i,n)p2=p2*2%MOD;
	f[0]=1;
	For(i,m)
		f[i]=f[i-1]*(p2-i)%MOD;
	d[0]=1;
	d[1]=0;
	for(int i=2; i<=m; i++)
		d[i]=(f[i-1]-d[i-1]-d[i-2]*(i-1)%MOD*(p2-i+1)%MOD)%MOD;
	printf("%lld\n",(d[m]*inv_fact%MOD+MOD)%MOD);
	return 0;
}

