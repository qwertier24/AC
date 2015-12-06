#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int n,done[10000];
struct ROOK
{
	int x1,y1,x2,y2,x,y,ord;
}rook[10000];
bool cmp1(const ROOK& a,const ROOK& b)
{
	if(a.x2==b.x2)
		return a.x1<b.x1;
	return a.x2<b.x2;
}
bool cmp2(const ROOK& a,const ROOK& b)
{
	if(a.y2==b.y2)
		return a.y1<b.y1;
	return a.y2<b.y2;
}
bool cmp3(const ROOK& a,const ROOK& b)
{
	return a.ord<b.ord;
}
void print()
{
	for(int i=1; i<=n; i++)
		printf("%d %d\n",rook[i].x,rook[i].y);
}
bool check()
{
	for(int i=1; i<=n; i++)
		if(!done[i])
			return false;
	return true;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d%d%d",&rook[i].x1,&rook[i].y1,&rook[i].x2,&rook[i].y2);
			rook[i].ord=i;
		}
		sort(rook+1,rook+n+1,cmp1);
		memset(done,0,sizeof(done));
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(!done[j]&&rook[j].x1<=i&&rook[j].x2>=i)
				{
					done[j]=1;
					rook[j].x=i;
					break;
				}
		if(!check())
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		memset(done,0,sizeof(done));
		sort(rook+1,rook+n+1,cmp2);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(!done[j]&&rook[j].y1<=i&&rook[j].y2>=i)
				{
					done[j]=1;
					rook[j].y=i;
					break;
				}
		if(!check())
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		sort(rook+1,rook+n+1,cmp3);
		print();
	}
	return 0;
}
