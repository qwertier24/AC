#include <stdio.h>
#include <algorithm>
using namespace std;
int n,final_sum,used[20]={0};
bool found=false;
int C[20][20];
void Init(){
	C[0][0]=1;
	for(int i=1; i<=10; i++){
		C[0][i]=1;
		for(int j=1; j<=i; j++)
			C[j][i]=C[j][i-1]+C[j-1][i-1];
	}
}
bool check(){
	int sum=0;
	for(int i=1; i<=n; i++){
		//printf("%d %d %d\n",i,used[i],i*C[used[i]-1][n-1]);
		sum+=i*C[used[i]-1][n-1];
	}
	//printf("  %d \n",sum);
	return sum==final_sum;
}
void search(int depth){
	if(depth==n+1){
		found=check();
		return;
	}
	for(int i=1; i<=n; ++i)
		if(!used[i]){
			used[i]=depth;
			search(depth+1);
			if(found)return;
			used[i]=0;
		}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	Init();
	//printf("%d %d %d\n",C[0][0],C[4][3],C[10][2]);
	scanf("%d%d",&n,&final_sum);
	search(1);
	for(int i=1; i<n; i++)
		for(int j=1; j<=n; j++)
			if(used[j]==i)
				printf("%d ",j);
	for(int j=1; j<=n; j++)
		if(used[j]==n)
			printf("%d",j);
	return 0;
}
