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

char mat[100][100],s[100];
void modify(char *s,int r,int c){
  Rep(i,r)Rep(j,c){
    mat[i][j]=s[i*c+j];
  }
}
bool check(int r,int c){
  Rep(j,c){
    int flag=1;
    Rep(i,r)
      if(mat[i][j]!='X')
	flag=0;
    if(flag)return true;
  }
  return false;
}
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  int T;
  vector<int> ans;
  scanf("%d",&T);
  while(T--){
    ans.clear();
    scanf("%s",s);
    For(i,12)
      if(12%i==0){
	modify(s,i,12/i);
	if(check(i,12/i))ans.push_back(i);
      }
    printf("%d",ans.size());
    Rep(i,ans.size())
      printf(" %dx%d",ans[i],12/ans[i]);
    puts("");
  }
  return 0;
}
