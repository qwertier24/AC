#include <stdio.h>
#include <algorithm>
using namespace std;
int t[1010];
int main()
{
	int T;
	scanf("%d",&T);
	bool first=true;
	//freopen("prob.out","w",stdout);
	while(T--)
	{
		int n,ans=0,p;
		scanf("%d",&n);
		p=n;
		for(int i=1; i<=n; i++)
			scanf("%d",&t[i]);
		sort(t+1,t+n+1);
		while(p>3)
		{
			if(t[2]*2<t[1]+t[p-1])
				ans+=t[p]+t[1]+t[2]+t[2];
			else
				ans+=t[1]+t[1]+t[p]+t[p-1];
			p-=2;
		}
		if(p==1)
			ans+=t[1];
		else if(p==2)
			ans+=t[2];
		else
			ans+=t[2]+t[3]+t[1];
		if(first)
			first=false;
		else
			printf("\n");
		printf("%d\n",ans);
		//output the solution
		p=n;
		while(p>3)
		{
			if(t[2]*2<t[1]+t[p-1])
				printf("%d %d\n%d\n%d %d\n%d\n",t[1],t[2],t[1],t[p-1],t[p],t[2]);
			else
				printf("%d %d\n%d\n%d %d\n%d\n",t[1],t[p],t[1],t[1],t[p-1],t[1]);
			p-=2;
		}
		if(p==1)
			printf("%d\n",t[1]);
		else if(p==2)
			printf("%d %d\n",t[1],t[2]);
		else
			printf("%d %d\n%d\n%d %d\n",t[1],t[2],t[1],t[1],t[3]);
	}
	return 0;
}
