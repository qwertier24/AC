#include<stdio.h>
#include<string.h>
#include<algorithm>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define abs(x) ((x)>0?(x):(-(x)))

using std::sort;
typedef long long LL;

#define N 100010
LL ans=1ll<<60;
int n,x[N],y[N];
void update(int xt,int yt){
	if((xt+yt)&1)return;
	LL ret=0;
	REP(i,1,n)
		ret+=abs(x[i]-xt)+abs(y[i]-yt);
	ans=ans>ret?ret:ans;
}
int dx[3]={0,-1,1},dy[3]={0,-1,1};
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&n);
	REP(i,1,n){
		scanf("%d%d",&x[i],&y[i]);
		x[i]=x[i]+y[i];
		y[i]=x[i]-2*y[i];
	}
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	int ax=x[(n+1)/2],ay=y[(n+1)/2];
	REP(i,0,2)REP(j,0,2)update(ax+dx[i],ay+dy[j]);
	printf("%lld\n",ans>>1);
	return 0;
}

