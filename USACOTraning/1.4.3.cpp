/*
ID: mayukun3
PROG: clocks
LANG: C++
*/
#include <stdio.h>
#include <string>
using namespace std;
int clock0[10],pow10[10]={1,10,1E2,1E3,1E4,1E5,1E6,1E7,1E8,1E9};
bool change[10][10]={0};
string s[9]={"abde","abc","bcef","adg","bdefh","cfi","degh","ghi","efhi"};
struct BIGN
{
	int len,num[100];
	bool operator<=(const BIGN& t)
	{
		if(len<t.len)
			return true;
		else if(len>t.len)
			return false;
		else
			for(int i=len; i>=1; i--)
			{
				if(num[i]>t.num[i])
					return false;
				else if(num[i]<t.num[i])
					return true;
			}
		return true;
	}
}b,ans;
void Init()
{
	for(int i=1; i<=9; i++)
		for(int j=0; j<s[i-1].size(); j++)
		{
			change[i][s[i-1][j]-'a'+1]=true;
		}
}
bool check(int pos)
{
	int clo[10];
	for(int i=1; i<=9; i++)
		clo[i]=clock0[i];
	for(int i=1; i<=9; i++)
		for(int j=1; j<=9; j++)
			if(change[i][j])
				for(int k=1; k<=(pos/pow10[i-1])%10; k++)
				{
					//printf("%d %d %d %d %d\n",i,j,k,clo[j],(clo[j]+1)%4);
					clo[j]=(clo[j]+1)%4;
				}
	for(int i=1; i<=9; i++)
		if(clo[i])
			return false;
	return true;
}
void count(int pos)
{
	b.len=0;
	for(int i=9; i>=1; i--)
		for(int j=1; j<=(pos/pow10[i-1])%10; j++)
			b.num[++b.len]=i;
	if(ans<=b)
		return;
	else
	{
		for(int i=1; i<=b.len; i++)
			ans.num[i]=b.num[i];
		ans.len=b.len;
	}
}
void search(int deep,int pos)
{
	if(deep==9)
	{
		//printf("%d\n",pos);
		if(check(pos))
		{
			count(pos);
		}
		return;
	}
	for(int i=0; i<4; i++)
		search(deep+1,pos*10+i);
}
int main()
{
	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);
	Init();
	ans.len=999999999;
	for(int i=1; i<=9; i++)
	{
		int t;
		scanf("%d",&t);
		clock0[i]=(t/3)%4;
	}
	check(11);
	for(int i=0; i<4; i++)
		search(1,i);
	printf("%d",ans.num[ans.len]);
	for(int i=ans.len-1; i>=1; i--)
		printf(" %d",ans.num[i]);
	printf("\n");
	return 0;
}
