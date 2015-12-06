#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
typedef unsigned long long ULL;
struct FACT
{
	int f,t;
};
vector<FACT> facts;
ULL ans;
int mark[20];
void update_ans()
{
	ULL cnt=1;
	for(int i=0; i<facts.size(); i++)
	{
		//printf("%d %d\n",mark[i],facts[i].f);
		if(mark[i]==facts[i].t)
			cnt*=(ULL)(facts[i].t+1);
	}
	ans+=cnt;
}
void solve(int pos)
{
	if(pos==facts.size())
	{
		update_ans();
		return;
	}
	for(int i=0; i<=facts[pos].t; i++)
	{
		mark[pos]=i;
		solve(pos+1);
	}
}
int main()
{
	int t;
	while(scanf("%d",&t)&&t)
	{
		ans=0;
		facts.clear();
		int nt=t;
		int p;
		for(p=2; p*p<=nt; p++)
			if(nt%p==0)
			{
				int cnt=0;
				while(nt%p==0)
				{
					nt/=p;
					cnt++;
				}
				facts.push_back((FACT){p,cnt});
			}
		if(nt!=1)
			facts.push_back((FACT){p,1});
		solve(0);
		cout<<t<<' '<<(ans+1)/2<<endl;
	}
	return 0;
}
