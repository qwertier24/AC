#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010
#define MP make_pair

using namespace std;
typedef long long LL;

map<pair<int,int>,int> seg;
int d[N],n;
map<pair<int,int>,int>::iterator it;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  For(i,n){
    int a,b;
    scanf("%d%d",&b,&a);
    a++;
    b=n-b;
    if(a<=b && a>0&&a<=n && b>0&&b<=n){
      seg[MP(a,b)]++;
      seg[MP(a,b)]=min(seg[MP(a,b)],b-a+1);
    }
  }
  it=seg.begin();
  For(i,n){
    d[i]=max(d[i],d[i-1]);
    while(it!=seg.end() && it->first.first==i){
      int r=it->first.second;
      d[r]=max(d[r],d[i-1]+it->second);
      it++;
    }
  }
  printf("%d\n",n-d[n]);
  return 0;
}
