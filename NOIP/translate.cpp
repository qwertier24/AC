#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
int q[1010]={0},front=0,rear=0,n,m,inq[1010]={0},a[1010];
int main(){
	freopen("translate.in","r",stdin);
	freopen("translate.out","w",stdout);
	scanf("%d%d",&n,&m);
	int ans=0;
	scanf("%d",&a[1]);
	q[rear]=a[1];
	inq[a[1]]=1;
	ans++;
	For(i,2,m){
		scanf("%d",&a[i]);
		if(!inq[a[i]]){
			ans++;
			rear=(rear+1)%n;
			if(rear==front){
				inq[q[front]]=0;
				front=(front+1)%n;
			}
			q[rear]=a[i];
			inq[a[i]]=1;
		}
	}
	printf("%d",ans);
	return 0;
}

