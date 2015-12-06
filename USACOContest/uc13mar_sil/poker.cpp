#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	long long ans=0;
	scanf("%d",&n);
	stack<int> st;
	st.push(0);
	for(int i=1; i<=n; i++){
		int h;
		scanf("%d",&h);
		int t=st.top();
		if(st.top()>h)
			ans+=t-h;
		while(st.top()>h){
			st.pop();
		}
		//printf("%d %d %lld\n",i,st.top(),ans);
		st.push(h);
	}
	ans+=st.top();
	printf("%lld",ans);
	return 0;
}
