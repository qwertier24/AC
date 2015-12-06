#include <iostream>
#include <stdio.h>
using namespace std;
long long f[1000001];
void Init()
{
	f[2]=0;
	for(long long i=3; i<=1000000; i++)
		f[i]=f[i-1]+( (i-2)*(i-1)/2 - (i-1)/2 )/2;
}
int main()
{
	int n;
	Init();
	while(scanf("%d",&n) && n>=3)
		cout<<f[n]<<endl;
	return 0;
}
