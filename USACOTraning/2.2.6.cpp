/*
ID: mayukun3
PROG: lamps
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n,c,ans_num=0,final_pos[101];
struct ANS
{
	int p[101];
	bool operator<(const ANS& rhs) const
	{
		for(int i=1;i<=n;i++)
		{
			if(p[i]<rhs.p[i])
				return true;
			else if(p[i]>rhs.p[i])
				return false;
		}
	}
}ans[16];
bool cmp(const ANS& a,const ANS& b)
{
	for(int i=n; i>=1; i--)
	{
		if(a.p[i]<b.p[i])
			return true;
		if(a.p[i]>b.p[i])
			return false;
	}
}
bool equal(int* a,int* b)
{
	for(int i=1; i<=n; i++)
		if(a[i]!=b[i])
			return false;
	return true;
}
bool new_ans(int* a)
{
	for(int i=0; i<ans_num; i++)
		if(equal(ans[i].p,a))
			return false;
	return true;
}
void work(int action,int* lights)
{
	if(action==0)
		for(int i=1; i<=n; i++)
			lights[i]=-lights[i];
	else if(action==1)
		for(int i=1; i<=n; i+=2)
			lights[i]=-lights[i];
	else if(action==2)
		for(int i=2; i<=n; i+=2)
			lights[i]=-lights[i];
	else
		for(int i=1; i<=n; i+=3)
			lights[i]=-lights[i];
}
void count(int pos)
{
	int t[101];
	for(int i=1; i<=n; i++)
		t[i]=1;
	for(int i=0; i<4; i++)
		if(1&(pos>>i))
			work(i,t);
	for(int i=1; i<=n; i++)
		ans[ans_num].p[i]=t[i]==-1?0:1;
	ans_num++;
}
bool check(int pos)
{
	int t[101];
	for(int i=1; i<=n; i++)
		t[i]=1;
	int cnt=0;
	for(int i=0; i<4; i++)
		if(1&(pos>>i))
		{
			work(i,t);
			cnt++;
		}
	if((cnt>c)||((cnt%2)!=(c%2)))
		return false;
	for(int i=1; i<=n; i++)
		if(final_pos[i]==-t[i])
			return false;
	if(!new_ans(t))
		return false;
	return true;
}
int main()
{
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&c);
	memset(final_pos,0,sizeof(final_pos));
	char t;
	while(scanf("%d",&t) && t!=-1)
	{
		final_pos[t]=1;
	}
	while(scanf("%d",&t)&&t!=-1)
	{
		final_pos[t]=-1;
	}
	for(int i=0; i<16; i++)
		if(check(i))
			count(i);
	sort(ans,ans+ans_num);
	if(ans_num==0)
		printf("IMPOSSIBLE\n");
	for(int i=0; i<ans_num; i++)
	{
		for(int j=1; j<=n; j++)
			printf("%d",ans[i].p[j]);
		printf("\n");
	}
}