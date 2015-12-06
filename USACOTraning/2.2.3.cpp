/*
ID: mayukun3
PROG: preface
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <math.h>
using namespace std;
int len,num[10];
map<char,int> mp;
char c10[5]={0,'I','X','C','M'};
char c5[5]={0,'V','L','D'};
char alpha[7]={'I','V','X','L','C','D','M'};
void count(int x)
{
	len=0;
	while(x>0)
	{
		num[++len]=x%10;
		x/=10;
	}
	for(int i=1; i<=len; i++)
	{
		if(num[i]>0)
		{
			if(num[i]<=3)
				mp[c10[i]]+=num[i];
			else if(num[i]<=8)
			{
				mp[c5[i]]++;
				mp[c10[i]]+=abs(num[i]-5);
			}
			else
				mp[c10[i]]++,mp[c10[i+1]]++;
		}
	}
}
int main()
{
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	int n;
	scanf("%d",&n);
	map<char,int>::iterator iter;
	for(int i=1; i<=n; i++)
	{
		count(i);
		for(iter=mp.begin(); iter!=mp.end(); ++iter)
		{
			//printf("%c %d\n",iter->first,iter->second);
		}
	}
	for(int i=0; i<7; i++)
	{
		if(mp[alpha[i]])
			printf("%c %d\n",alpha[i],mp[alpha[i]]);
	}
}