#include<stdio.h>
#include<time.h>
#include<stack>
#include<vector>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define N 1000010
#define LOG 21
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
using std::stack;
using std::vector;

int n,a[N],val[N],sum[N],rgt[N],lft[N];
vector<int> v[N];
char str[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%s",&n,str);
	REP(i,0,n-1){
		a[i+1]=str[i]=='p'?1:-1;
		sum[i+1]=sum[i]+a[i+1];
	}
	
	stack<int> st;
	REP(i,1,n){
		if(a[i]>0)st.push(i);
		while(!st.empty() && sum[i]-sum[st.top()-1]<0){
			rgt[st.top()]=i-1;
			st.pop();
		}
	}
	while(!st.empty()){
		rgt[st.top()]=n;
		st.pop();
	}
	RREP(i,n,1){
		if(a[i]>0)st.push(i);
		while(!st.empty() && sum[st.top()]-sum[i-1]<0){
			lft[st.top()]=i+1;
			st.pop();
		}
	}
	while(!st.empty()){
		lft[st.top()]=1;
		st.pop();
	}
	REP(i,1,n)if(lft[i])v[lft[i]].push_back(i);
	
	int ans=0;
	REP(i,1,n){
		REP(j,0,int(v[i].size())-1){
			for(int p=v[i][j]; p<=n; p+=(p&(-p)))
				val[p]=max(val[p],v[i][j]);
		}
		if(a[i]>0){
			int r=0;
			for(int p=rgt[i]; p; p-=(p&(-p)))
				r=max(r,val[p]);
			ans=max(ans,r-i+1);
		}
	}
	printf("%d\n",ans);
	return 0;
}
