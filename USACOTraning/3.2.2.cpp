/*
ID: mayukun3
PROG: fact4
LANG: C++
*/
#include <stdio.h>
int ans=1,n,cnt5=0,cnt2=0;
int main()
{
	freopen("fact4.in","r",stdin);freopen("fact4.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		int t=i;
		while(t%5==0)
			t/=5,cnt5++;
		while(t%2==0)
			t/=2,cnt2++;
		ans=(ans*t)%10;
	}
	for(int i=1; i<=cnt2-cnt5; i++)
		ans=(ans*2)%10;
	printf("%d\n",ans);
	return 0;
}