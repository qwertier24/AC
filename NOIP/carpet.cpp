#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
struct Carpet{
	int x1,y1,x2,y2;
}car[10010];
bool cover(int a,int l,int r){
	return a>=l&&a<=r;
}
int main(){
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout);
	int n;
	scanf("%d",&n);
	int ans=-1;
	for(int i=1; i<=n; ++i){
		int t1,t2;
		scanf("%d%d%d%d",&car[i].x1,&car[i].y1,&t1,&t2);
		car[i].x2=car[i].x1+t1;
		car[i].y2=car[i].y1+t2;
	}
	int x,y; 
	scanf("%d%d",&x,&y);
	for(int i=1; i<=n; ++i){
		if(cover(x,car[i].x1,car[i].x2)&&cover(y,car[i].y1,car[i].y2))
			ans=i;
	}
	printf("%d\n",ans);
	return 0;
}

