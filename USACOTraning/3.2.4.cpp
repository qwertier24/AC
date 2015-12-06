/*
ID: mayukun3
PROG: spin
LANG: C++
*/
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
struct SPIN
{
	int s,e,v,p;
	void plus()
	{
		s+=v;
		e+=v;
	}
};
vector<SPIN> spins;
int round[360];
bool check()
{
	memset(round,0,sizeof(round));
	for(int i=0; i<spins.size(); i++)
		for(int j=spins[i].s; j<=spins[i].e; j++)
			if(round[j%360]==spins[i].p-1)
				round[j%360]=spins[i].p;
	///for(int i=0; i<360; i++)
	//	printf("%d\n",round[i]);
	for(int i=0; i<360; i++)
	{
		//printf("%d",round[i]);
		if(round[i]==5)
			return true;
	}
	return false;
}
int main()
{
	freopen("spin.in","r",stdin);freopen("spin.out","w",stdout);
	for(int i=1; i<=5; i++)
	{
		int vt,nt,st,lt;
		scanf("%d %d",&vt,&nt);
		for(int j=0; j<nt; j++)
		{
			scanf("%d%d",&st,&lt);
			spins.push_back((SPIN){st,st+lt,vt,i});
		}
	}
	for(int i=0; i<360; i++)
	{
		//if(i==1)
		//	for(int i=0; i<spins.size(); i++)
		//		printf("%d %d %d\n",spins[i].s,spins[i].e,spins[i].p);
		if(check())
		{
			printf("%d\n",i);
			return 0;
		}
		for(int j=0; j<spins.size(); j++)
			spins[j].plus();
	}
	printf("none\n");
	return 0;
}