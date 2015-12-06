#include<stdio.h>
#define For(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
#define N 1000010

#define cross(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define sqr(x) ((x)*(x))
int n,q[N],fr,rr;
LL s[N],f[N],x[N],y[N],a,b,c;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%lld%lld%lld",&n,&a,&b,&c);
  For(i,n){
    scanf("%lld",&x[i]);
    s[i]=s[i-1]+x[i];
    while(fr<rr && cross(x[q[fr+1]]-x[q[fr]],y[q[fr+1]]-y[q[fr]],1,2*a*s[i])<0)
      fr++;
    f[i]=a*sqr(s[i]-s[q[fr]])+b*(s[i]-s[q[fr]])+c+f[q[fr]];
    x[i]=s[i];
    y[i]=a*sqr(s[i])-b*s[i]+f[i];
    while(fr<rr && cross(x[i]-x[q[rr]],y[i]-y[q[rr]],x[i]-x[q[rr-1]],y[i]-y[q[rr-1]])<0)
      rr--;
    q[++rr]=i;
  }
  printf("%lld\n",f[n]);
  return 0;
}
