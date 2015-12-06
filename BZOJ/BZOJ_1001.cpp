#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cstring>
#define dbg if(0)
#define ROW 0
#define COL 1
#define CROSS 2
#define N 1010
#define M 1010
#define Rep(i,n) for(int i=0; i<n; i++)
#define PROB "bjrabbit"

using namespace std;

int val[3][N][M],n,m;

struct Edge{
	int type,r,c,d;
	Edge(int a,int b,int C,int D):type(a),r(b),c(C),d(D){}
	const bool operator<(const Edge& rhs)const{
		return d>rhs.d;
	}
};

struct Pos{
	int type,r,c;
	Pos(){}
	Pos(int A,int B,int C):type(A),r(B),c(C){} 
	Pos operator+(Pos t){
		return Pos(t.type,r+t.r,c+t.c);
	}
	void Init(int A,int B,int C){
		type=A;
		r=B;
		c=C;
	}
}dxy[6];

int dist[3][N][M],done[3][N][M]={0};
priority_queue<Edge> pq;
bool check(Pos p){
	if(p.r<=0||p.c<=0)return false;
	if(p.type==0){
		return p.r<=n&&p.c<m;
	}else if(p.type==1){
		return p.r<n&&p.c<=m;
	}else{
		return p.r<n&&p.c<m;
	}
}
inline void Relax(int d0,Pos p){
	if(!check(p))return;
	if(dist[p.type][p.r][p.c]>d0+val[p.type][p.r][p.c]){
		dist[p.type][p.r][p.c]=d0+val[p.type][p.r][p.c];
		pq.push(Edge(p.type,p.r,p.c,dist[p.type][p.r][p.c]));
dbg		printf(" %d %d %d %d\n",p.type,p.r,p.c,dist[p.type][p.r][p.c]);
	}
}
int DIJ(){
	memset(done,0,sizeof(done));
	memset(dist,0x3f,sizeof(dist));
	for(int i=1; i<m; i++){
		dist[0][n][i]=val[0][n][i];
		pq.push(Edge(ROW,n,i,dist[0][n][i]));
	}
	for(int i=1; i<n; i++){
		dist[1][i][1]=val[1][i][1];
		pq.push(Edge(COL,i,1,dist[1][i][1]));
	}
	while(!pq.empty()){
		Edge u=pq.top();
		pq.pop();
		if(done[u.type][u.r][u.c])
			continue;
dbg		printf("%d %d %d %d\n",u.type,u.r,u.c,dist[u.type][u.r][u.c]);
		done[u.type][u.r][u.c]=1;
		if(u.type==ROW){
			Pos pt;
			pt.Init(COL,u.r-1,u.c);
			Relax(u.d,pt);
			
			pt.Init(COL,u.r,u.c+1);
			Relax(u.d,pt);
			
			pt.Init(CROSS,u.r,u.c);
			Relax(u.d,pt);
			
			pt.Init(CROSS,u.r-1,u.c);
			Relax(u.d,pt);
		}else if(u.type==COL){
			Pos pt;
			pt.Init(ROW,u.r,u.c-1);
			Relax(u.d,pt);
			
			pt.Init(ROW,u.r+1,u.c);
			Relax(u.d,pt);
			
			pt.Init(CROSS,u.r,u.c);
			Relax(u.d,pt);
			
			pt.Init(CROSS,u.r,u.c-1);
			Relax(u.d,pt);
		}else{
			Pos pt;
			pt.Init(ROW,u.r,u.c);
			Relax(u.d,pt);
			
			pt.Init(ROW,u.r+1,u.c);
			Relax(u.d,pt);
			
			pt.Init(COL,u.r,u.c);
			Relax(u.d,pt);
			
			pt.Init(COL,u.r,u.c+1);
			Relax(u.d,pt);
		}
	}
	int ret=1<<30;
	for(int i=1; i<m; i++){
dbg		printf("%d\n",dist[0][1][i]);
		ret=min(ret,dist[0][1][i]);
	}
	for(int i=1; i<n; i++){
dbg		printf("%d\n",dist[1][i][m]);
		ret=min(ret,dist[1][i][m]);
	}
	return ret;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	//freopen(PROB".in","r",stdin);
	//freopen(PROB".out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1&&m==1){
		printf("0\n");
		return 0;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<m; j++)
			scanf("%d",&val[0][i][j]);
	for(int i=1; i<n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d",&val[1][i][j]);
	for(int i=1; i<n; i++)
		for(int j=1; j<m; j++)
			scanf("%d",&val[2][i][j]);
	printf("%d\n",DIJ());
	return 0;
}
