#include <stdio.h>
#include <string.h>
#define MOD 1000007
int C[501][501];
void Init()
{
	memset(C,0,sizeof(C));
	C[0][0]=1;
	for(int i=1; i<=500; i++)
	{
		C[i][i]=C[0][i]=1;
		for(int j=1; j<i; j++)
			C[j][i]=(C[j-1][i-1] +C[j][i-1])%MOD;
	}
}
int main()
{
	Init();
	int T;
	scanf("%d",&T);
	for(int kase=1; kase<=T; kase++)
	{
		int n,m,k;
		int sum=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0; i<16; i++)
		{
			int b=0,r=n,c=m;
			if(i&1){r--; b++;}
			if(i&2){r--; b++;}
			if(i&4){c--; b++;}
			if(i&8){c--; b++;}
			if(b&1)
			{
				sum=(sum+MOD-C[k][r*c])%MOD;
				//printf("-%d",C[k][r*c]);
			}
			else
			{
				sum=(sum+C[k][r*c])%MOD;
				//printf("+%d",C[k][r*c]);
			}
		}
		printf("Case %d: %d\n",kase,sum);
	}
	return 0;
}
