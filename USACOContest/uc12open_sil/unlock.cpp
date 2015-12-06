#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <set>
#define PROB "unlock"
#define zero 20
#define dbg if(0)
#define max_width 41
#define clr(a) memset(a,-1,sizeof(a))
using namespace std;
int w[3],h[3];
struct R{
	int n,x[100],y[100];
}block[3];
struct Status{
	int t[3],l[3],d;
	Status(){}
	bool operator<(const Status& rhs)const{
		int r=memcmp(t,rhs.t,sizeof(t));
		if(!r)r=memcmp(l,rhs.l,sizeof(l));
		return r<0;
	}
	void Init(){
		for(int i=2; i>=0; i--){
			t[i]-=t[0];
			l[i]-=t[0];
		}
	}
};
 
bool check_sep(Status p){
	for(int i=0; i<3; i++)
		for(int j=0; j<i; j++){
			int x=
				return false;
		}
	return true; 
}
 
int addx[4]={0,0,-1,1},addy[4]={-1,1,0,0};
set<Status> vis;
 
inline bool check(int p){
	return p>=0&&p<max_width;
}
inline bool check_modify(int (*g)[max_width],Status p,int i){
	if(!check(p.l[i]+zero)||!check(p.l[i]+w[i]+zero)||!check(p.t[i]+zero)||!check(p.t[i]+h[i]+zero))return false;
	for(int j=0; j<3; j++)
		if(j!=i)
			for(int k=0; k<block[i].n; k++)
				for(int l=0; l<block[j].n; l++)
					if(block[i].x[k]+p.t[i]==block[j].x[l]+p.t[j]&&block[i].y[k]+p.l[i]==block[j].y[l]+p.l[j])
						return false;
	return true;
}
void getg(int (*g)[max_width],Status p){
	for(int i=0; i<3; i++)
		for(int j=0; j<block[i].n; j++)
			g[p.t[i]+block[i].x[j]+zero][p.l[i]+block[i].y[j]+zero]=i;
}
void print(int (*g)[max_width]){
	for(int i=10; i<35; i++){
		for(int j=10; j<35; j++)
			if(g[i][j]==-1)
				printf("   ");
			else
				printf("%3d",g[i][j]);
		printf("\n");
	}
}
int bfs(Status p0){
	queue<Status> q;
	p0.d=0;
	q.push(p0);
	vis.insert(p0);
	int g[max_width][max_width];
	while(!q.empty()){
		Status p=q.front();
		q.pop();
dbg		clr(g);
dbg		getg(g,p);
dbg		printf("d:%d\n",p.d);
dbg		print(g);
		if(check_sep(p)){
			return p.d;
		}
dbg		if(p.l[1]==2&&p.t[1]==4)printf("!!");
		//print(g);
		for(int i=0; i<3; i++)
			for(int j=0; j<4; j++){
				Status t=p;
				t.t[i]+=addx[j];
				t.l[i]+=addy[j];
				t.Init();
				if(check_modify(g,t,i)){
					if(vis.insert(t).second){
						t.d=p.d+1;
						q.push(t);
					}
				}
			}
	}
	return -1;
}
int main(){
	freopen(PROB".in","r",stdin);
	//freopen(PROB".out","w",stdout);
	int x,y;
	scanf("%d%d%d",&block[0].n,&block[1].n,&block[2].n);
	Status p0;
	for(int i=0; i<3; i++){
		p0.l[i]=1<<30,p0.t[i]=1<<30;
		int bx=0,ry=0;
		for(int j=0; j<block[i].n; j++){
			scanf("%d%d",&block[i].x[j],&block[i].y[j]);
			p0.l[i]=min(p0.l[i],block[i].y[j]);
			ry=max(ry,block[i].y[j]);
			p0.t[i]=min(p0.t[i],block[i].x[j]);
			bx=max(bx,block[i].x[j]);
		}
		w[i]=ry-p0.l[i];
		h[i]=bx-p0.t[i];
		for(int j=0; j<block[i].n; j++)
			block[i].x[j]-=p0.t[i],block[i].y[j]-=p0.l[i];
	}
	p0.Init();
	int g[max_width][max_width];
	clr(g);
	getg(g,p0);
	print(g);
	//printf("%d %d\n",p0.l[1],p0.t[1]);
	printf("%d",bfs(p0));
	return 0;
}
