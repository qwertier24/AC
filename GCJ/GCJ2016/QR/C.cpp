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
int n, j, dig[100];

void print(){
  for(int i = j - 1; i >= 0; i--)
    printf("%d",dig[i]);
  puts("");
}
void push(int cur,int k){
  dig[cur] = k;
  for(int i = 2; i <= 10; i++){
    num[i] = num[i] * i + k;
  }
}
void pop(int cur){
  for(int i = 2; i <= 10; i++)
    num[i] /= i;
}
bool is_prime(int n){
  if(
}
bool check(){
  for(int i = 2; i<= 10; i++)
    if(is_prime(num[i]))
      return false;
  return true;
}
void srh(int cur){
  if(cur == n){
    print();
    return;
  }
  if(cur && cur!=n-1){
    push(cur,1);
    srh(cur+1);
    pop(cur);
    if(tot == j)
      return;
  }
  push(cur,0);
  srh(cur+1);
  pop(cur);
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d",&pass,&n,&j);
  srh(0);
  return 0;
}
