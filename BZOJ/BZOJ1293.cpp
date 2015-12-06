#include <algorithm>
#include <stdio.h>
#include <string.h>
#define For(i,n) for(int i=1; i<=n; i++)
using namespace std;
#define N 1000010
#define X first
#define T second
#define MP make_pair
typedef pair<int,int> pii;

int n,m,fr=0,rr=-1;
pii a[N],q[N];
int cnt[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	n=0;
	For(i,m){
		int nt;
		scanf("%d",&nt);
		For(j,nt){
			int pt;
			scanf("%d",&pt);
			a[++n]=MP(pt,i);
		}
	}
	sort(a+1,a+n+1);
	int tot=0,ans=(~0)^(1<<31);
	For(i,n){
		if(cnt[a[i].T]==0)tot++;
		cnt[a[i].T]++;
		q[++rr]=a[i];
		while(cnt[q[fr].T]>1){
			cnt[q[fr].T]--;
			fr++;
		}
		if(tot==m)ans=min(ans,a[i].X-q[fr].X);
	}
	printf("%d\n",ans);
	return 0;
}

