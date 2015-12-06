#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#define PROB "slowdown"
#define INF 1e30
#define For(i,n) for(int i=1; i<=n; i++)

using namespace std;

vector<double> t,p;
char opt[10];
double x;
int n;
int main(){
  freopen(PROB".in","r",stdin);
  freopen(PROB".out","w",stdout);
  scanf("%d",&n);
  double curt=0,curp=0,revv=1;
  For(i,n){
    scanf("%s%lf",opt,&x);
    if(opt[0]=='T')t.push_back(x);
    else p.push_back(x);
  }
  sort(t.begin(),t.end());
  sort(p.begin(),p.end());
  int pt=0,pp=0;
  For(i,n){
    double t1=INF,t2=INF;
    if(pt<t.size()){
      t1=t[pt]-curt;
    }
    if(pp<p.size()){
      t2=(p[pp]-curp)*revv;
    }
    if(
    if(t1<t2){
      curt+=t1;
      curp+=t1/revv;
      revv++;
      pt++;
    }else{
      curt+=t2;
      curp+=t2/revv;
      revv++;
      pp++;
    }
  }
  printf("%.0f",curt+(1000-curp)*revv);
  return 0;
}
