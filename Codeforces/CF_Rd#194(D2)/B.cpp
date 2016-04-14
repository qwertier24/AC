#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
struct P
{
	int x,y;
	bool operator<(const P& rhs)const
	{
		return x<rhs.x||(x==rhs.x&&y<rhs.y);
	}
	bool operator!=(const P& rhs)const
	{
		return x!=rhs.x||y!=rhs.y;
	}
}p[10];
int main()
{
	for(int i=1; i<=8; i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+9);
	if(p[1].x==p[3].x&&p[6].x==p[8].x&&p[4].x==p[5].x
		&&p[1]!=p[4]&&p[4]!=p[6]
		&&p[1].y==p[4].y&&p[4].y==p[6].y&&p[3].y==p[5].y&&p[5].y==p[8].y&&p[2].y==p[7].y
		&&p[1]!=p[2]&&p[2]!=p[3]&&p[6]!=p[7]&&p[7]!=p[8]&&p[4]!=p[5]&&p[1]!=p[4]&&p[4]!=p[6])
		printf("respectable\n");
	else
		printf("ugly\n");
	return 0;
}
