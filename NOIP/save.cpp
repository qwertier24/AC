#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "save"
using namespace std;
int cost;
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	int sum=0,sum2=0;
	for(int i=1; i<=12; i++){
		scanf("%d",&cost);
		sum+=300;
		if(sum<cost){
			printf("-%d",i);
			return 0;
		}
		sum-=cost;
		sum2+=sum/100*100;
		sum%=100;
	}
	printf("%d",(sum2+sum+sum2/5));
	return 0;
}

