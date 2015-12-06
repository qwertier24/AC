#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <cstring>
#define For(i,b,e) for(int i=b; i<=e; i++)
#define PROB "tortoise"
using namespace std;
int d[50][50][50][50],cnt[5]={0},n,m,a[360];
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d",&n,&m);
	For(i,1,n)scanf("%d",&a[i]);
	for(int i=1; i<=m; i++){
		int b;
		scanf("%d",&b);
		cnt[b]++;
	}
	for(int i=0; i<=cnt[1]; i++)
		for(int j=0; j<=cnt[2]; j++)
			for(int k=0; k<=cnt[3]; k++)
				for(int l=0; l<=cnt[4]; l++){
					if(i>0)
						d[i][j][k][l]=max(d[i-1][j][k][l],d[i][j][k][l]);
					if(j>0)
						d[i][j][k][l]=max(d[i][j][k][l],d[i][j-1][k][l]);
					if(k>0)
						d[i][j][k][l]=max(d[i][j][k][l],d[i][j][k-1][l]);
					if(l>0)
						d[i][j][k][l]=max(d[i][j][k][l],d[i][j][k][l-1]);
					d[i][j][k][l]+=a[i+2*j+3*k+4*l+1];
					//printf("%d %d %d %d %d\n",i,j,k,l,d[i][j][k][l]);
				}
	printf("%d",d[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);
	return 0;
}

