/*
ID: mayukun3
PROG: prefix
LANG: C++
*/
#include <stdio.h>
#include <string.h>
char P[210][21],s[200011];
int len[210],d[200010]={0};
inline bool cmp(char* a,char* b,int l)
{
	for(int i=0; i<l; i++)
		if(a[i]!=b[i])
			return false;
	return true;
}
int main()
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	int n=0,ans=0;
	while(scanf("%s",P[n])&&P[n][0]!='.')
	{
		len[n]=strlen(P[n]);
		n++;
	}
	while(scanf("%s",s+strlen(s))!=EOF)
	{}
	len[n]=strlen(s);
	for(int i=0; i<len[n]; i++)
		for(int j=0; j<n; j++)
			if(cmp(s+i-len[j]+1,P[j],len[j]))
			{
				if(i-len[j]==-1)
					d[i]=1;
				else if(i-len[j]>=0)
					d[i]=d[i-len[j]];
				if(d[i])
				{
					ans=i+1;
					break;
				}
			}
	printf("%d\n",ans);
}