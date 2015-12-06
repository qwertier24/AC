/*
ID: mayukun3
PROG: msquare
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int ans_step=1<<30,end_pos,ans_pos,ans_actions[90000];
map<int,int> mp,last_pos;
void Modify(int act,int& t)
{
	int pos[10];
	for(int i=1; i<=8; i++)
		pos[i]=(t>>((i-1)*3))&7;
	if(act==1)
		for(int i=1; i<=4; i++)
			swap(pos[i],pos[i+4]);
	else if(act==2)
	{
		int t1=pos[4],t2=pos[8];
		for(int i=4; i>=2; i--)
			pos[i]=pos[i-1],pos[i+4]=pos[i+3];
		pos[1]=t1,pos[5]=t2;
	}
	else if(act==3)
	{
		int t=pos[2];
		pos[2]=pos[6];
		pos[6]=pos[7];
		pos[7]=pos[3];
		pos[3]=t;
	}
	t=0;
	for(int i=1; i<=8; i++)
		t|=pos[i]<<((i-1)*3);
}
inline bool check(int pos)
{
	return pos==end_pos;
}
void bfs()
{
	queue<int> q;
	q.push(045673210);
	mp[045673210]=0;
	while(!q.empty())
	{
		int pos=q.front();
		q.pop();
		if(check(pos))
		{
			ans_step=mp[pos];
			return;
		}
		for(int i=1; i<=3; i++)
		{
			int t=pos;
			Modify(i,t);
			if(!mp.count(t))
			{
				last_pos[t]=pos;
				q.push(t);
				mp[t]=mp[pos]+1;
			}
		}
	}
}
int main()
{
	freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);
	int t[10],pos;
	for(int i=1; i<=4; i++)
	{
		scanf("%d",&t[i]);
		end_pos|=(t[i]-1)<<((i-1)*3);
	}
	for(int i=8; i>=5; i--)
	{
		scanf("%d",&t[i]);
		end_pos|=(t[i]-1)<<((i-1)*3);
	}/*
	*/
	bfs();
	printf("%d\n",ans_step);
	for(int i=ans_step; i>=1; i--)
	{
		for(int j=1; j<=3; j++)
		{
			int t=last_pos[end_pos];
			Modify(j,t);
			if(t==end_pos)
			{
				ans_actions[i]=j;
				end_pos=last_pos[end_pos];
				//printf("%d %d\n",end_pos,last_pos[end_pos]);
				break;
			}
		}
	}
	for(int i=1; i<=ans_step; i++)
	{
		if(i%60)
			printf("%c",'A'-1+ans_actions[i]);
		else
			printf("%c\n",'A'-1+ans_actions[i]);
	}
	if(ans_step%60||ans_step==0)
		printf("\n");
	return 0;
}
