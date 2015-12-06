#include <stdio.h>
#include <cstring>
int d1[101][200],p[101],d2[101][200];
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		if(n==1)
		{
			printf("1\n");continue;
		}
		memset(d1,0,sizeof(d1));
		memset(d2,0,sizeof(d2));
		p[0]=1;
		for(int i=1; i<=100; i++)
			p[i]=(p[i-1]*10)%n;
		d1[1][1]=1;
		int digit;
		for(int i=2; i<=100; i++)
		{
			for(int j=0; j<n; j++)
				if(d1[i-1][j])
				{
					d1[i][(j*10)%n]=1;
					d1[i][(j*10+1)%n]=1;
				}
			if(d1[i][0])
			{
				digit=i;
				break;
			}
		}
		d2[0][0]=d2[1][0]=d2[1][1]=1;
		for(int i=2; i<=100; i++)
		{
			for(int j=0; j<n; j++)
				if(d2[i-1][j])
				{
					d2[i][(j*10)%n]=1;
					d2[i][(j*10+1)%n]=1;
				}
		}
		int rem=0;
		printf("1");
		rem=((rem-p[digit-1])%n+n)%n;
		//printf("!!!%d\n",d2[2][1]);
		for(int i=digit-1; i>=1; i--)
		{
			//printf("  %d\n",rem);
			if(d2[i-1][((rem-p[i-1])%n+n)%n])
			{
				printf("1");
				rem=((rem-p[i-1])%n+n)%n;
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}
