#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int gcd(int a,int b)
{
	while(a)
	{
		int t=a;
		a=b%a;
		b=t;
	}
	return b;
}
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(b*c==d*a)
		printf("0/1");
	else if(b*c<d*a)
		printf("%d/%d",(a*d-c*b)/gcd(a*d-c*b,a*d),(a*d)/gcd(a*d-c*b,a*d));
	else
		printf("%d/%d",(c*b-a*d)/gcd(c*b-a*d,c*b),(c*b)/gcd(c*b-a*d,c*b));
	return 0;
}
