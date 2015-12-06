#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "cowids"
using namespace std;
int n,k,C[5010][20]={0};
void Init(){
	for(int i=0; i<=5000; i++){
		C[i][0]=1;
		for(int j=1; j<=10; j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			if(C[i][j]>1e7)C[i][j]=1e7;
		}
	}
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==1){
		printf("1");
		for(int i=1; i<n; i++)
			printf("0");
		return 0;
	}
	Init();
	int sum=0,len=0;
	while(sum<n){
		len++;
		sum+=C[len-1][k-1];
	}
	for(int i=len; i; i--){
		sum=0;
		for(int j=i-1; j; j--)
			sum+=C[j-1][k-1];
		if(sum>=n)
			printf("0");
		else{
			printf("1");
			//printf("  %d\n",n);
			n-=sum;
			k--;
		}
	}
	return 0;
}

