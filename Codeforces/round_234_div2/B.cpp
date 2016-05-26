#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

typedef long long LL;
using namespace std;

int n,m,v[1010];
char g[1010][1010];
set<int> st;
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  Rep(i,n)
    scanf("%s",g[i]);
  Rep(i,n){
    int flag=-1;
    Rep(j,m){
      if(g[i][j]=='G')
	flag=j;
      if(g[i][j]=='S'){
	if(flag==-1){
	  puts("-1");
	  return 0;
	}
	v[i]=j-flag;
      }
    }
    st.insert(v[i]);
  }
  printf("%d",st.size());
  return 0;
}
