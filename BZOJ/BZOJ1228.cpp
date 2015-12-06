#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB
using namespace std;

int calc(int a,int b){
	int ret=31;
	for(int i=30; i; i--){
		if(a<=(1<<i) && b<=(1<<i))ret=i;
		if(a>(1<<i))a-=(1<<i);
		if(b>(1<<i))b-=(1<<i);
	}
	return a==1&&b==1?0:ret;
}
int main(){
	int T,n;
	freopen("in.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int ans=0;
		for(int i=1; i<=n; i+=2){
			int a,b;
			scanf("%d%d",&a,&b);
			ans^=calc(a,b);
		}
		printf("%s\n",ans?"YES":"NO");
	}
	return 0;
}

