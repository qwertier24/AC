#include<stdio.h>
#include<algorithm>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define PROB "milktemp"
#define N 20000
using namespace std;


int n,l[N+10],r[N+10];
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	int n,x,y,z;
	scanf("%d%d%d%d",&n,&x,&y,&z);
	set<int> st;
	For(i,n){
		scanf("%d%d",&l[i],&r[i]);
		st.insert(l[i]);
		st.insert(r[i]);
	}
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	int pl=1,pr=1,ans=0,comfort=0,hot=0;
	for(set<int>::iterator it=st.begin(); it!=st.end(); ++it){
		int t=*it;
		while(pl<=n&&l[pl]==t)
			comfort++,pl++;
		while(pr<=n&&r[pr]<t)
			hot++,pr++,comfort--;
		ans=max(ans,z*hot+y*comfort+x*(n-hot-comfort));
	}
	printf("%d",ans);
	return 0;
}

