#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
using namespace std;
vector<int> f;

struct BIGN{
  int num[1010],len;
  BIGN(int x){
    memset(num,0,sizeof(num));
    len=1;
    num[1]=x;
  }
  void operator+=(BIGN &t){
    int c=0;
    for(int i=1; i<=max(len,t.len)||c; i++){
      if(i>len)len=i;
      if(len>=1010)while(true);
      num[i]+=t.num[i]+c;
      c=num[i]/10;
      num[i]-=c*10;
    }
  }
  void operator*=(int x){
    int c=0;
    for(int i=1; i<=len||c; i++){
      if(i>len)len=i;
      if(len>=1010)while(true);
      num[i]*=x;
      num[i]+=c;
      c=num[i]/10;
      num[i]-=c*10;
    }
  }
  void operator-=(BIGN &t){
    REP(i,1,len){
      if(num[i]<t.num[i]){
        num[i+1]--;
        num[i]+=10;
      }
      num[i]=num[i]-t.num[i];
    }
    while(len>1 && !num[len])len--;
  }
  void print(){
    if(!len)puts("0");
    else{
      RREP(i,len,1)printf("%d",num[i]);
      puts("");
    }
  }
}a(0),b(0),tmp(0);
inline BIGN Pow(int t,int p){
  BIGN ret(1);
  REP(i,1,p)ret*=t;
  return ret;
}
int n,m;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  int mt=m;
  for(int i=2; i*i<=mt; i++){
    if(mt%i)continue;
    f.push_back(i);
    while(mt%i==0)
      mt/=i;
  }
  if(mt>1)f.push_back(mt);
  for(int i=0; i<(1<<f.size()); i++){
    int mul=1,g=1;
    for(int j=0; j<f.size(); j++)
      if(1&(i>>j)){
        mul*=-1;
        g*=f[j];
      }
    tmp=Pow(m/g,n);
    if(mul<0)b+=tmp;
    else a+=tmp;
  }
  a-=b;
  a.print();
  return 0;
}
