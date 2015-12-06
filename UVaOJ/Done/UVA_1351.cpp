#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define INF 200000
int d[202][202];
int count(int l,int r,int times)
{
	if(times==1)
		return r-l+1;
	else
	{
		int ret=0;
		while(times)
		{
			times/=10;
			ret++;
		}
		return ret+2+d[l][r];
	}
}
inline int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int times[201][201];
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char str[202];
		scanf("%s",str+1);
		int n=strlen(str+1);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=i; j++)
			{
				int p=i;
				while((i-p>=j && str[p]==str[p+j]) || i-p<j)
					p--;
				times[i][j]=(i-p)/j;
				//printf("times[%d][%d]=%d\n",i,j,times[i][j]);
			}
		memset(d,0,sizeof(d));
		for(int i=1; i<=n; i++)
			for(int j=0; j<i-1; j++)
				d[i][j]=INF;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j+i-1<=n; j++)
			{
				int l=j,r=j+i-1;
				d[l][r]=i;
				//printf("d[%d][%d]=%d\n",l,r,d[l][r]);
				for(int k=1; k<i; k++)
				{
					d[l][r]=min(d[l][r],d[l][r-k*times[r][k]] + count(r-k+1,r,times[r][k]));
					//printf("%d %d %d %d\n",l,r,d[l][r-k*times[r][k]],count(r-k+1,k,times[r][k]));
				}
				//printf("d[%d]=min(%d,%d)\n",i,d[i],d[i-j*times[i][j]] + (times[i][j]==1?j:(j+2+count(times[i][j]))));
			}                                                          
		}
		printf("%d\n",d[1][n]);
	}
	return 0;
}

//d[l][r]=min(d[l][r],d[l][r-k*times[j][k]] + count(r-k+1,k,times[r][k]));
