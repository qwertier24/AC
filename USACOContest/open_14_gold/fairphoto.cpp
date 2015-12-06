#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<ctype.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010
#define X first
#define T second
#define zero 100000

typedef long long LL;
using namespace std;
typedef pair<int,int> Cow;
Cow a[N];

void readint(int &x){
  x=0;
  char c=getchar();
  while(!isdigit(c))c=getchar();
  while(isdigit(c)){
    x=x*10+c-'0';
    c=getchar();
  }
}

int sz,dec[N][10],hval[N];

const int pri=1000003,seed=17;
int lh[pri],ph[N],hi[N],hcnt;
void addHash(int h,int i){
  hcnt++;
  ph[hcnt]=lh[h];
  lh[h]=hcnt;
  hi[hcnt]=i;
}
bool check(int i,int j){
  For(k,sz-1)if(dec[i][k]!=dec[j][k])return false;
  return true;
}
int findHash(int h,int j){
  for(int i=lh[h]; i; i=ph[i]){
    if(check(hi[i],j))
      return hi[i];
  }
  return 100000;
}

int n,m,maxt;
int pos[10],sum[10];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#else
  freopen("fairphoto.in","r",stdin);
  freopen("fairphoto.out","w",stdout);
#endif
  readint(n);readint(m);
  For(i,n){
    readint(a[i].X);readint(a[i].T);
    maxt=max(maxt,a[i].T);
    a[i].T--;
  }
  a[100001].X=1<<30;
  sort(a+1,a+n+1);
  int ans=-1;
  Rep(j,(1<<maxt)){
    sz=0;
    Rep(i,maxt)if(1&(j>>i))pos[sz++]=i;
    if(sz<m)continue;
    int lpos=-1;
    memset(sum,0,sizeof(sum));
    memset(lh,0,sizeof(lh));
    For(i,n){
      if(!(1&(j>>a[i].T))){
        if(lpos==-1)continue;
        hcnt=0;
        for(int k=lpos; k<i; k++){
          lh[hval[k]]=0;
          sum[a[k].T]--;
        }
        lpos=-1;
        continue;
      }
      sum[a[i].T]++;
      if(lpos==-1)lpos=i;
      hval[i]=0;
      int allzero=1;
      For(k,sz-1){
        dec[i][k]=sum[pos[k]]-sum[pos[k-1]];
        if(dec[i][k])allzero=0;
        hval[i]=(hval[i]*seed+zero+dec[i][k])%pri;
      }
      if(allzero){
        ans=max(ans,a[i].X-a[lpos].X);
      }else{
        int t=findHash(hval[i],i)+1;
        ans=max(ans,a[i].X-a[t].X);
        if(t>n)addHash(hval[i],i);
      }
    }
  }
  printf("%d",ans);
  return 0;
}
