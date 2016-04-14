#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <stack>
#include <cstring>
#include <math.h>
using namespace std;
int top_height[30][30]={0},g[30][30]={0},width[30],height[30];
char s[100];
int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%s",s);
		for(int j=0; j<m; j++)
			g[i][j+1]=!(s[j]-'0');
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(g[i][j])
				top_height[i][j]=top_height[i-1][j]+1;
		}
	}
	for(int i=1; i<=n; i++)
	{
		stack<int> st;
		st.push(0);
		memset(width,0,sizeof(width));
		memset(height,0,sizeof(height));
		for(int j=1; j<=m; j++)
		{
			while(!st.empty()&&top_height[i][st.top()]>=top_height[i][j])
				st.pop();
			if(g[i][j])
			{
				int w1=width[st.top()]+j-st.top(),w2=j-st.top(),h1=height[st.top()],h2=top_height[i][j];
				if(w1+h1>w2+h2)
					width[j]=w1,height[j]=h1;
				else
					width[j]=w2,height[j]=h2;
			}
			ans=max(ans,width[j]+height[j]);
			st.push(j);
		}
	}
	printf("%d",ans*2);
	return 0;
}
