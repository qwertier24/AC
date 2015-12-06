#include<stdio.h>
#include<set>
#define INF (1<<30)

using namespace std;

int a,n,cur,ans;
set<int> st;
set<int>::iterator it;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		if(scanf("%d",&a)==EOF)a=0;
		cur=INF;
		it=st.upper_bound(a);
		if(it!=st.end()&&st.size())
			cur=min(cur,*it-a);
		if(it!=st.begin()&&st.size()){
			it--;
			cur=min(cur,a-*it);
		}
		if(cur==INF)ans+=a;
		else ans+=cur;
		st.insert(a);
	}
	printf("%d",ans);
	return 0;
}
