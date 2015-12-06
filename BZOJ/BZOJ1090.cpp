#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <algorithm>
#define N 110
#define INF 1000
#define For(i,n) for(int i=1; i<=n; i++)

using namespace std;

char s[N];
int d[N][N],n;
bool cmp(int p1,int p2,int len){
  int i;
  for(i=0; i<len && s[p1+i]==s[p2+i]; i++);
  return i==len; 
}
int times[N][N],numlen[N];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif
  For(i,9)numlen[i]=1;
  for(int i=10; i<100; i++)
    numlen[i]=2;
  numlen[100]=3;
  scanf("%s",s+1);
  n=strlen(s+1);
  For(i,n)
    for(int j=i; j<=n; j++){
      times[i][j]=1;
      int len=j-i+1;
      for(int k=j+1; k+len-1<=n; k+=len){
	if(cmp(k,i,len))
	  times[i][j]++;
	else
	  break;
      }
    }
  For(l,n){
    for(int i=1; i+l-1<=n; i++){
      int j=i+l-1;
      d[i][j]=l;
      for(int k=i; k<=j; k++){
	int len=k-i+1;
	int t=min(times[i][k],(j-i+1)/len);
	d[i][j]=min(min(d[i][k]+numlen[t]+2,d[i][k]*t)+d[i+t*len][j],d[i][j]);
      }
    }
  }
  printf("%d\n",d[1][n]);
  return 0;
}

