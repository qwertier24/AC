#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#include <stack>
using namespace std;
stack<int> st;
int h[100010],t[100010];
int main()
{
	int n,ans=-1;
	scanf("%d",&n);
	t[1]=-1;
	st.push(1);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&h[i]);
		while(!st.empty()&&h[st.top()]<h[i])
		{
			t[i]=max(t[i],t[st.top()]+1);
			st.pop();
		}
		if(st.empty())
			t[i]=-1;
		ans=max(ans,t[i]);
		st.push(i);
	}
	printf("%d\n",ans+1);
	return 0;
}
