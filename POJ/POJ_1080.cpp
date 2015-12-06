#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int n1,n2,d[110][110];
char s1[200],s2[200];
int sum(char a,char b)
{
	if(a==b)
		return 5;
	else
	{
		if(isalpha(a)&&isalpha(b)&&a>b)
			swap(a,b);
		else if(a=='-')
			swap(a,b);
		if((a=='A'&&b=='C')||(a=='A'&&b=='T')||(a=='T'&&b=='-'))
			return -1;
		else if((a=='A'&&b=='G')||(a=='C'&&b=='T')||(a=='G'&&b=='T')||(a=='G'&&b=='-'))
			return -2;
		else if((a=='A'&&b=='-')||(a=='C'&&b=='G'))
			return -3;
		else
			return -4;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s%d%s",&n1,s1+1,&n2,s2+1);
		//printf("%c %c\n",s1[1],s2[1]);
		d[0][0]=0;
		for(int i=1; i<=n1; i++)
		{
			d[i][0]=d[i-1][0]+sum(s1[i],'-');
			d[0][i]=d[0][i-1]+sum(s2[i],'-');
		}
		for(int i=1; i<=n1; i++)
			for(int j=1; j<=n2; j++)
			{
				d[i][j]=max(max(d[i-1][j]+sum(s1[i],'-'),d[i][j-1]+sum(s2[j],'-')),sum(s1[i],s2[j])+d[i-1][j-1]);
				//printf("%d %d %d %d\n",i,j,d[i][j],sum(s1[i],s2[j]));
			}
		printf("%d\n",d[n1][n2]);
	}
	return 0;
}
