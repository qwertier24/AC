#include<stdio.h>
#include<algorithm>
#include<string.h>
#define N 110
#define For(i,n) for(int i=1; i<=n; i++)
#define CLR(t) memset(t,0,sizeof(t))
#define INF (1<<29)
#define X first
#define Y second
using namespace std;

typedef pair<int,int> P;
P man[N],house[N];

int Lx[N],Ly[N],T[N],S[N],n,hn,left[N],w[N][N];
char g[N][N];

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
	int a=1<<30;
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
		Lx[i]=-INF,Ly[i]=-INF;
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
	int r,c;
	while(scanf("%d%d",&r,&c)&&r){
		For(i,r)
			scanf("%s",g[i]+1);
		n=hn=0;
		For(i,r)
			For(j,c){
				if(g[i][j]=='m')
					man[++n]=P(i,j);
				else if(g[i][j]=='H')
					house[++hn]=P(i,j);
			}
		For(i,n)
			For(j,n)
				w[i][j]=-(abs(man[i].X-house[j].X)+abs(man[i].Y-house[j].Y));
		KM();
		int ans=0;
		For(i,n)ans+=Lx[i]+Ly[i];
		printf("%d\n",-ans);
	}
	return 0;
}
