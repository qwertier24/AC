#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct ANT
{
	int pos,ord;
	char dir;
	bool operator<(const ANT& rhs) const
	{
		return pos<rhs.pos;
	}
}ants[10001];
int locate[10001];
int main()
{
	int T,L,t,n;
	scanf("%d",&T);
	for(int kase=1; kase<=T; ++kase)
	{
		scanf("%d%d%d",&L,&t,&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d %c",&ants[i].pos,&ants[i].dir);
			ants[i].ord=i;
		}
		sort(ants+1,ants+n+1);
		for(int i=1; i<=n; i++)
			locate[ants[i].ord]=i;
		for(int i=1; i<=n; i++)
			ants[i].pos+=ants[i].dir=='L'?-t:t;
		sort(ants+1,ants+n+1);
		printf("Case #%d:\n",kase);
		for(int i=1; i<=n; i++)
		{
			int p=locate[i];
			if(ants[p].pos<0||ants[p].pos>L)
				printf("Fell off\n");
			else
			{
				printf("%d ",ants[p].pos);
				if((p>1&&ants[p].pos==ants[p-1].pos)||(p<n&&ants[p].pos==ants[p+1].pos))
					printf("Turning\n");
				else
					printf("%c\n",ants[p].dir);
			}
		}
		printf("\n");
	}
	return 0;
}
