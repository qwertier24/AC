#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
typedef unsigned long long ULL;
ULL pow10[24],sum[24]={0};
int len;
void Init()
{
	pow10[0]=1;
	for(int i=1; i<=20; i++)
		pow10[i]=pow10[i-1]*10;
	for(int i=1; i<=20; i++)
		sum[i]=sum[i-1]+pow10[(i-1)/2]*9;
}
bool head=true;
void solve(int pos,int s,int first)
{
	if(first)
	{
		int sum=0,digit=0;
		while(sum<s)
		{
			sum+=pow10[(pos-1)/2];
			digit++;
		}
		cout<<digit;
		if(pos>2)
			solve(pos-2,s-pow10[(pos-1)/2]*(digit-1),0);
		cout<<digit;
		return;
	}
	if(pos==1)
	{
		cout<<s-1;
		return;
	}
	int sum=0;
	int digit=0;
	while(pow10[(pos-1)/2]*(digit+1)<s)
		digit++;
	cout<<digit;
	if(pos>2)
		solve(pos-2,s-pow10[(pos-3)/2+1]*digit,0);
	cout<<digit;
}
int main()
{
	int p;
	Init();
	while(scanf("%d",&p)&&p)
	{
		if(p<10)
		{
			printf("%d\n",p);
			continue;
		}
		int len=1;
		while(sum[len]<p)
			len++;
		solve(len,p-sum[len-1],1);
		printf("\n");
	}
	return 0;
}
