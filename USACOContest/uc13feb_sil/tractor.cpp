#include <stdio.h>
#include <algorithm>
#include <cstring>
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
int n,g[510][510],min_size,vis[510][510],addx[4]={0,0,-1,1},addy[4]={-1,1,0,0},diff;
bool check(int x,int y){
	return x>=1&&y>=1&&x<=n&&y<=n&&!vis[x][y];
}
int dfs(int x,int y){
	int ret=0;
	vis[x][y]=1;
	for(int i=0; i<4; i++){
		int xt=x+addx[i],yt=y+addy[i];
		if(check(xt,yt)&&abs(g[xt][yt]-g[x][y])<=diff)
			ret+=dfs(xt,yt);
	}
	return ret+1;
}
bool check(){
	memset(vis,0,sizeof(vis));
	For(i,1,n)
		For(j,1,n)
			if(!vis[i][j])
				if(dfs(i,j)>=min_size)
					return true;
	return false;
}
int main(){
	freopen("tractor.in","r",stdin);
	freopen("tractor.out","w",stdout);
	scanf("%d",&n);
	min_size=(n*n-1)/2+1;
	For(i,1,n)
		For(j,1,n)
			scanf("%d",&g[i][j]);
	int l=0,r=1000000;
	while(l<r){
		int m=(l+r)>>1;
		diff=m;
		if(check())r=m;
		else l=m+1;
	}
	printf("%d",l);
	return 0;
}
