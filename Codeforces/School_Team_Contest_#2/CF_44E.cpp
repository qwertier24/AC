#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
string ans[201];
char s[210];
int main()
{
	int k,a,b,len;
	scanf("%d%d%d",&k,&a,&b);
	scanf("%s",s+1);
	len=strlen(s+1);
	if(len<a*k||len>b*k)
		printf("No solution");
	else
	{
		int p=1;
		int length=len/k,rem=len%k;
		for(int i=1; i<=k; i++)
		{
			for(int j=1; j<=length; j++)
				ans[i].push_back(s[p++]);
			if(rem)
			{
				rem--;
				ans[i].push_back(s[p++]);
			}
		}
		for(int i=1; i<=k; i++)
			cout<<ans[i]<<endl;
	}
	return 0;
}
