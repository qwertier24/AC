/*
ID: mayukun3
PROG: fence8
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int board[100],require[2000],max_board[100]={0},rem[100],sum[2010]={0};
int board_sum=0,num;
bool end=false;
int n,m;
bool cmp(const int& a,const int& b)
{
	return a>b;
}
void Init()
{
	board_sum=0;
	for(int i=1; i<=n; i++)
	{
		rem[i]=board[i];
		board_sum+=board[i];
	}
}
int cnt=0;
bool search(int pos,int last_p)
{
	//if(cnt>1000)
	//	return false;
	cnt++;
	if(pos<0)
		return true;
	//printf("   %d %d %d %d\n",pos,last_p,sum[num]-sum[pos-1],board_sum);
	//for(int i=1; i<=n; i++)
	//	printf("         %d %d\n",i,rem[i]);
	if(board_sum<sum[pos])
	{
		//printf("        %d %d %d\n",pos,last_p,sum[num]-sum[pos-1]);
		return false;
	}
	for(int i=last_p; i<=n; i++)
		if(rem[i]>=require[pos])
		{
			rem[i]-=require[pos];
			if(rem[i]<require[1])
				board_sum-=rem[i];
			board_sum-=require[pos];
			if(search(pos-1,require[pos]==require[pos-1]?i:1))
				return true;
			board_sum+=require[pos];
			if(rem[i]<require[1])
				board_sum+=rem[i];
			rem[i]+=require[pos];
		}
	return false;
}
int main()
{
	freopen("fence8.in","r",stdin);freopen("fence8.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&board[i]);
		board_sum+=board[i];
		rem[i]=board[i];
	}
	int sum_t=board_sum;
	sort(board+1,board+n+1,cmp);
	scanf("%d",&m);
	for(int i=1; i<=m; i++)
		scanf("%d",&require[i]);
	sort(require+1,require+m+1);
	while(require[m]>board[1])
		m--;
	for(int i=1; i<=m; i++)
		sum[i]=sum[i-1]+require[i];
	int l=0,r=m;
	num=(l+r)/2;
	while(l<=r)
	{ 
		Init();
		//printf("%d %d %d",l,r,num);
		if(search(num,1))
			l=num+1;
		else
			r=num-1;
		num=(l+r)/2;
    }
	printf("%d\n",num);
	return 0;
}