#include<stdio.h>
#include<algorithm>
#include<vector>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 510

typedef long long LL;
using namespace std;

int n;
LL sum[N];
pair<int,int> a[N];
int b[N],c[N];
bool check(int p){
  long long cnt=0;
  int j=0;
  For(i,n)if(i!=p){
    j++;
    cnt+=a[i].first;
    int rem=n-i;
    int k=lower_bound(b+1,b+rem+1,j)-b;
    long long tmp=sum[k-1]+(rem-k+1)*j+j*(j-1);
    if(p>i)tmp-=min(j,a[p].first);
    if(cnt>tmp)return false;
  }
  return cnt%2==0;
}
int main(){
  //freopen("in.txt","r",stdin);
  freopen("fcount.in","r",stdin);
  freopen("fcount.out","w",stdout);
  scanf("%d",&n);
  n++;
  For(i,n){
    scanf("%d",&a[i].first);
    a[i].second=i;
    b[i]=a[i].first;
  }
  sort(a+1,a+n+1);
  reverse(a+1,a+n+1);
  sort(b+1,b+n+1);
  For(i,n)sum[i]=sum[i-1]+b[i];
  vector<int> ans;
  For(i,n){
    if(check(i))
      ans.push_back(a[i].second);
  }
  printf("%d\n",(int)ans.size());
  sort(ans.begin(),ans.end());
  Rep(i,int(ans.size())-1)
    printf("%d\n",ans[i]);
  if(ans.size())
    printf("%d",ans[ans.size()-1]);
  return 0;

}
