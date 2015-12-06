/*
ID: mayukun3
PROG: milk3
LANG: C++
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <map>
#include <vector>
using namespace std;
int v[3];
bool ans[40]={0};
struct POS
{
	int remain[3];
	bool operator<(const POS& a)const 
	{
		for(int i=0; i<=2; i++)
		{
			if(remain[i]<a.remain[i])
				return true;
			else if(remain[i]>a.remain[i])
				return false;
		}
	}
};
void count(POS t)
{
	if(t.remain[0]==0)
		ans[t.remain[2]]=true;
}
map<POS,bool> mp;
void cpy(POS& a,POS& b)
{
	for(int i=0; i<3; i++)
		b.remain[i]=a.remain[i];
}
void search(POS pos)
{
	if(mp.count(pos)!=0)
		return;
	//printf("%d %d %d\n",pos.remain[0],pos.remain[1],pos.remain[2]);
	mp[pos]=true;
	count(pos);
	for(int i=0; i<3; i++)
		if(pos.remain[i])
			for(int j=0; j<3; j++)
				if(v[j]-pos.remain[j]&&i!=j)
				{
					POS t;
					cpy(pos,t);
					if(v[j]-t.remain[j]<t.remain[i])
					{
						t.remain[i]-=v[j]-t.remain[j];
						t.remain[j]=v[j];
					}
					else
					{
						t.remain[j]+=t.remain[i];
						t.remain[i]=0;
					}
					search(t);
				}
}
int main()
{
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	POS pos;
	scanf("%d%d%d",&v[0],&v[1],&v[2]);
	pos.remain[0]=pos.remain[1]=0;
	pos.remain[2]=v[2];
	search(pos);
	vector<int> va;
	for(int i=0; i<=v[2]; i++)
		if(ans[i])
			va.push_back(i);
	printf("%d",va[0]);
	for(int i=1; i<va.size(); i++)
		printf(" %d",va[i]);
	printf("\n");
	return 0;
}
