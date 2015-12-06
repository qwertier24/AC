#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m,d[110][60][60]={0},g[60][60]={0};
int main(){
	freopen("message.in","r",stdin);
	freopen("message.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d",&g[i][j]);
	d[3][1][2]=g[1][2]+g[2][1];
	for(int i=4; i<n+m; i++)
		for(int j=1; j<i; j++)
			for(int k=j+1; k<i; k++){
				int x1=j,y1=i-j,x2=k,y2=i-k;
				d[i][j][k]=max(d[i][j][k],d[i-1][x1-1][x2-1]);
				d[i][j][k]=max(d[i][j][k],d[i-1][x1][x2]);
				if(x1-1!=x2||y1!=y2-1)
					d[i][j][k]=max(d[i][j][k],d[i-1][x1-1][x2]);
				if(x1!=x2-1||y1-1!=y2)
					d[i][j][k]=max(d[i][j][k],d[i-1][x1][x2-1]);
				//if(i==4&&j==2&&k==3)
				//	printf(" %d %d %d %d %d\n",d[i][j][k],x1==j,y1,x2,y2);
				d[i][j][k]+=g[x1][y1]+g[x2][y2];
				//printf("%d %d %d %d\n",i,j,k,d[i][j][k]);
			}
	printf("%d",d[n+m-1][n-1][n]);
	return 0;
}
