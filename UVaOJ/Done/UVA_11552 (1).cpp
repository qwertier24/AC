#include <stdio.h>
#include <string.h>
#define MAXN 1000
#define INF 200000
int n,len;
inline int begin(int p)
{
	return len/n *(p-1);
}
inline int end(int p)
{
	return len/n *p-1;
}
inline int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int d[MAXN][26],block_num[MAXN];
	bool count[MAXN][26];
	char str[10001];
	memset(count,0,sizeof(count));
	memset(block_num,0,sizeof(block_num));
	memset(d,0,sizeof(d));
	scanf("%d %s",&n,str);
	len=strlen(str);
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<26; j++)
		{
			for(int k=begin(i); k<=end(i); k++)
				if(str[k]=='a'+j)
					count[i][j]++;
			if(count[i][j])block_num[i]++;
		}
	}
	for(int j=0; j<26; j++)
		d[1][j]=block_num[1];
	for(int i=2; i<=n; i++)
		for(int j=0; j<26; j++)
		{
			d[i][j]=INF;
			for(int k=0; k<26; k++)
			{
				if(count[i-1][k] && count[i][k])
					d[i][j]=min(d[i][j],d[i-1][j]+block_num[i]-1);
				else if(count[i-1][k])
					d[i][j]=min(d[i][j],d[i-1][j]+block_num[i]);
			}
		}
	int ans=0;
	for(int i=0; i<26; i++)
		if(count[n][i])
			ans=ans==0?d[n][i]:min(ans,d[n][i]);
	printf("%d\n",ans);
	return 0;
}
