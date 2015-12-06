#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;

#define N 200010

char s[N];
int cnt[N],*x=new int[N],*y=new int[N],n,sa[N];
#define check(a,b) ((a>=n&&b>=n) || (a<n&&b<n&&y[a]==y[b]))
void calc_sa(){
  int m=256;
  for(int i=0; i<n; i++)cnt[x[i]=s[i]]++;
  for(int i=1; i<m; i++)cnt[i]+=cnt[i-1];
  for(int i=n-1; i>=0; i--)sa[--cnt[x[i]]]=i;
  for(int k=1; k<=n; k<<=1){
    int p=0;
    for(int i=n-k; i<n; i++)y[p++]=i;
    for(int i=0; i<n; i++)if(sa[i]>=k)y[p++]=sa[i]-k;
    
    for(int i=0; i<m; i++)cnt[i]=0;
    for(int i=0; i<n; i++)cnt[x[y[i]]]++;
    for(int i=1; i<m; i++)cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--)sa[--cnt[x[y[i]]]]=y[i];
    
    swap(x,y);
    p=1;
    x[sa[0]]=0;
    for(int i=1; i<n; i++)
      x[sa[i]]=(check(sa[i],sa[i-1]) && check(sa[i]+k,sa[i-1]+k))?p-1:p++;
    m=p;
    if(m>=n)break;
  }
}

int hi[N];
void calc_hi(){
  int j,k=0;
  for(int i=0; i<n; i++){
    if(x[i]==0){k=0;hi[x[i]]=0;continue;}
    if(k)k--;
    j=sa[x[i]-1];
    while(s[j+k]==s[i+k])k++;
    hi[x[i]]=k;
  }
}

struct Query{int l,t;}q[500010];
vector<int> qv[N];
vector<int> hv[N];

int sz[N],pa[N];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}
void unionSet(int l,int r){
  cnt[sz[findset(l)]]--;
  cnt[sz[findset(r)]]--;
  sz[pa[l]]+=sz[pa[r]];
  cnt[sz[pa[l]]]++;
  pa[pa[r]]=pa[l];
}
int ans[500010];

int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%s",s);
  n=strlen(s);
  calc_sa();
  calc_hi();
  int Q;
  scanf("%d",&Q);
  REP(i,n){
    pa[i]=i;
    sz[i]=1;
    hv[hi[i]].push_back(i);
    //printf("%d %d %s\n",i,hi[i],s+sa[i]);
  }
  memset(cnt,0,sizeof(cnt));
  FOR(i,Q){
    scanf("%d%d",&q[i].l,&q[i].t);
    qv[q[i].l].push_back(i);
  }
  for(int j=n; j; j--){
    cnt[1]++;
    REP(k,hv[j].size()){
      //printf("union:%d %d\n",j,hv[j][k]);
      unionSet(hv[j][k]-1,hv[j][k]);
    }
    //REP(i,n)printf("%d %d %d\n",i,L[i],R[i]);
    //FOR(i,n)if(cnt[i])printf("%d %d\n",i,cnt[i]);
    //REP(i,n)printf("%d\n",sz[findset(L,i)]);
    //puts("");
    REP(k,qv[j].size()){
      int &i=qv[j][k];
      ans[i]=cnt[q[i].t];
    }
  }
  FOR(i,Q)printf("%d\n",ans[i]);
  return 0;
}
