#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#define PROB
using namespace std;

#define MP make_pair
#define N 50010
#define fi first
#define se second
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define gcd __gcd

const int sz=250;
typedef long long LL;
typedef pair<int,int> pii;

int n,m;
vector<int> q[N/sz+10];
int mark[N],a[N];
LL ans1[N],ans2[N];
pii Q[N];
bool cmp(const int& a,const int& b){
	return Q[a].se<Q[b].se;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	For(i,n)scanf("%d",&a[i]);
	For(i,m){
		int l,r;
		scanf("%d%d",&Q[i].fi,&Q[i].se);
		q[Q[i].fi/sz].push_back(i);
	}
	Rep(i,n/sz+1){
		sort(q[i].begin(),q[i].end(),cmp);
		int curl=1,curr=0;
		LL cnt=0;
		memset(mark,0,sizeof(mark)); 
		Rep(j,q[i].size()){
			int &l=Q[q[i][j]].fi,&r=Q[q[i][j]].se;
			while(curr<r){
				cnt+=mark[a[++curr]]++;
			}
			if(curl<l){
				for(int k=curl; k<l; k++)
					cnt-=--mark[a[k]];
			}else if(curl>l){
				for(int k=curl-1; k>=l; k--)
					cnt+=mark[a[k]]++;
			}
			curl=l;
			ans1[q[i][j]]=cnt;
			ans2[q[i][j]]=(r-l+1)*(LL)(r-l)/2;
		}
	}
	For(i,m){
		if(ans1[i]==0)puts("0/1");
		else printf("%lld/%lld\n",ans1[i]/gcd(ans1[i],ans2[i]),ans2[i]/gcd(ans1[i],ans2[i]));
	}
	return 0;
}

