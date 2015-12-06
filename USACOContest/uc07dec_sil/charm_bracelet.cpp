#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m,d[13000]={0};
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	int ans=0;
	for(int i=1; i<=n; i++){
		int w,v;
		scanf("%d%d",&w,&v);
		for(int j=m; j>=w; j--){
			d[j]=max(d[j],d[j-w]+v);
			//printf("%d %d %d\n",i,j,d[j]);
		}
	}
	printf("%d\n",d[m]);
	return 0;
}
