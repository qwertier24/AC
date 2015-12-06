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
int d1[100002]={0},d2[100002]={0},num[100001];
int main()
{
	int n;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(d1,0,sizeof(d1));
		memset(d2,0,sizeof(d2));
		int ans=-(1<<30);
		stack<int> st;
		for(int i=1; i<=n; i++)
			scanf("%d",&num[i]);
		for(int i=n; i>=1; i--)
		{
			d2[i]=max(d2[i+1]+num[i],num[i]);
			if(st.empty()||d2[i]>d2[st.top()])
				st.push(i);
		}
		for(int i=1; i<n; i++)
		{
			d1[i]=max(d1[i-1]+num[i],num[i]);
			if(st.top()==i)
				st.pop();
			ans=max(ans,d1[i]+d2[st.top()]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
