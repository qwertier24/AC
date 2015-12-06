#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 300000

using namespace std;
typedef long long LL;

int n;
char s[N+10];

int cnt[N+10],*x=new int[N+10],*y=new int[N+10],sa[N+10];
void calc_sa(){
  int m=256;
  Rep(i,m)cnt[i]=0;
  Rep(i,n)cnt[x[i]=s[i]]++;
  For(i,m-1)cnt[i]+=cnt[i-1];
  Rep(i,n)sa[--cnt[x[i]]]=i;
  for(int k=1; k<=n; k<<=1){
    int p=0;
    for(int i=n-k; i<n; i++)y[p++]=i;
    Rep(i,n)if(sa[i]>=k)y[p++]=sa[i]-k;

    Rep(i,m)cnt[i]=0;
    Rep(i,n)cnt[x[y[i]]]++;
    For(i,m-1)cnt[i]+=cnt[i-1];
    for(int i=n-1; i>0; i--)sa[--cnt[x[y[i]]]]=y[i];
    
    swap(x,y);
    x[sa[0]]=0;
    p=1;
    For(i,n-1){
      if(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])
	x[sa[i]]=p-1;
      else 
	x[sa[i]]=p++;
    }
    if(p>=n)break;
    m=p;
  }
}
int height[N+10];
void calc_height(){
  int k=0;
  Rep(i,n){
    if(k)k--;
    if(x[i]==0){
      height[x[i]]=0;
      continue;
    }
    int j=sa[x[i]-1];
    while(s[j+k]==s[i+k])k++;
    height[x[i]]=k;
  }
}
struct Node{
  int h,cnt;
  void init(int a,int b){
    h=a,cnt=b;
  }
}st[N+10];
int top,k,len1;
LL calc_ans(int p){
  LL sum=0,ret=0;
  top=0;
  Rep(i,n){
    if(height[i]<k){
      //printf("break:%s\n",s+sa[i]);
      top=sum=0;
      continue;
    }
    int cnt=0;
    if((sa[i-1]<len1)!=p)cnt=1;
    while(top&&st[top].h>=height[i]){
      sum-=st[top].cnt*((LL)st[top].h-k+1);
      cnt+=st[top].cnt;
      top--;
    }
    sum+=cnt*(LL)(height[i]-k+1);
    if(cnt)st[++top].init(height[i],cnt);
    if((sa[i]<len1)==p)ret+=sum;
    //printf("%d %s %lld\n",height[i],s+sa[i],sum);
  }
  return ret;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  while(scanf("%d",&k)&&k){
    scanf("%s",s);
    len1=strlen(s);
    *(s+len1)='?';
    len1++;
    scanf("%s",s+len1);
    n=len1+strlen(s+len1);
    calc_sa();
    calc_height();
    
    printf("%lld\n",calc_ans(0)+calc_ans(1));
  }
  return 0;
}
