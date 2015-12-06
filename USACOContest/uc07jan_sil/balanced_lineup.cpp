#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,val_max[200010][20],val_min[200010][20];
int get_max(int l,int r){
	int p=(int)log2(r-l+1);
	return max(val_max[l][p],val_max[r-(1<<(p))+1][p]);
}
int get_min(int l,int r){
	int p=(int)log2(r-l+1);
	//printf("%d %d %d %d\n",l,r,p,r-(1<<(p))+1);
	return min(val_min[l][p],val_min[r-(1<<(p))+1][p]);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&val_max[i][0]);
		val_min[i][0]=val_max[i][0];
	}
	for(int i=1; (1<<i)<=n; i++)
		for(int j=1; j+(1<<i)-1<=n; j++){
			val_max[j][i]=max(val_max[j][i-1],val_max[j+(1<<(i-1))][i-1]);
			//printf("%d %d %d\n",j,i,val_max[j][i]);
		}
	for(int i=1; (1<<i)<=n; i++)
		for(int j=1; j+(1<<i)-1<=n; j++){
			val_min[j][i]=min(val_min[j][i-1],val_min[j+(1<<(i-1))][i-1]);
			//printf("%d %d %d\n",j,i,val_max[j][i]);
		}
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",get_max(l,r)-get_min(l,r));
	}
	return 0;
}
