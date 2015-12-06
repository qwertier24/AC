#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB
using namespace std;
#define N 4210

#define UP 0
#define DOWN 1
int d[N],n,MOD,C[2][N];
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&MOD);
	d[0]=d[1]=d[2]=1;
	int cur=0,last=1;
	C[cur][0]=C[cur][1]=1;
	for(int i=3; i<=n; i++){
		cur^=1,last^=1;
		C[cur][0]=1;
		for(int j=1; j<=i-1; j++){
			C[cur][j]=C[last][j-1]+C[last][j];
			if(C[cur][j]>=MOD)C[cur][j]-=MOD;
		}
		for(int j=1; j<i; j+=2){
			d[i]+=d[j]*(long long)d[i-1-j]%MOD*C[cur][j]%MOD;
			if(d[i]>=MOD)d[i]-=MOD;
		}
	}
	printf("%d\n",(d[n]+d[n])%MOD);
	return 0;
}

