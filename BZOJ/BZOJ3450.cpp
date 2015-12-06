#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 300030

typedef long long LL;
using namespace std;

int n;
char str[N];
double f[N],g[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%s",&n,str);
  Rep(i,n){
    switch(str[i]){
    case 'o':
      f[i]=f[i-1]+g[i-1]*2+1;
      g[i]=g[i-1]+1;
      break;
    case 'x':
      f[i]=f[i-1];
      g[i]=0;
      break;
    case '?':
      f[i]=f[i-1]+g[i-1]+0.5;
      g[i]=(g[i-1]+1)/2;
      break;
    }
    //printf("%f %f\n",g[i],f[i]);
  }
  printf("%.4f\n",f[n-1]);
  return 0;
}
