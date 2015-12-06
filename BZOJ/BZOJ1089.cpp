#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define H 20
#define MOD 1000000007
#define MAXLEN 500

using namespace std;
typedef long long LL;

struct BIGN{
  int num[MAXLEN],len;
  int& operator[](int x){
    return num[x];
  }
  BIGN operator*(BIGN& r){
    BIGN ret;
    For(i,len)For(j,r.len){
      ret[i+j-1]+=num[i]*r[j];
    }
    ret.len=len+r.len-1;
    int c=0;
    for(int i=1; i<=ret.len || c; i++){
      ret.len=max(i,ret.len);
      ret[i]+=c;
      c=ret[i]/10;
      ret[i]%=10;
    }
    return ret;
  }
  BIGN operator+(BIGN& r){
    BIGN ret;
    ret.len=max(len,r.len);
    int c=0;
    for(int i=1; i<=ret.len||c; i++){
      ret.len=max(ret.len,i);
      ret[i]=num[i]+r[i]+c;
      c=ret[i]/10;
      ret[i]%=10;
    }
    return ret;
  }
  BIGN operator-(BIGN& r){
    BIGN ret;
    for(int i=1; i<=max(len,r.len); i++){
      if(num[i]<r[i]){
	num[i+1]--;
	num[i]+=10;
      }
      ret[i]=num[i]-r[i];
      if(ret[i])ret.len=i;
    }
    return ret;
  }
  BIGN(int t=0){
    memset(num,0,sizeof(num));
    len=1;
    num[1]=t;
  }
  void print(){
    for(int i=len; i; i--)printf("%d",num[i]);
    puts("");
  }
}d[H],sumd1(1),sumd2,t1,t2;

int n,h;
BIGN fpow(BIGN t,int p){
  BIGN ret(1);
  while(p){
    if(p&1)ret=ret*t;
    t=t*t;
    p>>=1;
  }
  return ret;
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&h);
  d[0]=1;
  For(i,h){
    t1=fpow(sumd1,n),t2=fpow(sumd2,n);
    d[i]=t1-t2;
    sumd1=sumd1+d[i];
    sumd2=sumd2+d[i-1];
  }
  d[h].print();
  return 0;
}
