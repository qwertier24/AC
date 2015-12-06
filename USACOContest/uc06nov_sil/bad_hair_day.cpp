#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
int st[80010]={0},top=-1,h[80010]={0},n;
void rev(){
	for(int i=1; i<=n/2; i++)
		swap(h[i],h[n-i+1]);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	long long ans=0;
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&h[i]);
	}
	rev();
	For(i,1,n){
		while(top>=0&&h[st[top]]<h[i])
			top--;
		if(top<0){
		//	printf("front>rear %d\n",i);
			ans+=i-1;
		}else{
			//printf("%d %d\n",i,q[rear]);
			ans+=i-st[top]-1;
		}
		st[++top]=i;
	}
	printf("%lld",ans);
	return 0;
}

