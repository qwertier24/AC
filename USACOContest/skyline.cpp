/*
ID: mayukun3
PROG: skyline
LANG: C++
*/
#include <stdio.h>
#include <stack>
using namespace std;
int n,w;
stack<int> st;
int main()
{
	int ans=0,x,y;
	freopen("skyline.in","r",stdin);freopen("skyline.out","w",stdout);
	scanf("%d%d",&n,&w);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d%d",&x,&y);
		while(!st.empty()&&st.top()>y)
			ans++,st.pop();
		if(!st.empty()&&st.top()==y)
			st.pop();
		//printf("%d\n",ans);
		st.push(y);
	}
	while(!st.empty()&&st.top()>0)
		ans++,st.pop();
	printf("%d\n",ans);
	return 0;
}