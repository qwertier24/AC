#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
char s1[300],s2[300],s3[500];
int d[401][201];
int T,n1,n2,n3;
bool check(int p)
{
	for(int i=1; i<=p&&i<=n1; i++)
		if(s1[i]==s3[p]&&d[p-1][i-1])
			d[p][i]=1;
	//printf("%d\n",s2[1]==s3[p]&&d[p-1][0]);
	for(int i=1; i<=p&&i<=n2; i++)
	{
		//printf("%d\n",d[p][p-i]);
		if(s2[i]==s3[p]&&d[p-1][p-i])
			d[p][p-i]=1;
		//printf("%d\n",d[p][p-i]);
	}
	for(int i=0; i<=p&&i<=n1; i++)
		if(d[p][i])
			return true;
	return false;
}
int main()
{
	scanf("%d",&T);
	for(int kase=1; kase<=T; kase++)
	{
		bool ok=true;
		memset(d,0,sizeof(d));
		d[0][0]=1;
		scanf("%s%s%s",s1+1,s2+1,s3+1);
		n1=strlen(s1+1),n2=strlen(s2+1),n3=strlen(s3+1);
		if(n3!=n1+n2)
		{
			printf("Data set %d: no\n",kase);
			continue;
		}
		for(int i=1; i<=n3; i++)
			if(!check(i))
			{
				//printf("I:%d\n",i);
				//for(int j=0; j<=i&&j<=n1; j++)
				//	printf("d[%d][%d]:%d\n",i,j,d[i][j]);
				ok=false;
				break;
			}
		if(ok)
			printf("Data set %d: yes\n",kase);
		else
			printf("Data set %d: no\n",kase);
	}
	return 0;
}
