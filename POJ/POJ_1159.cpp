#include <stdio.h>
#include <algorithm>
using namespace std;
char s1[5010],s2[5010];
int n;
short d[5001][5001]={0},ans=10000;
void reserve()
{
	for(int i=1; i<=n; i++)
		s2[i]=s1[n-i+1];
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s1+1);
	reserve();
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			if(s1[i]==s2[j])
				d[i][j]=d[i-1][j-1]+1;
			else
				d[i][j]=max(d[i-1][j],d[i][j-1]);
		}
	for(int i=1; i<=n; i++)
	{
		//printf("%d %d\n",n-1-2*d[i-1][n-i],d[i][n-i]);
		ans=min(ans,min(short(n-1-2*d[i-1][n-i]),(short)(n-2*d[i][n-i])));
	}
	printf("%d",ans);
	return 0;
}
