#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN 10000000
int prime[10000],next_prime[10000];
void Init()
{
	memset(prime,-1,sizeof(prime));
	int loop=(int)(sqrt(MAXN)+0.5),t=MAXN;
	for(int i=2; i<=loop; i++)
		if(prime[i])
			for(int j=i+i; j<=loop; j+=i)
				prime[j]=0;
	for(int i=loop; i>=2; i--)
		if(prime[i])
		{
			next_prime[i]=t;
			t=i;
		}
}
int main()
{
	Init();
	int T;
	scanf("%d",&T);
	while(T--)
	{
	int A,C,B=1;
	scanf("%d%d",&A,&C);
	int i=2;
	if(C%A){printf("NO SOLUTION\n");continue;}
	C/=A;
	while(A!=1 && C!=1)
	{
		int a=0,c=0,A0=A,C0=C;
		while(A%i==0){A/=i; a++;}
		while(C%i==0){C/=i; c++;}
		if(c)
			B*=(A0/A)*(C0/C);
		i=next_prime[i];
	}
	B*=C;
	printf("%d\n",B);
	}
	return 0;
}
