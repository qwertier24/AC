#include <stdio.h>
#include <algorithm>
#include <cstring>
#define INF 1<<30
using namespace std;
int d[301]={0},min_pos[301][601],n,m,len[610];
char s[310],words[30];
int main()
{
	scanf("%d%d",&m,&n);
	scanf("%s",s+1);
	memset(min_pos,-1,sizeof(min_pos));
	for(int i=1; i<=m; i++)
	{
		scanf("%s",words+1);
		len[i]=strlen(words+1);
		for(int j=1; j<=n; j++)
		{
			int p=len[i],k=j;
			while(k>=1&&p>=1)
			{
				if(s[k]==words[p])
				p--;
				if(p<1)
					min_pos[j][i]=k;
				k--;
			}
		}
		//printf("%d %d\n",i,min_pos[n][i]);
	}
	for(int i=1; i<=n; i++)
	{
		d[i]=i;
		for(int j=1; j<=m; j++)
			if(min_pos[i][j]!=-1)
				d[i]=min(d[i],d[min_pos[i][j]-1]+i-min_pos[i][j]+1-len[j]);
	}
	printf("%d",d[n]);
	return 0;
}
