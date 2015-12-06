#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	int a=1,b=0;
	while(n--){
		int t=a;
		a=b;
		b+=t;
	}
	printf("%d %d\n",a,b);
	return 0;
}
