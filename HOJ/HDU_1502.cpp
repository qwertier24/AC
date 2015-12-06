#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
struct BIGN
{
	char len,num[80];
	void operator+=(const BIGN& t)
	{
		len=max(len,t.len);
		for(int i=1; i<=len; i++)
			num[i]+=t.num[i];
		short c=0;
		for(int i=1; i<=len||c; i++)
		{
			if(i>len)len++;
			num[i]+=c;
			c=num[i]/10;
			num[i]%=10;
		}
	}
	void print()
	{
		for(int i=len; i>=1; i--)
			printf("%d",num[i]);
		printf("\n\n");
	}
}d[62][62][62];
int n;
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
	memset(d,0,sizeof(d));
	d[0][0][0].len=1;
	d[0][0][0].num[1]=1;
	for(int l=0; l<=n+n+n; l++)
		for(int i=0; i<=n; i++)
			for(int j=0; j<=n; j++)
			{
				if(i>=j&&j>=(l-i-j)&&l-i-j>=0)
				{
					//printf("%d %d %d %d\n",i,j,l-i-j,d[i][j][l-i-j]);
					d[i+1][j][l-i-j]+=d[i][j][l-i-j];
					d[i][j+1][l-i-j]+=d[i][j][l-i-j];
					d[i][j][l-i-j+1]+=d[i][j][l-i-j];
				}
			}
	d[n][n][n].print();
	}
	return 0;
}
