#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
long long d[50][10];
int main()
{
	char s[60];
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=0; i<10; i++)
		d[n][i]=1;
	for(int i=n-1; i>=1; i--)
	{
		for(int j=0; j<10; j++)
		{
			if((j+s[i+1]-'0')%2)
				d[i][j]=d[i+1][(j+s[i+1]-'0')/2]+d[i+1][(j+s[i+1]-'0')/2+1];
			else
				d[i][j]=d[i+1][(j+s[i+1]-'0')/2];
			//printf("d[%d][%d]=%d\n",i,j,d[i][j]);
		}
	}
	bool flag=true;
	int num[60]={0};
	num[1]=s[1]-'0';
	for(int i=1; i<=n; i++)
	{
		if(num[i]!=s[i]-'0')
		{
			flag=false;
			break;
		}
		//printf("%d\n",num[i]);
		if(s[i+1]-'0'==(num[i]+s[i+1]-'0')/2+1&&(num[i]+s[i+1]-'0')%2)
			num[i+1]=(num[i]+s[i+1]-'0')/2+1;
		else
			num[i+1]=(num[i]+s[i+1]-'0')/2;
	}
	long long ans=0;
	for(int i=0; i<10; i++)
		ans+=d[1][i];
	if(flag)
		ans--;
	cout<<ans;
	return 0;
}
