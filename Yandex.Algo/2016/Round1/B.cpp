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


int n = 9;
int cur[9];
char des[9];
bool check_c(int x){
    return x>=0 && x<3;
}
int dx[4]= {0,0,-1,1},dy[4]={-1,1,0,0};
bool check(){
    REP(i,n)
        if(cur[i] != des[i]-'0' && des[i] != '?')
            return false;
    FOR(i,n-1)REP(x,3)REP(y,3)if(cur[x*3+y] == i){
        int flag = 0;
        REP(k,4)
            if(check_c(x + dx[k]) && check_c(y+dy[k]) && cur[(x+dx[k])*3+y+dy[k]] == i + 1)
                flag = 1;
        if(!flag)
            return false;
    }
    return true;
}
void print(){
    REP(i,n)
        printf("%d%s",cur[i],((i+1)%3==0)?"\n":"");
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  REP(i,3)
      scanf("%s",des+(i*3));
  REP(i,n)
      cur[i] = i + 1;
  do{
      if(check())
          print();
  }while(next_permutation(cur,cur+n));
  return 0;
}
