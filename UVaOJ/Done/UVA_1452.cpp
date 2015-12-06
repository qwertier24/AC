#include <stdio.h>
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int ans=(k-1)%3;
	for(int i=4; i<=n; i++)
		ans=(ans+k)%i;
	ans++;
	if(!ans)ans=n;
	printf("%d ",ans);
	ans=(k-1)%2;
	for(int i=3; i<=n; i++)
		ans=(ans+k)%i;
	ans++;
	if(ans==0)ans=n;
	printf("%d ",ans);
	ans=0;
	for(int i=2; i<=n; i++)
		ans=(ans+k)%i;
	ans++;
	if(ans==0)ans=n;
	printf("%d\n",ans);
	return 0;
}
