#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#define MOD 10007
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
int fast_pow(int a,int p){
	int t=a,ret=1;
	while(p){
		if(p&1)
			ret=(ret*t)%MOD;
		t=(t*t)%MOD;
		p>>=1;
	}
	return ret;
}
int C[1010][1010];
void Init(){
	C[0][0]=1;
	for(int i=1; i<=1000; i++){
		C[0][i]=1;
		for(int j=1; j<=i; j++)
			C[j][i]=(C[j-1][i-1]+C[j][i-1])%MOD;
	}
}
int main(){
	freopen("factor.in","r",stdin);
	freopen("factor.out","w",stdout);
	int a,b,k,n,m;
	Init();
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	a%=MOD;
	b%=MOD;
	int ans=C[n][k];
	ans=(ans*fast_pow(a,n))%MOD;
	ans=(ans*fast_pow(b,m))%MOD;
	printf("%d",ans);
	return 0;
}

