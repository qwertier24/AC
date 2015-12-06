#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	priority_queue<int> q;
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		int w;
		scanf("%d",&w);
		q.push(-w);
	}
	while(q.size()!=1)
	{
		int t1=q.top(),t2;
		q.pop();
		t2=q.top();
		q.pop();
		q.push(t1+t2);
		ans+=-t1-t2;
		//printf("%d %d %d\n",t1,t2,ans);
	}
	printf("%d",ans);
	return 0;
}
