#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <iostream>
#define PROB "bookshelf"
using namespace std;
int n,L,h[100010]={0},w[100010]={0},q[100010]={0},front=0,rear=0;
long long d[100010]={0};
multiset<long long> st;
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d",&n,&L);
	int sum=0;
	for(int i=1; i<=n; i++){
		scanf("%d%d",&h[i],&w[i]);
		while(front<rear&&h[q[rear]]<=h[i]){
			st.erase(st.find(d[q[rear-1]]+h[q[rear]]));
			rear--;
		}
		st.insert(d[q[rear]]+h[i]);
		q[rear+1]=i;
		sum+=w[i];
		while(sum>L){
			st.erase(st.find(d[q[front]]+h[q[front+1]]));
			if(q[front]+1==q[front+1])
				front++;
			else{
				q[front]++;
				st.insert(d[q[front]]+h[q[front+1]]);
			}
			sum-=w[q[front]];
		}
		d[i]=*st.begin();
		q[++rear]=i;
	}
	cout<<d[n];
	return 0;
}

