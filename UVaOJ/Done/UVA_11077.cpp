#include <stdio.h>
unsigned long long f[22][22]={0};
void Init()
{
	f[1][0]=1;
	for(int i=2;i<=21; i++)
		for(int j=0; j<i; j++)
		{
			f[i][j]=f[i-1][j];
			if(j)
				f[i][j]+=f[i-1][j-1]*(long long)(i-1);
		}
}
int main()
{
	Init();
	int n,k;
	while(scanf("%d%d",&n,&k)&&n)
	{
		printf("%llu\n",f[n][k]);
	}
	return 0;
}
