#include<stdio.h>
#define MOD 2007

int T,n,ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=4;
		for(int i=2; i<=n; i++)ans=ans*5%MOD;
		ans=ans*n%MOD;
		printf("%d\n",ans);
	}
	return 0;
}
