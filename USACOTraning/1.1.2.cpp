/*
ID: mayukun3
PROG: ride
LANG: C++
*/
#include <stdio.h>
#include <string.h>
int main()
{
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	char a[8];
	scanf("%s",a);
	int len=strlen(a),n2=1,n=1;
	for(int i=0; i<len; i++)
		n*=a[i]-'A'+1;
	scanf("%s",a);
	len=strlen(a);
	for(int i=0; i<len; i++)
		n2*=a[i]-'A'+1;
	if(n%47==n2%47)
		printf("GO\n");
	else
		printf("STAY\n");
	return 0;
}
