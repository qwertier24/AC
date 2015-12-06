#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
char s1[1010],s2[1010];
int d[1010][1010]={0};
int main()
{
	while(scanf("%s%s",s1+1,s2+1)!=EOF)
	{
		int n1=strlen(s1+1),n2=strlen(s2+1);
		for(int i=1; i<=n1; i++)
			for(int j=1; j<=n2; j++)
				d[i][j]=(s1[i]==s2[j])?d[i-1][j-1]+1:max(d[i][j-1],d[i-1][j]);
		printf("%d\n",d[n1][n2]);
	}
	return 0;
}
