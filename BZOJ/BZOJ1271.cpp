#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB
#define N 200010
#define For(i,n) for(int i=1; i<=n; i++)
using namespace std;

int T,n,s[N],d[N],e[N],sum;
int getsum(int p){
	int ret=0;
	For(i,n)if(s[i]<=p){
		ret+=(min(p,e[i])-s[i])/d[i]+1;
	}
	return ret;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	//freopen(PROB".out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		sum=0;
		For(i,n){
			scanf("%d%d%d",&s[i],&e[i],&d[i]);
			sum+=(e[i]-s[i])/d[i]+1;
		}
		if(sum%2==0){
			puts("Poor QIN Teng:(");
			continue;
		}
		int lo=0,hi=(~0)^(1<<31);
		while(lo<hi){
			int mi=lo+(hi-lo)/2;
			if(getsum(mi)&1)hi=mi;
			else lo=mi+1;
		}
		printf("%d %d\n",lo,getsum(lo)-getsum(lo-1));
	}
	return 0;
}

