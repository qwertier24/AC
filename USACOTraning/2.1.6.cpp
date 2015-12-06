/*
ID: mayukun3
PROG: holstein
LANG: C++
*/
#include <stdio.h>
struct FEED
{
	int provide[30];
}feeds[20];
int v,g,need[30],min_types,selections=0;
void cpy(int* a,int* b)
{
	for(int i=0; i<v; i++)
		a[i]=b[i];
}
bool check(int pos)
{
	int t[30];
	cpy(t,need);
	for(int i=0; i<g; i++)
		if(pos&(1<<i))
			for(int j=0; j<v; j++)
				t[j]-=feeds[i].provide[j];
	for(int i=0; i<v; i++)
		if(t[i]>0)
			return false;
	return true;
}
void count(int pos,int deep)
{
	selections=pos;
	min_types=deep;
}
void search(int pos,int action,int deep)
{
	if(deep>=min_types)
		return;
	if(check(pos))
		count(pos,deep);
	for(int i=action+1; i<g; i++)
		search(pos|(1<<i),i,deep+1);
}
int main()
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	scanf("%d",&v);
	for(int i=0; i<v; i++)
		scanf("%d",&need[i]);
	scanf("%d",&g);
	for(int i=0; i<g; i++)
		for(int j=0; j<v; j++)
			scanf("%d",&feeds[i].provide[j]);
	selections=(1<<g)-1;
	min_types=g;
	for(int i=0; i<g; i++)
		search(1<<i,i,1);
	printf("%d",min_types);
	for(int i=0; i<g; i++)
		if(selections&(1<<i))
			printf(" %d",i+1);
	printf("\n");
}