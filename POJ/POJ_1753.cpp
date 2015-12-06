#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#define INF 1<<30
#include <math.h>
using namespace std;
int p0,addx[4]={-1,0,1,0},addy[4]={0,1,0,-1};
int cnt(int pos)
{
	int ret=0;
	for(int i=0; i<17; i++)
		if((pos>>i)&1)
			ret++;
	return ret;
}
bool check(int pos)
{
	int pt=p0;
	for(int i=0; i<16; i++)
		if((pos>>i)&1)
		{
			int xt=i/4,yt=i%4;
			pt^=(1<<i);
			for(int j=0; j<4; j++)
				if(xt+addx[j]>=0&&xt+addx[j]<4&&yt+addy[j]<4&&yt+addy[j]>=0)
					pt^=(1<<((xt+addx[j])*4+yt+addy[j]));
		}
	if(pt==(1<<16)-1||pt==0)
		return true;
	else
		return false;
}
int main()
{
	int ans=INF;
	char s[10];
	p0=0;
	for(int i=0; i<4; i++)
	{
		scanf("%s",s);
		for(int j=0; j<4; j++)
			p0=(p0<<1)|(s[j]=='b');
	}
	
	for(int i=0; i<(1<<16); i++)
		if(check(i))
			ans=min(cnt(i),ans);
	if(ans==INF)
		printf("Impossible\n");
	else
		printf("%d",ans);
	
	return 0;
}
