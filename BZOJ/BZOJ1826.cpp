#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

#define N 100010
int n,sz,m,a[N],b[N],mark[N],nxt[N],ans;
priority_queue<pair<int,int> > pq;
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&sz);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	for(int i=1; i<=m; i++)mark[i]=n+1;
	for(int i=n; i; i--){
		a[i]=lower_bound(b+1,b+m+1,a[i])-b;
		nxt[i]=mark[a[i]];
		mark[a[i]]=i;
	}
	memset(mark,0,sizeof(mark));
	for(int i=1; i<=n; i++){
		if(!mark[a[i]]){
			if(sz)sz--;
			else{
				mark[pq.top().second]=0;
				pq.pop();
			}
			ans++;
		}
		mark[a[i]]=1;
		pq.push(make_pair(nxt[i],a[i]));
	}
	printf("%d\n",ans);
	return 0;
}
