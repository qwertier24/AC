#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "tilechng"
using namespace std;
int sum=0,l[20],n,m,d[20][10010];
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&l[i]);
		sum+=l[i];
	}
	memset(d,0x3f,sizeof(d));
	d[0][0]=0;
	for(int i=1; i<=n; i++)
		for(int j=0; j<=m; j++)
			for(int k=0; k*k<=j; k++)
				d[i][j]=min(d[i][j],d[i-1][j-k*k]+(k-l[i])*(k-l[i]));
	if(d[n][m]>=d[0][1])
		printf("-1");
	else
		printf("%d",d[n][m]);
	return 0;
}

