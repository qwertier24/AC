#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 50
#define MOD 10000

using namespace std;
typedef long long LL;

int n;
struct Mat{
  int num[50][50];
  Mat operator*(Mat &r){
    Mat ret;
    Rep(i,n)Rep(j,n)Rep(k,n)
      ret[i][j]=(ret[i][j]+num[i][k]*r[k][j])%MOD;
    return ret;
  }
  int* operator[](int x){
    return num[x];
  }
  void init(){
    Rep(i,n)num[i][i]=1;
  }
  Mat(){memset(num,0,sizeof(num));}
}matd[13],mata;
Mat fPow(Mat t,int p){
  Mat ret;
  ret.init();
  while(p){
    if(p&1)ret=ret*t;
    t=t*t;
    p>>=1;
  }
  return ret;
}

int m,st,ed,en;

LL k;

int g[N][N],mark[N][N];

int pos[N][20];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d%d%I64d",&n,&en,&st,&ed,&k);
  For(i,en){
    int u,v;
    scanf("%d%d",&u,&v);
    g[u][v]=g[v][u]=1;
  }

  scanf("%d",&m);
  For(i,m){
    int T;
    scanf("%d",&T);
    Rep(j,T){
      scanf("%d",&pos[i][j]);
      for(int p=j+T; p<=12; p+=T)
	pos[i][p]=pos[i][j];
    }
    For(j,12)
      mark[j][pos[i][j]]=1;
  }

  mata.init();
  For(p,12){
    Mat &mat=matd[p];
    Rep(i,n){
      Rep(j,n)
	if(g[i][j]&&!mark[p][i])
	  mat[j][i]=1;
    }
    mata=mata*mat;
  }
  
  mata=fPow(mata,k/12);
  For(i,k%12)
    mata=mata*matd[i];
  printf("%d\n",mata[st][ed]);
  return 0;
}
