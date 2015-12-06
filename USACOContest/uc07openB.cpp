#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <iostream>
#define For(i,b,e) for(int i=b; i<=e; i++)
#define check(x,y) x>=0&&y>=0&&x<n&&y<m
using namespace std;
int n,m,g[20][20],gt[20][20],ans[20][20],min_step=-1,addx[4]={0,0,-1,1},addy[4]={1,-1,0,0},steps,anst[20][20];
void Modify(int x,int y){
	gt[x][y]=1^gt[x][y];
	anst[x][y]=1;
	steps++;
	For(i,0,3){
		int xt=x+addx[i],yt=y+addy[i];
		if(check(xt,yt))
			gt[xt][yt]=1^gt[xt][yt];
	}
}
bool check_g(){
	For(i,0,n-1)
		For(j,0,m-1)
			if(gt[i][j])
				return false;
	return true;
}
void solve(int S){
	memset(anst,0,sizeof(anst));
	steps=0;
	memcpy(gt,g,sizeof(g));
	For(i,0,m-1){
		if((S>>i)&1)
			Modify(0,i);
	}
	For(i,1,n-1){
		For(j,0,m-1){
			if(gt[i-1][j]){
				Modify(i,j);
				//printf("%d %d %d\n",i,j,gt[i-1][j]);
			}
		}
	}
	/*
	For(i,0,n-1){
		For(j,0,m-1)
			printf("%d ",gt[i][j]);
		printf("\n");
	}
	*/
	if((min_step==-1||min_step>steps)&&check_g()){
		memcpy(ans,anst,sizeof(anst));
		min_step=steps;
	}
}
int main(){
	freopen("fliptile.in","r",stdin);
	scanf("%d%d",&n,&m);
	For(i,0,n-1)
		For(j,0,m-1)
			scanf("%d",&g[i][j]);
	For(i,0,(1<<m)-1)
		solve(i);
	if(min_step==-1)
		printf("IMPOSSIBLE\n");
	else
		For(i,0,n-1){
			For(j,0,m-2)
				printf("%d ",ans[i][j]);
			printf("%d\n",ans[i][m-1]);
		}
	return 0;
}

