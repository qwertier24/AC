#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int n,w[5010],e[5010];
bool check(int v)
{
	int wDec=0,eDec=0,allDec=0,wRem=0,eRem=0;
	for(int i=1; i<=n; i++)
	{
		eRem+=e[i];
		wRem+=w[i];
		while(wRem>v)
		{
			if(!wDec||!allDec)
				return false;
			wDec--;
			allDec--;
			wRem--;
		}
		while(eRem>v)
		{
			if(!eDec||!allDec)
				return false;
			eDec--;
			allDec--;
			eRem--;
		}
		if(wDec<wRem)
			wDec++;
		if(eDec<eRem)
			eDec++;
		if(allDec<wRem+eRem)
			allDec++;
		//printf("%d %d %d %d %d\n",wRem,eRem,wDec,eDec,allDec);
	}
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d%d",&w[i],&e[i]);
		int l=1, r=10*5000;
		while(l<r)
		{
			int m=(l+r)>>1;
			if(check(m))
				r=m;
			else
				l=m+1;
		}
		printf("%d\n",l-1);
	}
	return 0;
}
