#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int m;
int main()
{
	int n,mark[2]={0};
	bool ok=true;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&m);
		if(m==25)
		{
			mark[0]++;
			continue;
		}
		else if(m==50)
		{
			if(mark[0])
			{
				mark[0]--;
				mark[1]++;
			}
			else
			{
				ok=false;
				break;
			}
		}
		else
		{
			if(mark[1]&&mark[0])
			{
				mark[1]--;
				mark[0]--;
			}
			else if(mark[0]>=3)
			{
				mark[0]-=3;
			}
			else
			{
				ok=false;
				break;
			}
		}
	}
	if(ok)
		printf("YES");
	else
		printf("NO");
	return 0;
}
