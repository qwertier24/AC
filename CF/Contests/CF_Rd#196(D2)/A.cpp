#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int size[100];
int main()
{
	int n,m,ans=1<<30;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++)
		scanf("%d",&size[i]);
	sort(size+1,size+m+1);
	for(int i=1; i<=m-n+1; i++)
		ans=min(ans,size[i+n-1]-size[i]);
	printf("%d",ans);
	return 0;
}
