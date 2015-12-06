#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define MP make_pair
#define fi first
#define se second

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define N 100000

pii v[N+10];
int pri[N+10],pcnt,mu[N+10];
void init(){
	memset(mu,0x3f,sizeof(mu));
	mu[1]=1;
	REP(i,2,N){
		if(mu[i]>1){
			mu[i]=-1;
			pri[pcnt++]=i;
		}
		for(int j=0; j<pcnt && pri[j]*i<=N; j++){
			if(i%pri[j]==0){
				mu[i*pri[j]]=0;
				break;
			}else
				mu[i*pri[j]]=-mu[i];
		}
	}
	REP(i,1,N){
		int s=0;
		for(int j=1; j*j<=i; j++)
			if(i%j==0){
				s+=j;
				if(i/j!=j)
					s+=i/j;
			}
		v[i]=MP(s,i);
	}
	sort(v+1,v+N+1);
}

int val[N+10];
void add(int p,int v){
	while(p<=N){val[p]+=v;p+=p&(-p);}
}
int sum(int p){
	int ret=0;
	while(p){ret+=val[p];p-=p&(-p);}
	return ret;
}

int T,ans[N+10];
struct Q{
	int n,m,a,id;
	const bool operator<(const Q& r)const{return a<r.a;}
}q[N+10];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	init();
	scanf("%d",&T);
	REP(i,1,T){
		scanf("%d%d%d",&q[i].n,&q[i].m,&q[i].a);
		if(q[i].n>q[i].m)swap(q[i].n,q[i].m);
		q[i].id=i;
	}
	sort(q+1,q+T+1);
	int p=1;
	REP(i,1,T){
		while(p<=N && v[p].fi<=q[i].a){
			for(int j=1; j*v[p].se<=N; j++)
				add(j*v[p].se,mu[j]*v[p].fi);
			++p;
		}
		int &n=q[i].n,&m=q[i].m;
		for(int j=1,lst; j<=n; j=lst+1){
			lst=min(n/(n/j),m/(m/j));
			ans[q[i].id]+=(sum(lst)-sum(j-1))*(n/j)*(m/j);
		}
	}
	REP(i,1,T){
		if(ans[i]<0)ans[i]+=1<<31;
		printf("%d\n",ans[i]);
	}
	return 0;
}

