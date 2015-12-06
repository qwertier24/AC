#include <stdio.h>
#include <algorithm>
using namespace std;
bool check(char t[10]){
	for(int i=1; i<=8; i++)
		if(t[i]==t[i-1])
			return false;
	return true;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	char g[10][10];
	for(int i=1; i<=8; i++)
		scanf("%s",g[i]+1);
	for(int i=1; i<=8; i++)
		if(!check(g[i])){
			printf("NO");
			return 0;
		}
	printf("YES");
	return 0;
}
