#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	if(x>0&&y>0)
		printf("0 %d %d 0",x+y,x+y);
	else if(x<0&&y>0)
		printf("%d 0 0 %d",x-y,y-x);
	else if(x>0&&y<0)
		printf("0 %d %d 0",y-x,x-y);
	else
		printf("%d 0 0 %d",x+y,x+y);
	return 0;
}
