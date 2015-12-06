#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define CLR(t) memset(t,0,sizeof(t));
#define N 500000

using namespace std;

char s[N+10];
int n,cnt[N+10],sa[N+10],*x=new int[N+10],*y=new int[N+10],m=256;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%s",s);
  n=strlen(s);
  Rep(i,n)cnt[x[i]=s[i]]++;
  For(i,m-1)cnt[i]+=cnt[i-1];
  Rep(i,n)sa[--cnt[x[i]]]=i;
  for(int k=1; k<=n; k<<=1){
    int p=0;
    Rep(i,n)y[p++]=(sa[i]-k+n)%n;
    Rep(i,m)cnt[i]=0;
    Rep(i,n)cnt[x[y[i]]]++;
    For(i,m-1)cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--)sa[--cnt[x[y[i]]]]=y[i];
    swap(x,y);
    p=1;
    x[sa[0]]=0;
    For(i,n-1){
      if(y[sa[i-1]]==y[sa[i]]&&y[(sa[i-1]+k)%n]==y[(sa[i]+k)%n])
	x[sa[i]]=p-1;
      else
	x[sa[i]]=p++;
    }
    if(p>=n)break;
    m=p;
  }
  Rep(i,n)putchar(s[(sa[i]+n-1)%n]);
  return 0;
}
