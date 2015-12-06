#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <queue>
#include <map>
#include <string.h>
#include <iostream>
using namespace std;
map<unsigned long long,bool> mp;
int prime[65];
void Init()
{
	memset(prime,-1,sizeof(prime));
	int maxn=100;
	for(int i=2; i<=maxn/i; i++)
		if(prime[i])
			for(int j=i*i; j<=maxn; j+=i)
				prime[j]=0;

}
int main()
{
	Init();
	for(int i=2; i<=(1<<16)-1; i++)
	{
		unsigned long long t=((unsigned long long)i*(unsigned long long)i)*((unsigned long long)i*(unsigned long long)i);
		for(int j=4; j<=floor(64.0*(1.0/log2(i))); j++)
		{
			if(!prime[j])
			{
				if(mp.count(t)==0)
					mp[t]=true;
			}
			t*=i;
		}
	}
	map<unsigned long long,bool>::iterator it=mp.begin();
	it++;
	printf("1\n");
	while(it!=mp.end())
	{
		cout<<it->first<<endl;
		it++;
	}
	return 0;
}
