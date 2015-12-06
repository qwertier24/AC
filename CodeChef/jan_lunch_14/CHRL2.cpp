#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;

vector<int> pos[4];
vector<int>::iterator it[4];
int idx(char c){
  if(c=='C')return 0;
  if(c=='H')return 1;
  if(c=='E')return 2;
  if(c=='F')return 3;
}
char s[100010];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%s",s);
  int n=strlen(s);
  Rep(i,n)
    pos[idx(s[i])].push_back(i);
  int ans=0;
  Rep(i,4)
    it[i]=pos[i].begin();
  while(true){
    int lpos=-1;
    Rep(i,4){
      while(it[i]!=pos[i].end()&&*it[i]<=lpos)
	++it[i];
      if(it[i]==pos[i].end()){
	printf("%d",ans);
	return 0;
      }
      lpos=*it[i];
      ++it[i];
    }
    //printf("%d\n",lpos);
    ans++;
  }
  return 0;
}
