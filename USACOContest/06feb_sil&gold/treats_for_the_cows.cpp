#include <stdio.h>
#include <algorithm>
using namespace std;
int d[2010][2010],num[2010];
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&num[i]);
		d[i][i]=n*num[i];
	}
	for(int len=2; len<=n; ++len)
		for(int l=1; l+len-1<=n; ++l){
			int r=l+len-1;
			d[l][r]=max(d[l][r-1]+(n-len+1)*num[r],d[l+1][r]+(n-len+1)*num[l]);
		}
	printf("%d",d[1][n]);
	return 0;
}
