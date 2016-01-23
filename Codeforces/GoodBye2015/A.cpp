#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

char s[10];
int day[7]={52,52,52,52,53,53,52},month[31];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int k;
  scanf("%d%s",&k,s);
  scanf("%s",s);
  REP(i,29)
    month[i]=12;
  month[29]=11;
  month[30]=7;
  if(s[0]=='w'){
    printf("%d\n",day[k-1]);
  }else{
    printf("%d\n",month[k-1]);
  }
  return 0;
}
