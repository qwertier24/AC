#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
long long dp[1<<17];
int mega,weapon[17];
int cover[1<<17];
int get_num()
{
	char t=getchar();
	while(t!='0'&&t!='1')
		t=getchar();
	return t-'0';
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int kase=1; kase<=T; kase++)
	{
		int n;
		char s[20];
		scanf("%d",&n);
		int all=(1<<n)-1;
		mega=0;
		memset(dp,0,sizeof(dp));
		memset(weapon,0,sizeof(weapon));
		memset(cover,0,sizeof(cover));
		for(int i=0; i<n; i++)
		{
			mega|=get_num()<<i;
		}
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
			{
				weapon[i]|=get_num()<<j;
			}
        }
		dp[0]=1;
		for(int S=0; S<=all; S++)
		{
			cover[S]=mega;
			for(int i=0; i<n; i++)
			{
				if(S&(1<<i))
				{
					cover[S]|=weapon[i];
				}
			}
		}
		for(int S=1; S<=all; S++)
		{
			for(int i=0; i<n; i++)
			{
				if(S&(1<<i) && cover[S^(1<<i)]&(1<<i))
				{
					dp[S]+=dp[S^(1<<i)];
				}
			}
		}
		cout<<"Case "<<kase<<":"<<dp[all]<<endl;
	}
	return 0;
}
