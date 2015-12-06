#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>
#define PROB "planting"
using namespace std;
int n,x1[1010],x2[1010],y1[1010],y2[1010];
long long calc(int i,int l,int t,int r,int b){
	if(t<=b||l>=r||i>n)return 0;
	long long cur=(min(r,x2[i])-max(l,x1[i]));
	if(cur<=0)return calc(i+1,l,t,r,b);
	cur*=(min(t,y1[i])-max(b,y2[i]));
	if(cur<=0)return calc(i+1,l,t,r,b);
	printf("%d (%d,%d) (%d,%d) %I64d %d %d %d %d\n",i,l,t,r,b,cur,min(r,x2[i]),max(l,x1[i]),min(t,y1[i]),max(b,y2[i]));
	if(l<x1[i])cur+=calc(i+1,l,t,x1[i],b);
	if(r>x2[i])cur+=calc(i+1,x2[i],t,r,b);
	if(t>y1[i])cur+=calc(i+1,max(x1[i],l),t,min(r,x2[i]),y1[i]);
	if(b<y2[i])cur+=calc(i+1,max(x1[i],l),y2[i],min(r,x2[i]),b);
	return cur;
}
int main(){
	freopen(PROB".in","r",stdin);
	//freopen(PROB".out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	cout<<calc(1,-1e8,1e8,1e8,-1e8);
	return 0;
}

