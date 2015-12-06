#include<stdio.h>
#include<algorithm>
#include<ctype.h>
#include<math.h>
#define N 100000
#define For(i,n) for(int i=1; i<=n; i++)


using namespace std;

typedef unsigned long long LL;

void readint(int& x){
  x=0;
  char c=getchar();
  while(!isdigit(c))
    c=getchar();
  while(isdigit(c)){
    x=x*10+c-'0';  
    c=getchar();
  }
}
void readll(LL& x){
  x=0;
  char c=getchar();
  while(!isdigit(c))
    c=getchar();
  while(isdigit(c)){
    x=x*10+c-'0';
    c=getchar();
  }
}
char dig[20];
int cnt;
void output(LL &x){
  if(x==0){
    puts("0");
    return;
  }
  cnt=0;
  while(x){
    dig[++cnt]=x%10+'0';
    x/=10;
  }
  while(cnt)putchar(dig[cnt--]);
  putchar('\n');
}

LL a[N+10],sumv[N<<2],_sum;
int mark[N<<2];
int L,R;
void build(int o,int l,int r){
  if(l==r){
    mark[o]=a[l]==1;
    sumv[o]=a[l];
    return;
  }
  int m=(l+r)>>1;
  build(o<<1,l,m);
  build(o<<1|1,m+1,r);
  mark[o]=mark[o<<1]&mark[o<<1|1];
  sumv[o]=sumv[o<<1]+sumv[o<<1|1];
}
/*
LL sqrt(LL& x){
  LL l=1,r=x,m;
  while(l<r){
    m=l+1+((r-l-1)>>1);
    if(m==x/m&&m*m==x)return m;
    else if(m<=x/m)l=m;
    else r=m-1;
  }
  return l;
}
*/
void update(int o,int l,int r){
  if(mark[o]==1)return;
  if(l==r){
    sumv[o]=(LL)sqrt(sumv[o]);
    mark[o]=sumv[o]==1;
    return;
  }
  int m=(l+r)>>1;
  if(L<=m)update(o<<1,l,m);
  if(R>m)update(o<<1|1,m+1,r);
  mark[o]=mark[o<<1]&mark[o<<1|1];
  sumv[o]=sumv[o<<1]+sumv[o<<1|1];
}
void query(int o,int l,int r){
  if(mark[o]){
    _sum+=min(R,r)-max(L,l)+1;
    return;
  }
  if(L<=l&&r<=R){
    _sum+=sumv[o];
    return;
  }
  int m=(l+r)>>1;
  if(L<=m)query(o<<1,l,m);
  if(R>m)query(o<<1|1,m+1,r);
}
int n,m,opt;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  For(i,n)readll(a[i]);
  build(1,1,n);
  readint(m);
  For(i,m){
    readint(opt);
    readint(L);
    readint(R);
    if(opt){
      _sum=0;
      if(L>R)swap(L,R);
      query(1,1,n);
      output(_sum);
    }else{
      if(L>R)swap(L,R);
      update(1,1,n);
    }
  }
  return 0;
}

