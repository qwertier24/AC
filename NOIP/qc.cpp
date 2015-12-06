#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <cstring>
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
int n,m,sum[200010]={0},w[200010],v[200010],l[200010],r[200010];
long long cnt[200010]={0};
long long S;
long long Abs(long long t){
	return t>=0?t:-t;
}
long long solve(int W){
	memset(sum,0,sizeof(sum));
	memset(cnt,0,sizeof(cnt));
	for(int i=1; i<=n; i++)
		sum[i]=sum[i-1]+(w[i]>=W);
	for(int i=1; i<=m; i++)
		cnt[l[i]]+=sum[r[i]]-sum[l[i]-1],cnt[r[i]+1]-=sum[r[i]]-sum[l[i]-1];
	long long t=0,ret=0;
	for(int i=1; i<=n; i++){
		t+=cnt[i];
		//cout<<i<<' '<<t<<' '<<ret<<endl;
		ret+=v[i]*t*(w[i]>=W);
	}
	return ret;
}
int main(){
	freopen("qc.in","r",stdin);
	freopen("qc.out","w",stdout);
	cin>>n>>m>>S;
	For(i,1,n){
		scanf("%d%d",&w[i],&v[i]);
	}
	For(i,1,m){
		scanf("%d%d",&l[i],&r[i]);
	}
	int l=0,r=((int)1e6)+1;
	while(l<r){
		int m=((l+r-1)>>1)+1;
		//cout<<l<<' '<<r<<' '<<m<<endl;
		if(solve(m)>=S)l=m;
		else r=m-1;
	}
	long long ans=Abs(solve(l)-S);
	l=0,r=((int)1e6)+1;
	while(l<r){
		int m=(l+r)>>1;
		//cout<<l<<' '<<r<<' '<<m<<endl;
		if(solve(m)<=S)r=m;
		else l=m+1;
	}
	cout<<min(ans,Abs(solve(l)-S));
	return 0;
}

