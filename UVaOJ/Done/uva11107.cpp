#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1000000

using namespace std;

int m,n,len[110];
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
      height[0]=0;
      continue;
    }
    int j=sa[x[i]-1];
    while(s[j+k]==s[i+k])k++;
    height[x[i]]=k;
  }
}
int instr[N+10];
int mark[110],markcnt;
bool check(int L){
  memset(mark,-1,sizeof(mark));
  int last=1;
  height[n]=-1;
  Rep(i,n+1){
    //printf("%d %d\n",i,height[i]);
    if(height[i]<L){
      markcnt=0;
      for(int j=last; j<i; j++)
	if(mark[instr[sa[j]]]!=last){
	  mark[instr[sa[j]]]=last;
	  markcnt++;
	}
      if(markcnt>m/2)return true;
      last=i;
    }
  }
  return false;
}
void print(int L){
  //printf("L%d\n",L);
  memset(mark,-1,sizeof(mark)); 
  int last=0;
  height[n]=-1;
  Rep(i,n+1)
    if(height[i]<L){
      markcnt=0;
      for(int j=last; j<i; j++)
	if(mark[instr[sa[j]]]!=last){
	  mark[instr[sa[j]]]=last;
	  markcnt++;
	}
      if(markcnt>m/2){
	for(int j=sa[last]; j<sa[last]+L; j++)
	  printf("%c",s[j]);
	puts("");
      }
      last=i;
    }
}
char fillchar[110];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);  
#endif 
  int t;
  For(i,'a'-1)fillchar[++t]=i;
  for(int i='z'+1; t<=100; i++)fillchar[++t]=i;
  //printf("%d %d\n",'a','z');
  int first=1;
  while(scanf("%d",&m)&&m){
    n=0;
    if(!first)puts("");
    first=0;
    For(i,m){
      scanf("%s",s+n);
      n+=strlen(s+n)+1;
      *(s+n-1)=fillchar[i];
      *(s+n)=0;
      len[i]=n;
    }
    if(m==1){
      s[n-1]=0;
      printf("%s\n",s);
      continue;
    }
    For(i,m)
      for(int j=len[i-1]; j<len[i]; j++)
	instr[j]=i;
    calc_sa();
    calc_height();
    //Rep(i,n)printf("%d %s\n",height[i],s+sa[i]);
    int l=0,r=n;
    For(i,m)r=min(r,len[i]-len[i-1]);
    while(l<r){
      int mid=((l+r-1)>>1)+1;
      if(check(mid))l=mid;
      else r=mid-1;
    }
    if(l==0)printf("?\n");
    else print(l);
  }
  return 0;
}
