#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "umbrella"
using namespace std;
int n,m,d[5010],cost[100010],x[5010];

int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",&x[i]);
	sort(x+1,x+n+1);
	for(int i=1; i<=m; i++)
		scanf("%d",&cost[i]);
	cost[m+1]=1<<30;
	for(int i=m; i>=1; i--)
		if(cost[i]>cost[i+1])
			cost[i]=cost[i+1];
	for(int i=1; i<=n; i++){
		if(x[i]==x[i-1]){d[i]=d[i-1];continue;}
		d[i]=1<<30;
		for(int j=0; j<i; j++)
			d[i]=min(d[i],cost[x[i]-x[j+1]+1]+d[j]);
	}
	printf("%d",d[n]);
	return 0;
}

