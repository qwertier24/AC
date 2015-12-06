#include<stdio.h>
#include<string.h>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define N 200010

using std::set;
typedef long long LL;

LL a[N],M,ans;
set<LL> st;
set<LL>::iterator it;
int n;
int main(){
#ifndef ONLINE_JUDGE
	//freopen("in.txt","r",stdin);
#endif
	scanf("%d%lld",&n,&M);
	st.insert(0);
	REP(i,1,n){
		scanf("%lld",&a[i]);
		a[i]=(a[i-1]+a[i])%M;
		if(a[i]<0)a[i]+=M;
		it=st.upper_bound(M-a[i]-1);
		if(it!=st.begin()){
			--it;
			if(ans<*it+a[i])ans=*it+a[i];
		}
		st.insert(M-a[i]);
	}
	printf("%lld",ans);
	return 0;
}

