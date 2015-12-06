/*
ID: mayukun3
PROG: sprime
LANG: C++
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#define maxn 1<<27
//int prime[1<<27+1];
bool prime(int a)
{
	int loop=sqrt(a);
	for(int i=2; i<=loop; i++)
		if(a%i==0)
			return false;
	return true;
}
/*
void get_prime()
{
	memset(prime,-1,sizeof(prime));
	int loop=sqrt(maxn);
	prime[1]=prime[0]=0;
	for(int i=2; i<=loop; i++)
		if(prime[i])
			for(int j=i*i; j<=maxn; j+=i)
				prime[j]=0;
}
*/
void search(int pos,int deep)
{
	if(!deep)
	{
		if(prime(pos))printf("%d\n",pos);
		return;
	}
	if(!prime(pos))return;
	for(int i=0; i<10; i++)
		search(pos*10+i,deep-1);
}
int main()
{
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	//get_prime();
	int n;
	scanf("%d",&n);
	for(int i=2; i<10; i++)
		if(prime(i))
			search(i,n-1);
}