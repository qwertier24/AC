#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define INF 99999999
int part_len,d[1002][30],exist[1002][30],count[1002];
inline int min(int a,int b)
{
	return a<b?a:b;
}
int begin(int pos)
{
	return (pos-1)*part_len;
}
int end(int pos)
{
	return pos*part_len-1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		char s[1002];
		memset(count,0,sizeof(count));
		memset(exist,0,sizeof(exist));
		scanf("%d",&part_len);
		scanf("%s",s);
		n=strlen(s)/part_len;
		for(int i=1; i<=n; i++)
			for(int j='a'; j<='z'; j++)
			{
				for(int k=begin(i); k<=end(i); k++)
					if(s[k]==j)
						exist[i][j-'a']++;
				if(exist[i][j-'a'])
					count[i]++;
			}
		for(int i=1; i<=n; i++)
			for(int j=0; j<26; j++)
			{
				d[i][j]=INF;
				for(int k=0; k<26; k++)
				{
					if(exist[i-1][k] && exist[i][k] && (j!=k||count[i]<=1))
						d[i][j]=min(d[i][j],d[i-1][k]+count[i]-1);
					else if(exist[i][k])
						d[i][j]=min(d[i][j],d[i-1][k]+count[i]);
				}
			}
		int ans=INF;
		for(int i=0; i<26; i++)
			ans=min(ans,d[n][i]);
		printf("%d\n",ans);

	}
	return 0;
}
