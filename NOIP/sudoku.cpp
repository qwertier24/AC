#include <stdio.h>
#include <algorithm>
#include <string.h>
#define Rep(i) for(int i=0; i<9; i++)
#define PROB "sudoku"
using namespace std;
int mr[10][10]={0},mc[10][10]={0},mb[10][10]={0},max_cnt=-1,score[10][10],g[10][10]={0};
struct Can{
	int x,y,b,cnt;
	bool operator<(const Can& rhs)const{
		return cnt<rhs.cnt;
	}
}can[82]={0};
void dfs(int p){
	//printf("%d\n",p);
	if(p>80){
		int cnt=0;
		for(int i=0; i<9; i++)
			for(int j=0; j<9; j++)
				cnt+=score[i][j]*g[i][j];
		max_cnt=max(max_cnt,cnt);
		return;
	}
	if(can[p].cnt){
		int x=can[p].x,y=can[p].y,bn=can[p].b;
		for(int i=1; i<10; i++)
			if(!mr[x][i]&&!mc[y][i]&&!mb[bn][i]){
				mb[bn][i]=1;
				mr[x][i]=1;
				mc[y][i]=1;
				g[x][y]=i;
				dfs(p+1);
				mb[bn][i]=0;
				mr[x][i]=0;
				mc[y][i]=0;
				g[x][y]=0;
			}
	}else
		dfs(p+1);
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	Rep(i)
		Rep(j){
			scanf("%d",&g[i][j]);
			if(g[i][j]){
				if(mr[i][g[i][j]]||mc[j][g[i][j]]||mb[i/3*3+j/3][g[i][j]]){
					printf("-1\n");
					return 0;
				}
				mr[i][g[i][j]]=1;
				mc[j][g[i][j]]=1;
				mb[i/3*3+j/3][g[i][j]]=1;
				//printf("%d %d %d %d\n",i,j,i/3*3+j/3,g[i][j]);
			}
		}
	for(int i=0; i<5; i++){
		for(int j=4-i; j<=4+i; j++)
			score[4-i][j]=score[4+i][j]=10-i;
		for(int j=4-i; j<=4+i; j++)
			score[j][4+i]=score[j][4-i]=10-i;
	}
	Rep(i)
		Rep(j){
			int bn=i/3*3+j/3;
			can[i*9+j].x=i;
			can[i*9+j].y=j;
			can[i*9+j].b=bn;
			if(!g[i][j])
				for(int k=1; k<10; k++){
					if(!mr[i][k]&&!mc[j][k]&&!mb[bn][k]){
						can[i*9+j].cnt++;
					}
				}
		}
	sort(can,can+81);
	//for(int i=0; i<81; i++)
	//	printf("%d %d %d\n",can[i].x,can[i].y,can[i].cnt);
	/*
	Rep(i){
		Rep(j){
			printf("%d ",score[i][j]);
		}
		printf("\n");
	}
	*/
	dfs(0);
	printf("%d\n",max_cnt);
	return 0;
}

