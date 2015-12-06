/*
ID: mayukun3
PROG: checker
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#define chuli(x) ((x<0)||(x>n))?0:x
int n,pos[15],ans=3,cnt=0;
int places[15][15];
void print(int m)
{
	printf("%d",pos[1]);
	for(int i=2; i<=m; i++)
		printf(" %d",pos[i]);
	printf("\n");
}
void get_places(int m)
{
	memset(places[m],-1,sizeof(places[m]));
	for(int i=1; i<m; i++)
	{
		//printf("%d %d %d\n",chuli(pos[i]+m-i),chuli(pos[i]-(m-i)),pos[i]);
		places[m][chuli(m-i+pos[i])]=0;
		places[m][chuli(pos[i]-(m-i))]=0;
		places[m][pos[i]]=0;
	}
	return;
}
void search(int deep)
{
	//print(deep-1);
	if(deep==n+1)
	{
		cnt++;
		if(cnt<=3)
			print(n);
		return;
	}
	get_places(deep);
	for(int i=1; i<=n; i++)
		if(places[deep][i])
		{
			pos[deep]=i;
			search(deep+1);
		}
	return;
}
int main()
{
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		pos[1]=i;
		search(2);
	}
	/*
	pos[1]=2;
	pos[2]=4;
	pos[3]=6;
	search(4);
	*/
	printf("%d\n",cnt);
	return 0;
}
