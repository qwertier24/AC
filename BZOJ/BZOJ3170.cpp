#include<stdio.h>
#include<string.h>
#include<algorithm>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
using std::sort;
#define N 100010

typedef long long LL;

int n,x[N],y[N],id[N];
bool cmpx(const int &a,const int& b){
	return x[a]<x[b];
}
bool cmpy(const int& a,const int& b){
	return y[a]<y[b];
}
LL suml,sumr,ans=1ll<<60,sum[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&n);
	REP(i,1,n){
		scanf("%d%d",&x[i],&y[i]);
		x[i]=x[i]+y[i];
		y[i]=x[i]-2*y[i];
		id[i]=i;
	}
	sort(id+1,id+n+1,cmpx);
	suml=sumr=0;
	REP(i,1,n)sumr+=x[i];
	REP(j,1,n){
		int &i=id[j];
		sumr-=x[i];
		sum[i]+=(j-1)*(LL)x[i]-suml+sumr-(n-j)*(LL)x[i];
		suml+=x[i];
	}
	
	sort(id+1,id+n+1,cmpy);
	suml=sumr=0;
	REP(i,1,n)sumr+=y[i];
	REP(j,1,n){
		int &i=id[j];
		sumr-=y[i];
		sum[i]+=(j-1)*(LL)y[i]-suml+sumr-(n-j)*(LL)y[i];
		suml+=y[i];
		if(ans>sum[i])ans=sum[i];
	}
	printf("%lld\n",ans>>1);
	return 0;
}

