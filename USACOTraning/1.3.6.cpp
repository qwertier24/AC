/*
ID: mayukun3
PROG: crypt1
LANG: C++
*/
#include <stdio.h>
bool num[10]={0};
bool check(int ta,int lent)
{
	int a=ta,len=0;
	while(a>0)
	{
		if(!num[a%10])
			return false;
		a/=10;
		len++;
	}
	if(len!=lent)
		return false;
	return true;
}
int main()
{
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	int n,ans=0;
	scanf("%d",&n);
	while(n--)
	{
		int t;
		scanf("%d",&t);
		num[t]=true;
	}
	for(int i=100; i<1000; i++)
		for(int j=10; j<100; j++)
		{
			if(check(j,2)&&check(i,3)&&check(i*(j%10),3)&&check(i*(j/10),3)&&check(i*j,4))
				ans++;
		}
	printf("%d\n",ans);
}