#include <stdio.h>
#include <stack>
using namespace std;
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		int t=0,p=0,ans,num;
		stack<int> st;
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&num);
			for(int i=t+1; i<=num; i++)
				st.push(++p);
			p++;
			ans=(p-st.top()-1)/2+1;
			st.pop();
			t=num;
			printf("%d ",ans);
		}
		printf("\n");
	}
	return 0;
}
