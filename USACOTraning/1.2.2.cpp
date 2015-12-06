/*
ID: mayukun3
PROG: milk2
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
struct LINE
{
	int left,right;
}line[5001],newline[5001];
bool cmp(const LINE& a,const LINE& b)
{
	return a.left<b.left;
}
bool chonghe(const LINE& a,const LINE& b)
{
	if(a.right>=b.left)
		return true;
	else
		return false;
}
int main()
{
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	int n,num=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d %d",&line[i].left,&line[i].right);
	sort(line+1,line+n+1,cmp);
	newline[++num].left=line[1].left;
	newline[num].right=line[1].right;
	for(int i=2; i<=n; i++)
	{
		if(chonghe(newline[num],line[i]))
		{
			newline[num].right=max(newline[num].right,line[i].right);
		}
		else
		{
			newline[++num].left=line[i].left;
			newline[num].right=line[i].right;
		}
	}
	int max_busy=newline[1].right-newline[1].left,max_free=0;
	for(int i=2; i<=num; i++)
	{
		max_busy=max(max_busy,newline[i].right-newline[i].left);
		max_free=max(max_free,newline[i].left-newline[i-1].right);
	}
	printf("%d %d\n",max_busy,max_free);
	return 0;
}
