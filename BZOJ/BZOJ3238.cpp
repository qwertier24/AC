#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<stack>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 500010
#define fi first
#define se second
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

char s[N];
int n,sa[N],*x=new int[N<<1],*y=new int[N<<1],cnt[N],m=26;
inline bool eq(int i,int j){
  return (i>=n && j>=n)||(i<n && j<n && y[i]==y[j]);
}
void calc_sa(){
  m=26;
  Rep(i,n)cnt[x[i]=s[i]]++;
  For(i,m-1)cnt[i]+=cnt[i-1];
  for(int i=n-1; i>=0; i--)sa[--cnt[x[i]]]=i;
  for(int k=1; k<=n; k<<=1){
    int p=0;
    for(int i=n-k; i<n; i++)y[p++]=i;
    Rep(i,n)if(sa[i]>=k)y[p++]=sa[i]-k;

    Rep(i,m)cnt[i]=0;
    Rep(i,n)cnt[x[y[i]]]++;
    For(i,m-1)cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--)sa[--cnt[x[y[i]]]]=y[i];

    swap(x,y);
    x[sa[0]]=0;
    p=1;
    For(i,n-1)
      x[sa[i]]=eq(sa[i],sa[i-1])&&eq(sa[i]+k,sa[i-1]+k)?p-1:p++;
    if(p>=n)break;
    m=p;
  }
}

int h[N];
void calc_hi(){
  int j,k=0;
  Rep(i,n){
    if(x[i]==0){k=0;continue;}
    if(k)k--;
    j=sa[x[i]-1];
    while(s[i+k]==s[j+k])k++;
    h[x[i]]=k;
  }
}

int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%s",s);
  n=strlen(s);
  Rep(i,n)s[i]-='a';
  calc_sa();
  Rep(i,n)s[i]+='a';
  calc_hi();
  
  stack<pii> st;
  LL sum=0,ans=0;
  For(i,n-1){
    int cnt=1;
    while(!st.empty() && st.top().fi>h[i]){
      sum-=st.top().se*(LL)st.top().fi;
      cnt+=st.top().se;
      st.pop();
    }
    sum+=cnt*(LL)h[i];
    //printf("%d %s sum:%lld cnt:%d %d\n",i,s+sa[i],sum,cnt,h[i]);
    ans+=sum;
    st.push(MP(h[i],cnt));
  }
  printf("%lld\n",n*((LL)n+1)/2*((LL)n-1)-2*ans);
  return 0;
}
