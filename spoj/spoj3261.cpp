#include<stdio.h>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100000

typedef long long LL;
using namespace std;

void readint(int &x){
  x=0;
  char c=getchar();
  while(!isdigit(c))c=getchar();
  while(isdigit(c)){
    x=x*10+c-'0';
    c=getchar();
  }
}
int dig[30],cnt;
void writeint(int x){
  cnt=0;
  if(x==0){
    puts("0");
    return;
  }
  while(x){
    dig[++cnt]=x%10;
    x/=10;
  }
  for(int i=cnt; i; i--)
    putchar(dig[i]+'0');
  putchar('\n');
}

int n,a[N];
int sz,bkn,blk[400][400];
void init(){
  memset(blk,0x3f,sizeof(blk));
  sz=(int)sqrt(n);
  bkn=(n-1)/sz+1;
  Rep(i,n){
    blk[i/sz][i%sz]=a[i];
  }
  Rep(i,bkn)
    sort(blk[i],blk[i]+sz);
}
void erase(int bki,int v){
  int k=lower_bound(blk[bki],blk[bki]+sz,v)-blk[bki];
  for(int i=k; i<sz-1; i++){
    blk[bki][i]=blk[bki][i+1];
  }
}
void insert(int bki,int v){
  for(int i=sz-1; i>=0; i--){
    if(i==0 || blk[bki][i-1]<=v){
      blk[bki][i]=v;
      break;
    }
    blk[bki][i]=blk[bki][i-1];
  }
}
int query(int l,int r,int v){
  int lb=l/sz,rb=r/sz,ret=0;
  for(int i=lb+1; i<rb; i++)
    ret+=upper_bound(blk[i],blk[i]+sz,v)-blk[i];
  for(int i=l; i<=r&&i/sz==lb; i++){
    ret+=a[i]<=v;
  }
  if(rb>lb){
    for(int i=r; i>=0 && i/sz==rb; i--)
      ret+=a[i]<=v;
  }
  return ret;
}
int m,p,v,l,r;
char op[10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  readint(n);readint(m);
  Rep(i,n)readint(a[i]);
  init();
  while(m--){
    scanf("%s",op);
    if(op[0]=='C'){
      readint(l);readint(r);readint(v);
      writeint(query(l-1,r-1,v));
    }else{
      readint(p);readint(v);
      p--;
      erase(p/sz,a[p]);
      a[p]=v;
      insert(p/sz,a[p]);
    }
  }
  return 0;
}
