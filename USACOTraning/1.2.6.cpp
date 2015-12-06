/*
ID: mayukun3
PROG: dualpal
LANG: C++
*/
#include <stdio.h>
struct BIGN
{
	int len,num[100];
}b;
bool check(int a,int n)
{
	b.len=0;
	while(a>0)
	{
		b.num[++b.len]=a%n;
		a/=n;
	}
	for(int i=1; i<=b.len/2; i++)
		if(b.num[i]!=b.num[b.len-i+1])
			return false;
	return true;
}
int main()
{
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int n,s,count=0;
	scanf("%d%d",&n,&s);
	for(int i=s+1;count<n; i++)
	{
		bool first=false;
		for(int j=2; j<=10; j++)
			if(check(i,j))
			{
				if(first)
				{
					printf("%d\n",i);
					count++;
					break;
				}
				else
					first=true;
			}
	}
}