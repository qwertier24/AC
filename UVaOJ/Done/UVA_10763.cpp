#include <stdio.h>
#include <string.h>
int g[1001][1001];
struct FT
{
	int f,t;
}stu[5000001];
int main()
{
	bool ok;
	int n,f,t;
	while(scanf("%d",&n)&&n)
	{
		memset(g,0,sizeof(g));
		ok=true;
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d",&stu[i].f,&stu[i].t);
			if(!g[stu[i].t][stu[i].f])
				g[stu[i].f][stu[i].t]++;
			else
				g[stu[i].t][stu[i].f]--;
		}
		for(int i=1; i<=n; i++)
			if(g[stu[i].f][stu[i].t])
			{
				ok=false;
				break;
			}
		if(ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
