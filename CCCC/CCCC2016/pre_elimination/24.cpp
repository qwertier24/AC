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

#define N 1010
map<int,int> pos;
int t[N], sz;
void insert(int u){
    t[++sz] = u;
    int cur = sz;
    while(true){
        int fa = cur>>1;
        if(t[fa] > u)
            swap(t[fa], t[cur]);
        else
            break;
        cur = fa;
    }
}

char ch[2] = {'F','T'};
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int n, m;
  t[0] = -20000;
  scanf("%d%d",&n,&m);
  FOR(i,n){
      int u;
      scanf("%d",&u);
      insert(u);
  }
  FOR(i,sz){
      pos[t[i]] = i;
      //printf("%d\n", t[i]);
  }
  FOR(i,m){
      int x, y;
      char op[200];
      scanf("%d",&x);
      scanf("%s",op);
      if(op[0] == 'i'){ //1 3 4
          scanf("%s", op);
          if(op[0] == 't'){ // 1 3
              scanf("%s", op);
              if(op[0] == 'r'){ // 1
                  printf("%c\n", ch[pos[x] == 1]);
              }else{ // 3
                  scanf("%s", op);
                  scanf("%d", &y);
                  printf("%c\n", ch[pos[y]/2 == pos[x]]);
              }
          }else{ // 4
              scanf("%s%s",op,op);
              scanf("%d",&y);
              printf("%c\n", ch[pos[x]/2 == pos[y]]);
          }
      }else{ // 2
          scanf("%d",&y);
          scanf("%s%s",op,op);
          printf("%c\n",ch[pos[x]/2 == pos[y]/2]);
      }
  }
  return 0;
}
