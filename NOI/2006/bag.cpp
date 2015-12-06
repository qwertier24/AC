#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 1010

int fp[20010],pri[20010],pcnt;
void init(){
  REP(i,2,20000){
    if(!fp[i])
      pri[pcnt++]=i;
    for(int j=0; j<pcnt&&pri[j]*i<=20000; j++){
      if(i%pri[j]==0){
        fp[i*pri[j]]=pri[j];
        break;
      }else
        fp[i*pri[j]]=pri[j];
    }
  }
}
struct BIGN{
  int num[30000],len;
  BIGN(){len=1,num[1]=1;}
  void operator*=(int t){
    int c=0;
    for(int i=1; i<=len||c; i++){
      if(i>len)len=i;
      num[i]*=t;
      num[i]+=c;
      c=num[i]/10;
      num[i]-=c*10;
    }
  }
  void print(){
    RREP(i,len,1)putchar(num[i]+'0');
  }
}a,b;

int pw[20010],x[N],y[N],n,m,d,cnt[N],tot;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  init();
  scanf("%d%d%d",&n,&m,&d);
  REP(i,1,n){
    scanf("%d",&cnt[i]);
    tot+=cnt[i];
  }
  REP(i,1,m)
    scanf("%d%d",&x[i],&y[i]);
  REP(i,1,m){
    pw[tot]--;
    pw[cnt[y[i]]]++;
    cnt[y[i]]+=d;
    tot+=d;
  }
  RREP(i,20000,2)if(pw[i]){
    if(fp[i]){
      pw[i/fp[i]]+=pw[i];
      pw[fp[i]]+=pw[i];
    }else{
      if(pw[i]<0){
        REP(j,pw[i],-1)
          b*=i;
      }else{
        REP(j,1,pw[i])
          a*=i;
      }
    }
  }
  a.print();
  putchar('/');
  b.print();
  return 0;
}
