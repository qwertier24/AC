#include<stdio.h>
#include<algorithm> 
#include<iostream>
#include<string.h>
#define Rep(i,n) for(int i=0; i<n; ++i)
#define For(i,n) for(int i=1; i<=n; ++i)

typedef long long LL;
using namespace std;

LL k,n,m,MOD;
int rc;
LL ret[210][210],t[210][210],tmp[210][210];
int cnt;
void fPow2(int p){
  Rep(i,rc)ret[i][i]=1;
  while(p){
    if(p&1){
      Rep(i,rc)for(int j=i; j<rc; ++j){
        tmp[i][j]=0;
        for(int k=i; k<=j; ++k){
          cnt++;
          tmp[i][j]=(tmp[i][j]+ret[i][k]*t[k][j])%MOD;
        }
      }
      memcpy(ret,tmp,sizeof(ret));
    }
    Rep(i,rc)for(int j=i; j<rc; ++j){
      tmp[i][j]=0;
      for(int k=i; k<=j; ++k){
        cnt++;
        tmp[i][j]=(tmp[i][j]+t[i][k]*t[k][j])%MOD;
      }
    }
    memcpy(t,tmp,sizeof(t));
    p>>=1;
  }
}
LL fPow(LL t,int p){
  LL ret=1;
  while(p){
    if(p&1)ret=(ret*t)%MOD;
    t=(t*t)%MOD;
    p>>=1;
  }
  return ret;
}
int f,g[9000010];
LL ans;
int C[1010][1010];
LL a[210][210],b[210][210];
int mark[3010][3010];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  cin>>n>>m>>MOD;
  if(n<1){
    puts("0");
    return 0;
  }
  k=(m*m-3*m+3)%MOD;
  
  if(n<=100000){
    f=m*(m-1)%MOD;
    ans+=f;
    for(int i=2; i<=n; i++){
      f=f*k%MOD;
      g[i]=f*fPow(i,m)%MOD;
      ans+=g[i];
      ans%=MOD;
    }
    cout<<ans*fPow(2,m)%MOD<<endl;
  }else if(m<=200){
    ans=0;
    Rep(i,201){
      C[i][0]=1;
      For(j,i)
	   C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }
    rc=m+2;
    Rep(i,m+1){
     Rep(j,m+1)
       t[j][i]=(k*C[i][j])%MOD;
    }
    t[rc-1][rc-1]=1;
    t[rc-2][rc-1]=1;
    //t.print();
    fPow2(n);
    Rep(i,rc-1){
        ans+=ret[i][rc-1]*m%MOD*(m-1)%MOD;
        ans%=MOD;
    }
    cout<<ans*fPow(2,m)%MOD<<endl;
  }else{
    g[1]=f=m*(m-1)%MOD;
    mark[f][1]=1;
    for(int i=2; i<=n; i++){
      f=f*k%MOD;
      g[i]=f*fPow(i,m)%MOD;
      if(mark[f][i%MOD]){
        LL sum1=0,sum2=0;
        int lpos=mark[f][i%MOD];
        for(int j=1; j<=i; j++){
          sum1+=g[j];
          sum1%=MOD;
        }
        for(int j=lpos+1; j<=i; j++){
          sum2+=g[j];
          sum2%=MOD;
        }
        int loop=i-lpos;
        For(j,(n-i)%loop){
          sum1+=g[j+lpos];
          sum1%=MOD;
        }
        cout<<((n-i)/loop*sum2%MOD+sum1)%MOD*fPow(2,m)%MOD<<endl;
        return 0;
      }
      mark[f][i%MOD]=i;
    }
    LL sum=0;
    For(i,n){
      sum+=g[i];
      sum%=MOD;
    }
    cout<<sum<<endl;
  }
  return 0; 
}
