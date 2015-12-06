#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int point[1001],g0[1001];
struct BLOCK
{
	int n,l,r;
}block[1001];
int g(int x)
{
	return x>0? g0[x]:0;
}
int mex(vector<int>& m)
{
	bool exist[1001]={0};
	if(m.empty())
		return 0;
	sort(m.begin(),m.end());
	if(m[0])return 0;
	exist[0]=true;
	for(int i=1; i<m.size(); i++)
	{
		exist[m[i]]=true;
	}
	for(int i=0; i<m.size(); i++)
		if(!exist[m[i]+1])
			return m[i]+1;
	return m[m.size()-1]+1;
}
bool check(string& game)
{
	//cout<<"GAME:"<<game<<endl;
	int num=0,ans=0;
	int len=game.size();
	for(int i = 0; i < len-2; i++)
		if(game[i] == 'X' && game[i+1] == 'X' && game[i+2] == 'X') 
			return false;
	memset(point,0,sizeof(point));
	if(game.find("XX")!=std::string::npos || game.find("X.X")!=std::string::npos)
		return true;
	for(int i=0; i<len; i++)
		if(game[i]=='X')
		{
			if(i>0)
				point[i+1-2]=1;
			point[i+1-1]=point[i+1]=point[i+2]=point[i+3]=1;
		}
	for(int i=1; i<=len; i++)
	{
		while(point[i] && i<=len)
			i++;
		if(i<=len)
		{
			block[++num].n=1;
			block[num].l=i;
			block[num].r=i;
		}
		i++;
		while(point[i]==0 && i<=len)
		{
			i++;
			block[num].n++;
			block[num].r++;
		}
	}
	for(int i=1; i<=num; i++)
	{
		//
		//printf("Block[%d]=%d\n",i,block[i].n);
		ans^=g(block[i].n);
	}
	return ans!=0;
}
void Init()
{
	g0[1]=g0[2]=g0[3]=1;
	for(int i=4; i<=1000; i++)
	{
		vector<int> m;
		for(int j=1; j<=i; j++)
		{
			if(j-2>=0 && i-3-j>=0)
				m.push_back(g(j-2)^g(i-3-j));
			else if(j-3>=0)
				m.push_back(g(j-3));
			else if(i-3-j>=0)
				m.push_back(g(i-2-j));
		}
		g0[i]=mex(m);
	}
}
int main()
{
	string s;
	Init();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int pos[1001];
		memset(pos,0,sizeof(pos));
		s.clear();
		cin>>s;
		int len=s.size();
		memset(point,0,sizeof(point));
		memset(block,0,sizeof(block));
		if(!check(s))
		{
			printf("LOSING\n");
			printf("\n");
			continue;
		}
		vector<int> v;
		printf("WINNING\n");
		for(int i=0; i<len; i++)
			if(s[i]=='X')
			{
				if(i>0)
					pos[i+1-2]=1;
				pos[i+1-1]=pos[i+1]=pos[i+2]=pos[i+3]=1;
			}
		for(int i=0; i<len; i++)
			if(s[i]!='X')
			{
				s[i]='X';
				if(!check(s))
					v.push_back(i+1);
				s[i]='.';
			}
		printf("%d",v[0]);
		for(int i=0; i<v.size(); i++)
			printf(" %d",v[i]);
		printf("\n");
	}
	return 0;
}
