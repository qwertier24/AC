#include <stdio.h>
#include <algorithm>
using namespace std;
int pos[1000001];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int max_t=0,min_t=0,n,l;
		scanf("%d%d",&l,&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&pos[i]);
			min_t=max(min_t,min(pos[i],l-pos[i]));
			max_t=max(max_t,max(pos[i],l-pos[i]));
		}
		printf("%d %d\n",min_t,max_t);
	}
	return 0;
}
