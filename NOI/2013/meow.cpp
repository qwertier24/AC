#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<ctype.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 100010

inline void readint(int &x){
  x=0;
  char c=getchar();
  while(c>'9' || c<'0')c=getchar();
  while('0'<=c && c<='9'){
    x=x*10+c-'0';
    c=getchar();
  }
}

int MOD;

int a[N][110],c[N],ansx,n,m,times=1,x[N],xt[N],y[N],mod[3000010];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d%d",&n,&m,&MOD);
  REP(i,1,3000000){
    mod[i]=mod[i-1]+1;
    if(mod[i]==MOD)mod[i]=0;
  }
  REP(i,1,n){
    int *it=a[i];
    REP(j,1,m){
      ++it;
      readint(*it);
      a[i][j]=mod[a[i][j]];
      if(a[i][j])c[i]++;
    }
    c[i]%=MOD;
  }
  if(MOD==2){
    while(times--){
      int sum=0;
      REP(i,1,n){
        x[i]=1;
        sum+=x[i];
      }
      sum&=1;
      memset(xt,0,sizeof(int)*(m+1));
      memset(y,0,sizeof(int)*(n+1));
      REP(j,1,n)if(x[j]){
        int *it=a[j];
        REP(i,1,m){
          ++it;
          if(*it)
            xt[i]+=x[j]**it;
        }
      }
      REP(i,1,m)xt[i]&=1;
      REP(i,1,n){
        int *it=a[i];
        REP(j,1,m){
          ++it;
          if(xt[j]&&*it)
            y[i]+=xt[j]**it;
        }
        y[i]&=1;
      }
      REP(i,1,n){
        xt[i]=(x[i]*(c[i]-1)+sum)&1;
        if(xt[i]!=y[i]){
          ansx=i;
          break;
        }
      }
      if(ansx)break;
    }
  }else{
    while(times--){
      int sum=0;
      REP(i,1,n){
        x[i]=1;
        sum+=x[i];
      }
      memset(xt,0,sizeof(int)*(m+1)*(m+1));
      memset(y,0,sizeof(int)*(n+1));
      int pos=0;
      REP(j,1,m)REP(k,1,m){
        pos++;
        REP(i,1,n)if(x[i]){
          int *it=a[i];
          if(it[j]&&it[k])
            xt[pos]+=x[i]*it[j]*it[k];
        }
        xt[pos]%=MOD;
      }
      REP(i,1,n){
        int pos=0;
        int *it=a[i];
        REP(j,1,m)REP(k,1,m){
          pos++;
          if(xt[pos]&&it[j]&&it[k])
            y[i]+=xt[pos]*it[j]*it[k];
        }
        y[i]%=MOD;
      }
      REP(i,1,n){
        xt[i]=((c[i]-1)*x[i]+sum)%MOD;
        if(xt[i]!=y[i]){
          ansx=i;
          break;
        }
      }
      if(ansx)break;
    }
  }
  if(!ansx)puts("-1 -1");
  else{
    int *t=a[ansx];
    REP(i,1,n)if(i!=ansx){
      int sum=0,*it=a[i];
      REP(j,1,m){
        ++it;
        if(t[j] && *it)
          sum+=t[j]**it;
      }
      if(sum%MOD==0){
        printf("%d %d\n",min(ansx,i),max(ansx,i));
        return 0;
      }
    }
  }
  return 0;
}
