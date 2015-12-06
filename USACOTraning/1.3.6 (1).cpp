/*
ID: mayukun3
PROG: crypt1
LANG: C++
*/
#include <stdio.h>
#include <string.h>
bool exist[10];
int ans=0;
bool check(int x,int y)
{
	int len=0;
	while(x>0)
	{
		len++;
		if(!exist[x%10])
			return false;
		x/=10;
	}
	if(len==y)
		return true;
	else
		return false;
}
int main()
{
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	int n;
	scanf("%d",&n);
	memset(exist,0,sizeof(exist));
	for(int i=1; i<=n; i++)
	{
		int c;
		scanf("%d",&c);
		exist[c]=true;
	}
	for(int i=100; i<=999; i++)
		for(int j=10; j<=99; j++)
			if(check(i,3)&&check(j,2)&&check(i*(j%10),3)&&check(i*(j/10),3)&&check(i*j,4))
				ans++;
	printf("%d",ans);
}