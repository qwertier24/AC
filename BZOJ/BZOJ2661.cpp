#include<stdio.h>
#include<string.h>
#include<math.h>

namespace nf{
#define N 2010
#define M 2200000
	int le[N],pe[M],ev[M],data[M],ecnt;
	int cost[M];
	void addEdge(int u,int v,int cap,int fee){
		pe[ecnt]=le[u];
		le[u]=ecnt;
		ev[ecnt]=v;
		data[ecnt]=cap;
		cost[ecnt]=fee;
		ecnt++;
		
		pe[ecnt]=le[v];
		le[v]=ecnt;
		ev[ecnt]=u;
		data[ecnt]=0;
		cost[ecnt]=-fee;
		ecnt++;
	}
	
	int S,T;
	void init(int s,int t){
		S=s,T=t;
		memset(le,-1,sizeof(le));
	}
	
	int dist[N];
	int q[N+10],inq[N],fr,rr,pre[N];
	int f,c;
	bool spfa(){
		for(int i=0; i<=T; i++)
			dist[i]=-(1<<30);
		memset(inq,0,sizeof(inq));
		fr=rr=0;
		q[rr++]=S;
		dist[S]=0;
		inq[S]=1;
		while(fr!=rr){
			int u=q[fr++];
			inq[u]=0;
			if(fr==N)fr=0;
			for(int i=le[u]; i!=-1; i=pe[i])if(data[i]){
				int &v=ev[i];
				if(dist[v]<cost[i]+dist[u]){
					dist[v]=dist[u]+cost[i];
					pre[v]=i;
					if(!inq[v]){
						inq[v]=1;
						q[rr++]=v;
						if(rr==N)rr=0;
					}
				}
			}
		}
		if(dist[T]<=-(1<<30))return false;
		c+=dist[T];
		f++;
		int u=T;
		while(u!=S){
			data[pre[u]]--;
			data[pre[u]^1]++;
			u=ev[pre[u]^1];
		}
		return true;
	}
	void mcmf(){
		f=c=0;
		while(spfa()); 
	}
}

int gcd(int a,int b){
	int tmp;
	while(a){
		tmp=a;
		a=b%a;
		b=tmp;
	}
	return b;
}
bool check(int a){
	int c=sqrt(a);
	return c*c==a;
}
int a,b;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&a,&b);
	nf::init(0,(b-a+1)*2+1);
	for(int i=a; i<=b; i++){
		nf::addEdge(nf::S,i-a+1,1,0);
		nf::addEdge(i-a+1+(b-a+1),nf::T,1,0);
		for(int j=i+1; j<=b; j++)
			if(check(j*j-i*i)&&gcd(i,j)==1){
				nf::addEdge(i-a+1,j-a+1+(b-a+1),1,j+i);
				nf::addEdge(j-a+1,i-a+1+(b-a+1),1,j+i);
			}
	}
	nf::mcmf();
	printf("%d %d\n",nf::f>>1,nf::c>>1);
	return 0;
}
