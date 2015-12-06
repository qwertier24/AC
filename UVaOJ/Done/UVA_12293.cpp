#include <stdio.h>
int SG(int x)
{
	x++;
	for(int i=1; i<=30; i++)
		if(!(x^1<<i))
			return 0;
	return 1;
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		if(SG(n))
			printf("Alice\n");
		else
			printf("Bob\n");
	}
	return 0;
}
