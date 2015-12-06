#include<stdio.h>
#include<algorithm>
#include<string.h>
#define N 160
#define For(i,n) for(int i=1; i<=n; i++)
#define CLR(t) memset(t,0,sizeof(t))
#define INF (1<<20)
#define X first
#define Y second
using namespace std;

int Lx[N],Ly[N],T[N],S[N],n,left[N],w[N][N]={0};
int g[N][N];

bool match(int i){
	S[i]=1;
	For(j,n)if(Lx[i]+Ly[j]==w[i][j]&&!T[j]){
		T[j]=1;
		if(!left[j]||match(left[j])){
			left[j]=i;
			return true;
		}
	}
	return false;
}

void update(){
	int a=1<<20;
	For(i,n)if(S[i])
		For(j,n)if(!T[j])
			a=min(a,Lx[i]+Ly[j]-w[i][j]);
	For(i,n){
		if(S[i])Lx[i]-=a;
		if(T[i])Ly[i]+=a;
	}
}

void KM(){
	CLR(left);
	for(int i=1; i<=n; i++)
		Lx[i]=-INF,Ly[i]=0;
	For(i,n)
		For(j,n)
			Lx[i]=max(Lx[i],w[i][j]);
	For(i,n)
		while(true){
			CLR(S);
			CLR(T);
			if(match(i))break;
			else update();
		}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.txt","r",stdin);
#endif
	scanf("%d",&n);
	For(i,n)
		For(j,n)
			w[i][j]=-INF;
	For(i,n){
		int sum=0;
		For(j,n){
			scanf("%d",&w[i][j]);
			sum+=w[i][j];
		}
		For(j,n)
			w[i][j]=sum-w[i][j];
	}
	For(i,n)
		For(j,n)
			w[i][j]*=-1;
	KM();
	int ans=0;
	For(i,n){
		//printf("%d %d\n",Lx[i],Ly[i]);
		ans+=Lx[i]+Ly[i];
	}
	printf("%d",-ans);
	return 0;
}
