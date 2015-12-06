#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#define PROB
using namespace std;
#define N 50010
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

typedef long long LL;
typedef pair<int,int> pii;
const int sz=300;

int bn;
int b[N];

int val[N];
#define lowbit(x) (x&(-x))
int sum(int p){
	int ret=0;
	while(p){
		ret+=val[p];
		p-=lowbit(p);
	}
	return ret;
}
void add(int p,int v){
	while(p<=bn){
		val[p]+=v;
		p+=lowbit(p);
	}
}

int n,m;
vector<int> q[N/sz+10];
pii Q[N];
int ans[N],a[N];
bool cmp(const int& a,const int& b){
	return Q[a].second<Q[b].second;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&n);
	For(i,n){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	bn=unique(b+1,b+n+1)-b-1;
	For(i,n)a[i]=lower_bound(b+1,b+bn+1,a[i])-b;
	
	scanf("%d",&m);
	For(i,m){
		scanf("%d%d",&Q[i].first,&Q[i].second);
		q[Q[i].first/sz].push_back(i);
	}
	Rep(i,n/sz+1){
		memset(val,0,sizeof(val));
		int curl=1,curr=0;
		int cnt=0;
		sort(q[i].begin(),q[i].end(),cmp);
		Rep(j,q[i].size()){
			int &l=Q[q[i][j]].first,&r=Q[q[i][j]].second;
			while(curr<r){
				++curr;
				cnt+=sum(bn)-sum(a[curr]);
				add(a[curr],1);
			}
			if(curl<l){
				for(; curl<l; curl++){
					add(a[curl],-1);
					cnt-=sum(a[curl]-1);
				}
			}else if(curl>l){
				for(curl--; curl>=l; curl--){
					cnt+=sum(a[curl]-1);
					add(a[curl],1);
				}
				curl=l;
			}
			ans[q[i][j]]=cnt;
		}
	}
	For(i,m)
		printf("%d\n",ans[i]);
	return 0;
}

