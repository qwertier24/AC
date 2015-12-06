#include<stdio.h>
#define min(x,y) (x<y?x:y)
typedef long long LL;

int n,m;
LL ans;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&m,&n);
	if(m>n){
		ans+=(m-n)*(LL)n;
		m=n;
	}
	for(int i=1,lst; i<=m; i=lst+1){
		lst=min(m,n/(n/i));
		ans+=(lst-i+1)*(LL)n-(n/i)*LL(lst-i+1)*LL(lst+i)/2;
	}
	printf("%lld\n",ans);
	return 0;
}
