#include<stdio.h>
#include<string.h>
#include<algorithm>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using std::max;
using std::sort;

typedef long long LL;
#define N 2010

int n,d[N],a[N],b[N],idx[N],h;
inline bool cmp(const int& i,const int& j){
	return a[i]+b[i]<a[j]+b[j];
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&n);
	memset(d,0xcf,sizeof(d));
	d[0]=0;
	REP(i,1,n){
		scanf("%d%d",&a[i],&b[i]);
		idx[i]=i;
		d[0]+=a[i];
	}
	scanf("%d",&h);
	sort(idx+1,idx+n+1,cmp);
	int ans=0;
	REP(i,1,n)
		RREP(j,i,1){
			if(d[j-1]+b[idx[i]]>=h)d[j]=max(d[j],d[j-1]-a[idx[i]]);
			if(d[j]>=0)ans=max(ans,j);
		}
	printf("%d\n",ans);
	return 0;
}

