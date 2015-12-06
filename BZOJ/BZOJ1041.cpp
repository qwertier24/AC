#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<math.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define gcd __gcd

using namespace std;

typedef long long LL;

bool check(LL a,LL b,LL c){
  return a*a+b*b==c&&gcd(a,b)==1&&a!=b;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  LL r;
  int ans=0;
  scanf("%lld",&r);
  for(LL d=1; d*d<=2*r; d++)
    if(2*r%d==0){
      for(LL a=1; a*a<=r/d; a++)
	if(check(a,(LL)sqrt(2*r/d-a*a),2*r/d)){
	  ans++;
	}
      if(d*d!=2*r)
	for(LL a=1; a*a*2<=d; a++)
	  if(check(a,(LL)sqrt(d-a*a),d))
	    ans++;
    }
  printf("%d\n",ans*4+4);
  return 0;
}
