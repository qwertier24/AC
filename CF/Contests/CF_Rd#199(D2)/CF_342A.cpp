#include <stdio.h>
#include <vector>
using namespace std;
vector<int> ans;
int nt,num[10]={0};
char cas[4][10]={"1 2 4\n","1 3 6\n","2 3 6\n","1 2 6\n"};
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&nt);
		num[nt]++;
	}
	if(num[7]||num[5])
	{
		printf("-1\n");
		return 0;
	}
	bool ok=true;
	for(int i=1; i<=num[4]; i++)
	{
		if(!num[1]||!num[2])
		{
			printf("-1\n");
			return 0;
		}
		num[1]--;
		num[2]--;
		ans.push_back(0);
	}
	//printf("%d %d %d %d %d %d\n",num[1],num[2],num[3],num[4],num[5],num[6]);
	for(int i=1; i<=num[3]; i++)
	{
		if(!num[1])
		{
			printf("-1\n");
			return 0;
		}
			ans.push_back(1);
			num[1]--;
			num[6]--;
	}
	if(num[6]<0||num[1]!=num[2]||num[1]!=num[6]||num[2]!=num[6])
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1; i<=num[6]; i++)
		ans.push_back(3);
	for(int i=0; i<ans.size(); i++)
		printf("%s",cas[ans[i]]);
	return 0;
}
