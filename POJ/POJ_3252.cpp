#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int C[32][32];
void Init()
{
	memset(C,0,sizeof(C));
	for(int i=0; i<=30; i++)
	{
		C[i][0]=1;
		for(int j=1; j<=i; j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
}
int sum(int r)
{
	if(r==0)
		return 0;
	int one_num=0,ret=0,first=0,zero_num=0,digits=floor(log2(r));
	for(int i=digits; i>=0; i--)
	{
		if((r>>i)&1)
		{
			if(one_num)
			{
				zero_num++;
				for(int j=0; j+one_num<=zero_num+i-j; j++)
				{
					ret+=C[i][j];
					//printf(" %d %d %d\n",i,j,ret);
				}
			}
			else
			{
				for(int j=i; j>=2; j--)
					for(int k=0; k<=j/2-1; k++)
					{
						ret+=C[j-1][k];
						//printf("  %d %d %d %d\n",j,k,ret,C[j-1][k]);
					}
			}
			//printf("%d %d %d\n",i,one_num,ret);
			if(one_num)
				zero_num--;
			one_num++;
		}
		else
			zero_num++;
	}
	if(one_num<=zero_num)
		ret++;
	return ret;
}
int main()
{
	Init();
	int a,b;
	//printf("%d\n",C[30][15]);
	scanf("%d%d",&a,&b);
	printf("%d\n",sum(b)-sum(a-1));
	return 0;
}
