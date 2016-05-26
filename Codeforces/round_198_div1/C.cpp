#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define MOD 1000000007
using namespace std;
int mark[2010]={0},posn,num,n=0,m=0;
long long d[2010][2010]={0},fact[2010];
int main()
{
	fact[0]=1;
	for(int i=1; i<=2000; i++)
		fact[i]=(fact[i-1]*i)%MOD;
	scanf("%d",&posn);
	for(int i=1; i<=posn; i++)
	{
		scanf("%d",&num);
		if(num!=-1)
		{
			mark[num]=2;
			if(!mark[i])
				mark[i]=1;
		}
	}
	for(int i=1; i<=posn; i++)
	{
		if(mark[i]==0)
			m++;
		else if(mark[i]==1)
			n++;
	}
	//printf("%d %d\n",n,m);
	for(int i=0; i<=n+1000; i++)
		d[i][0]=fact[i];
	for(int i=0; i<=n+1000; i++)
		d[i][1]=(i*fact[i])%MOD;
	for(int j=2; j<=m; j++)
		for(int i=0; i<=n+1000; i++)
		{
			d[i][j]=(d[i+1][j-2]*(j-1)+d[i][j-1]*i)%MOD;
			//printf("%d %d %d %d %d\n",i,j,d[i][j],d[i+1][j-2],d[i][j-1]);
		}
	printf("%d\n",d[n][m]);
	return 0;
}
