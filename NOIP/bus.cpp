#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
int n,m,sum[1010]={0},D[1010],t[1010]={0},latest[1010]={0},k;
struct Interval{
	int l,r,cnt;
	Interval(int a,int b,int c){
		l=a,r=b,cnt=c;
	}
	bool operator<(const Interval& rhs)const{
		return cnt<rhs.cnt;
	}
};
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	long long ans=0;
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,n-1)scanf("%d",&D[i]);
	For(i,1,m){
		int a,b,T;
		scanf("%d%d%d",&T,&a,&b);
		ans-=T;
		sum[b]++;
		latest[a]=max(latest[a],T);
	}
	
	
	int last_p=1;
	priority_queue<Interval> pq;
	For(i,2,n){
		sum[i]+=sum[i-1];
		t[i]=max(latest[i-1],t[i-1])+D[i-1];
		//printf("  %d %d %d %d\n",i,t[i],latest[i],sum[i]-sum[i-1]);
		if(t[i]<=latest[i]){
			pq.push(Interval(last_p+1,i,sum[i]-sum[last_p]));
			last_p=i;
		}
	}
	if(last_p!=n)
		pq.push(Interval(last_p+1,n,sum[n]-sum[last_p]));
	
	
	
	while(k){
		if(pq.empty())break;
		Interval itv=pq.top();
		pq.pop();
		int max_dec=min(k,D[itv.l-1]);
		for(int i=itv.l; i<itv.r; i++)
			max_dec=min(t[i]-latest[i],max_dec);
			
		//printf("%d %d %d %d\n",itv.l,itv.r,itv.cnt,max_dec);
		for(int i=itv.l; i<=itv.r; i++)
			t[i]-=max_dec;
		D[itv.l-1]-=max_dec;
		k-=max_dec; 
		
		if(D[itv.l-1]&&t[itv.l]>latest[itv.l])
			last_p=itv.l-1;
		else
			last_p=itv.l;
		for(int i=itv.l+1; i<=itv.r; i++){
			if(t[i]<=latest[i]){
				pq.push(Interval(last_p+1,i,sum[i]-sum[last_p]));
				last_p=i;
			}
		}
		if(last_p!=itv.r)
			pq.push(Interval(last_p+1,itv.r,sum[itv.r]-sum[last_p]));
	}
	//for(int i=1; i<=n; i++)
	//	printf("%d %d\n",i,t[i]);
	for(int i=1; i<=n; i++)
		ans+=(sum[i]-sum[i-1])*(long long)t[i];
	cout<<ans<<endl;
	return 0;
}

