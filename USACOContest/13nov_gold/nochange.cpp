#include<stdio.h>
#include<algorithm>
#define Rep(i,n) for(int i=0; i<(n); i++)
#define For(i,n) for(int i=1; i<=n; i++)
#define PROB "nochange"
#define N 100000
#define M 16
#define dbg if(0)

using namespace std;

int n,m,sum[N+10]={0},coin[M+10],d[1<<M]={0};

int count(int S){
	int ret=0;
	Rep(i,m)
		if(!(1&(S>>i)))
			ret+=coin[i];
	return ret;
}

int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d",&m,&n);
	Rep(i,m)
		scanf("%d",&coin[i]);
	For(i,n){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
dbg		printf("%d\n",sum[i]);
	}
	int ans=-1;
	Rep(S,1<<m){
		Rep(i,m)
			if(1&(S>>i))
				d[S]=max(d[S],(int)(upper_bound(sum+1,sum+n+1,sum[d[S^(1<<i)]]+coin[i])-sum-1));
dbg		printf("%o %d\n",S,d[S]);
		if(d[S]==n)
			ans=max(ans,count(S));
	}
	printf("%d",ans);
}
