/*
ID: mayukun3
PROG: numgrid
LANG: C++
*/
#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
using namespace std;
map<string,int> mp;
int g[5][5],addx[4]={-1,0,1,0},addy[4]={0,1,0,-1},ans=0;
string s("aaaaaa");
void search(int x,int y,int deep)
{
	s[deep]=g[x][y]+'0';
	if(deep==5)
	{
		if(!mp.count(s))
		{
			mp[s]=1;
			ans++;
			//cout<<x<<" "<<y<<" "<<s<<endl;
		}
		return;
	}
	for(int i=0; i<4; i++)
		if(x+addx[i]>=0&&x+addx[i]<5&&y+addy[i]>=0&&y+addy[i]<5)
			search(x+addx[i],y+addy[i],deep+1);
}
int main()
{
	freopen("numgrid.in","r",stdin);freopen("numgrid.out","w",stdout);
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			scanf("%d",&g[i][j]);
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			search(i,j,0);
	printf("%d\n",ans);
	return 0;
}