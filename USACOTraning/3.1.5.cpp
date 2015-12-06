/*
ID: mayukun3
PROG: rect1
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct REC
{
	int x1,y2,y1,x2,color;
}rect[1001];
int s[2501]={0},n;
void cover(int x1,int y1,int x2,int y2,int color,int height)
{
	//printf("%d %d %d %d %d %d\n",x1,y1,x2,y2,color,height);
	if(height>n)
	{
		s[color]+=(x2-x1)*(y2-y1);
		return;
	}
	REC& floor=rect[height];
	if(x2<=floor.x1||x1>=floor.x2||y2<=floor.y1||y1>=floor.y2)
		cover(x1,y1,x2,y2,color,height+1);
	else
	{
		if(x1<floor.x1)
			cover(x1,max(y1,floor.y1),floor.x1,y2,color,height+1);
		if(y1<floor.y1)
			cover(x1,y1,min(x2,floor.x2),floor.y1,color,height+1);
		if(x2>floor.x2)
			cover(floor.x2,y1,x2,min(floor.y2,y2),color,height+1);
		if(y2>floor.y2)
			cover(max(x1,floor.x1),floor.y2,x2,y2,color,height+1);
	}
}
int main()
{
	freopen("rect1.in","r",stdin);
	freopen("rect1.out","w",stdout);
	scanf("%d%d%d",&rect[0].x2,&rect[0].y2,&n);
	rect[0].x1=0,rect[0].y1=0,rect[0].color=1;
	for(int i=1; i<=n; i++)
	{
		scanf("%d%d%d%d%d",&rect[i].x1,&rect[i].y1,&rect[i].x2,&rect[i].y2,&rect[i].color);
	}
	for(int i=n; i>=0; i--)
	{
		cover(rect[i].x1,rect[i].y1,rect[i].x2,rect[i].y2,rect[i].color,i+1);
	}
	for(int i=1; i<=2500; i++)
		if(s[i])
			printf("%d %d\n",i,s[i]);
	return 0;
}
