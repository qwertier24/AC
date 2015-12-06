#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
using namespace std;

#define N 60
struct BIGN{
  int num[80],len;
  BIGN(){len=1;memset(num,0,sizeof(num));}
  inline int& operator[](int x){return num[x];}
  void operator*=(int x){
    int c=0;
    for(int i=1; i<=len||c; i++){
      if(i>len)len=i;
      num[i]*=x;
      num[i]+=c;
      c=num[i]/10;
      num[i]-=c*10;
    }
  }
  void operator+=(BIGN &t){
    len=max(len,t.len);
    for(int i=1; i<=len||num[i]; i++){
      if(i>len)len=i;
      num[i]+=t[i];
      num[i+1]+=num[i]/10;
      num[i]%=10;
      //printf("%d %d\n",i,num[i]);
    }
  }
  void print(){
    RREP(i,len,1)putchar(num[i]+'0');
    puts("");
  }
}f[N][N],ans[N];
void init(){
  f[0][0][1]=1;
  REP(i,1,50)REP(j,1,50){
    f[i][j]=f[i-1][j-1];
    f[i][j]+=f[i-1][j];
    f[i][j]*=j;
    ans[i]+=f[i][j];
    //f[i][j].print();
  }
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int T,n;
  init();
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    ans[n].print();
  }
  return 0;
}
