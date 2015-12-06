#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;

const int m=4;
int n;
char chr[m]={'W','I','N','G'},s[220];
int meth[m],Div[m][16][2],d[220][220][m];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  Rep(i,m)scanf("%d",&meth[i]);
  Rep(i,m)Rep(j,meth[i]){
    scanf("%s",s);
    Rep(k,2)Rep(l,4)if(s[k]==chr[l])
      Div[i][j][k]=l;
  }
  scanf("%s",s);
  n=strlen(s);
  Rep(i,n)Rep(j,m)if(chr[j]==s[i])d[i][i][j]=1;
  int found;
  for(int len=2; len<=n; len++)
    Rep(l,n-len+1){
      int r=l+len-1;
      Rep(i,m){
	found=0;
	Rep(j,meth[i]){
	  for(int mid=l; mid<r; mid++)
	    if(d[l][mid][Div[i][j][0]]&&d[mid+1][r][Div[i][j][1]]){
	      d[l][r][i]=1;
	      found=true;
	      break;
	    }
	  if(found)break;
	}
      }
    }
  int flag=0;
  Rep(i,m)if(d[0][n-1][i]){
    flag=1;
    printf("%c",chr[i]);
  }
  if(!flag)printf("The name is wrong!");
  return 0;
}
