#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int ans,cnt[1<<10],n,k,g[10];
void Init()
{
	for(int i=0; i<(1<<8); i++)
	{
		cnt[i]=0;
		for(int j=0; j<8; j++)
			if((i>>j)&1)
				cnt[i]++;
	}
}
void search(int deep,int pos)
{
	if(cnt[pos]==k)
	{
		//printf("   %d\n",pos);
		ans++;
		return;
	}
	if(deep==n)
		return;
	int t=(((1<<n)-1)^pos)&g[deep];
	//printf("%d %d %d\n",deep,pos,t);
	for(int i=0; i<n; i++)
		if((t>>i)&1)
			search(deep+1,pos|(1<<i));
	search(deep+1,pos);
}
int main()
{
	Init();
	char s[100];
	while(scanf("%d%d",&n,&k)&&n!=-1)
	{
		ans=0;
		for(int i=0; i<n; i++)
		{
			g[i]=0;
			scanf("%s",s);
			for(int j=0; j<n; j++)
				g[i]=(g[i]<<1)|(s[j]=='#');
			//printf("g[%d]=%d\n",i,g[i]);
		}
		for(int i=0; i<n; i++)
			if((g[0]>>i)&1)
				search(1,1<<i);
		search(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
