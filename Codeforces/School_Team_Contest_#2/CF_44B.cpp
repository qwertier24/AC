#include <stdio.h>
int c;
bool check(int rem)
{
	//printf("%d \n",rem);
	if(rem<0||rem%4||rem/4>c)
		return false;
	else
		return true;
}
int main()
{
	int n,a,b;
		long long ans=0;
	scanf("%d%d%d%d",&n,&a,&b,&c);
	n*=2;
	for(int i=0; i<=a; i++)
		for(int j=0; j<=b; j++)
			if(check(n-i-2*j))
			{
				ans++;
				//printf("%d %d\n",i,j);
			}
	printf("%I64d",ans);
	return 0;
}
