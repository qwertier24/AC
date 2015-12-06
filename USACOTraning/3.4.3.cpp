/*
ID: mayukun3
PROG: heritage
LANG: C++
*/
#include <stdio.h>
#include <cstring>
char pre[1000],mid[1000];
void solve(int l1,int r1,int l2,int r2)
{
	if(l1>r1||l2>r2)
		return;
	//printf("%d %d %d %d\n",l1,r1,l2,r2);
	if(l1==r1)
	{
		printf("%c",pre[l1]);
		return;
	}
	int p=strchr(mid,pre[l1])-mid;
	solve(l1+1,l1+p-l2,l2,p-1);
	solve(l1+1+p-l2,r1,p+1,r2);
	printf("%c",pre[l1]);
}
int main()
{
	freopen("heritage.in","r",stdin);freopen("heritage.out","w",stdout);
	scanf("%s %s",mid,pre);
	solve(0,strlen(pre)-1,0,strlen(mid)-1);
	printf("\n");
	return 0;
}
