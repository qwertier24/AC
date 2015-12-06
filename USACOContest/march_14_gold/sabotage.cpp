#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010
#define zero 100000ll
#define MP make_pair

typedef long long LL;
using namespace std;

int n;
long long a[N];
bool check(int avg){
  stack<pair<int,long long > > st;
  long long sum=0;
  for(int i=n; i>2; --i){
    sum+=a[i]-avg;
    if(st.empty() || st.top().second>sum)
      st.push(MP(i,sum));
  }
  sum=0;
  For(i,n-2){
    sum+=a[i]-avg;
    while(!st.empty() && st.top().first<=i+1)st.pop();
    if(!st.empty() && st.top().second+sum<=0)return true;
  }
  return false;
}
int main(){
  freopen("sabotage.in","r",stdin);
  freopen("sabotage.out","w",stdout);
  scanf("%d",&n);
  For(i,n){
    cin>>a[i];
    a[i]*=zero;
  }
  LL low=1*zero,high=10000*zero;
  while(low<high){
    int mid=(low+high)>>1;
    if(check(mid))high=mid;
    else low=mid+1;
  }
  printf("%.3f\n",low/(double)zero);
  return 0;
}
