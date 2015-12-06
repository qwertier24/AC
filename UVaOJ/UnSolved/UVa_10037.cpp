#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int t[1001],crossed[1001],crossing[1001],n;
vector<int> ans;
int main()
{
	int min_t=0;
	scanf("%d",&n);
	memset(crossed,0,sizeof(crossed));
	for(int i=1; i<=n; i++)
		scanf("%d",&t[i]),crossing[i]=1;
	sort(t+1,t+n+1);
	crossed[1]=crossed[2]=1;
	crossing[1]=crossing[2]=0;
	ans.push_back(t[1]);
	ans.push_back(t[2]);
	min_t+=t[2];
	for(int i=3; i<=n; i++)
	{
		if(n!=i&&t[i+1]+t[1]+t[2]+t[2]<=t[i]+t[i+1]+t[1]+t[1])
		{
			min_t+=t[i+1]+t[1]+t[2]+t[2];
			ans.push_back(t[1]);
			ans.push_back(t[i]);
			ans.push_back(t[i+1]);
			ans.push_back(t[2]);
			ans.push_back(t[1]);
			ans.push_back(t[2]);
			i++;
		}
		else
		{
			min_t+=t[i]+t[1];
			ans.push_back(t[1]);
			ans.push_back(t[1]);
			ans.push_back(t[i]);
		}
	}
	printf("%d\n",min_t);
	for(int i=0; i<ans.size(); i++)
		printf("%d\n",ans[i]);
	for(int i=0; i<ans.size(); i++)
	{
		if(i%3)
		{
			printf("%d\n",ans[i]);
		}
		else
		{
			printf("%d %d\n",ans[i],ans[i+1]);
			i++;
		}
	}
	return 0;
}
