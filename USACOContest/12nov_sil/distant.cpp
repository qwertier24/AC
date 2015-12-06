#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#define PROB "distant"
#define INF (1<<30)
#define Rep(i,n) for(int i=0; i<n; i++)
using namespace std;
struct P{
	int x,y;
	P(int a,int b):x(a),y(b){}
};
int n,A,B,inq[40][40],dist[40][40],addx[4]={0,0,-1,1},addy[4]={-1,1,0,0};
char g[40][40];
inline bool check(int x,int y){
	return x>=0&&y>=0&&x<n&&y<n;
}
void SPFA(int x0,int y0){
	int x,y,xt,yt,d;
	Rep(i,n)
		Rep(j,n)
			dist[i][j]=INF;
	memset(inq,0,sizeof(inq));
	dist[x0][y0]=0;
	inq[x0][y0]=1;
	queue<P> q;
	q.push(P(x0,y0));
	while(!q.empty()){
		P p=q.front();
		q.pop();
		x=p.x,y=p.y;
		inq[x][y]=0;
		Rep(i,4){
			xt=x+addx[i],yt=y+addy[i];
			if(check(xt,yt)){
				d=g[x][y]==g[xt][yt]?A:B;
				if(dist[xt][yt]>dist[x][y]+d){
					dist[xt][yt]=dist[x][y]+d;
					if(!inq[xt][yt]){
						inq[xt][yt]=1;
						q.push(P(xt,yt));
					}
				}
			}
		}
	}
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d%d",&n,&A,&B);
	for(int i=0; i<n; i++)
		scanf("%s",g[i]);
	int ans=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			SPFA(i,j);
			for(int k=0; k<n; k++)
				for(int l=0; l<n; l++)
					if(k!=i||l!=j)
						ans=max(ans,dist[k][l]);
		}
	printf("%d",ans);		
	return 0;
}

