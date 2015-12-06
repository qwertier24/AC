#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 50
#define M 500
#define CLR(t) memset(t,0,sizeof(t))
#define INF (1<<29)

using namespace std;

int n,m;

int vx[N],vy[M],w[N][M],lx[N],ly[M],mark[M],slack[M];
int match(int u){
	if(vx[u])return 0;
	vx[u]=1;
	Rep(v,m){
		if(w[u][v]==lx[u]+ly[v]){
			vy[v]=1;
			if(mark[v]==-1 || match(mark[v])){
				mark[v]=u;
				return 1;
			}
		}else
			slack[v]=min(slack[v],lx[u]+ly[v]-w[u][v]);
	}
	return 0;
}
void update(){
	int d=INF;
	Rep(i,m)
		if(!vy[i])
			d=min(d,slack[i]);
	Rep(i,n)if(vx[i])lx[i]-=d;
	Rep(i,m){
		if(vy[i])
			ly[i]+=d;
		else
			slack[i]-=d;
	}
}
void KM(){
	Rep(i,n){
		lx[i]=-INF;
		Rep(j,m)
			lx[i]=max(lx[i],w[i][j]);
	}
	memset(mark,-1,sizeof(mark));
	CLR(ly);
	Rep(i,n){
		memset(slack,0x3f,sizeof(slack));
		while(true){
			CLR(vx);CLR(vy);
			if(match(i))break;
			else update();
		}
	}
}
int t[N][M],size[M];
int incpu[N],ansl[N],ansr[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int kase=1;
	while(scanf("%d%d",&m,&n)&&(m||n)){
		Rep(i,n)Rep(j,m)t[i][j]=INF;
		Rep(i,m)
			scanf("%d",&size[i]);
		Rep(i,n){
			int kt,st,tt;
			scanf("%d",&kt);
			Rep(j,kt){
				scanf("%d%d",&st,&tt);
				Rep(k,m)
					if(size[k]>=st)
						t[i][k]=min(t[i][k],tt);
			}
		}
		Rep(i,n)
			Rep(j,m){
				if(t[i][j]!=INF){
					Rep(k,n)
						w[i][j*n+k]=-t[i][j]*(k+1);
				}else
					Rep(k,n)w[i][j*n+k]=-INF;
			}
		m*=n;
		KM();
		vector<int> cpu[M];
		for(int i=m-1; i>=0; i--){
			if(mark[i]!=-1){
				cpu[i/n].push_back(mark[i]);
			}
		}
		m/=n;
		int total=0;
		Rep(i,m){
			int sumt=0;
			Rep(j,cpu[i].size()){
				int k=cpu[i][j];
				incpu[k]=i;
				ansl[k]=sumt;
				sumt+=t[k][i];
				ansr[k]=sumt;
				total+=sumt;
			}
		}
		printf("Case %d\nAverage turnaround time = %.2f\n",kase++,total/(double)n);
		Rep(i,n){
			printf("Program %d runs in region %d from %d to %d\n",
			i+1,incpu[i]+1,ansl[i],ansr[i]);
		}
		puts("");
	}
#ifndef ONLINE_JUDGE
	while(true);
#endif
	return 0;
}
