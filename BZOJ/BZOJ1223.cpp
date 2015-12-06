#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<ctype.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

#define N 110
using namespace std;
struct BIGN{
  int num[N*4],len;
  void operator/=(int x){
    RREP(i,len,1){
      num[i-1]+=num[i]%x*10;
      num[i]/=x;
    }
    while(len && !num[len])len--;
  }
  void operator+=(BIGN &t){
    len=max(t.len,len);
    for(int i=1; i<=len||num[i]; i++){
      if(len<i)len=i;
      num[i]+=t[i];
      num[i+1]+=num[i]/10;
      num[i]%=10;
    }
  }
  void operator*=(int x){
    int c=0;
    for(int i=1; i<=len||c; i++){
      if(len<i)len=i;
      num[i]*=x;
      num[i]+=c;
      c=num[i]/10;
      num[i]-=c*10;
    }
  }
  int& operator[](int x){return num[x];}
  void read(){
    char c=getchar();
    while(!isdigit(c))c=getchar();
    len=0;
    while(isdigit(c)){
      num[++len]=c-'0';
      c=getchar();
    }
    reverse(num+1,num+len+1);
  }
  void print(){
    RREP(i,len,1)printf("%d",num[i]);
    puts("");
  }
  BIGN(){
    memset(num,0,sizeof(num));
    len=1;
  }
}ans,p2[N*4],m,n;

int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  p2[0][1]=1;
  REP(i,1,400){
    p2[i]=p2[i-1];
    p2[i]*=2;
  }
  n.read();
  int len=0;
  while(n.len>1 || n[1]){
    m[++len]=n[1]%2;
    n/=2;
  }
  RREP(i,len-1,len/2+1){
    if(!m[i])continue;
    ans+=p2[i-(len/2+1)];
  }
  REP(i,1,len-1)
    ans+=p2[(i-1)/2];
  int flag=1;
  RREP(i,len/2,1){
    if(m[i]^m[len-i+1]){
      if(m[len-i+1])flag=0;
      break;
    }
  }
  if(flag){
    BIGN tmp;
    tmp[1]=1;
    ans+=tmp;
  }
  ans.print();
  return 0;
}
