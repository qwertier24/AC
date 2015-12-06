#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int col[2000],row[2000];
int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		row[i]=1,col[i]=1;
	for(int i=1; i<=m; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		row[x]=col[y]=0;
	}
	if(n%2&&(row[n/2+1]||col[n/2+1]))
		ans++;
	//printf("%d",ans);
	//printf("%d %d %d\n",row[2],col[4],row[4]);
	for(int i=2; i<=n/2; i++)
	{
		//printf("%d %d %d %d %d\n",n-i+1,row[i],col[i],row[n-i+1],col[n-i+1]);
		ans+=row[i]+col[i]+row[n-i+1]+col[n-i+1];
	}
	printf("%d",ans);
	return 0;
}
