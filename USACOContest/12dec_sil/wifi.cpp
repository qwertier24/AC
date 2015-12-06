#include <stdio.h>
#include <algorithm>
#include <iostream>
#define PROB "wifi"
using namespace std;
int n;
int d[2010],A,B,a[2010];
int main(){
#ifndef ONLINE_JUDGE
	freopen(PROB".in","r",stdin);
	//freopen(PROB".out","w",stdout);
#endif
	cin>>n>>A>>B;
	A*=2;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++){
		d[i]=1<<30;
		for(int j=0; j<i; j++)
			d[i]=min(d[i],d[j]+(a[i]-a[j+1])*B+A);
		//printf("%d %d\n",i,d[i]);
	}
	printf("%d",d[n]/2);
	if(d[n]%2)printf(".5");
	return 0;
}
