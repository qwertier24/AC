#include<stdio.h>
#include<algorithm>
#include<string.h>
#define N 100000
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define A 1000001
#define print(t) printf("f:%d top:%d down:%d size:%d\n",t,top[t],down[t],size[t]);

using namespace std;

inline int lowbit(int x){
  return x&(-x);
}
struct FenwickTree{
  int sum[1000000+10];
  void Init(){
    memset(sum,0,sizeof(sum));
  }
  void add(int p,int d){
    while(p<=A){
      sum[p]+=d;
      p+=lowbit(p);
    }
  }
  int get(int p){
    int ret=0;
    while(p){
      ret+=sum[p];
      p-=lowbit(p);
    }
    return ret;
  }
  void Add(int l,int r,int d){
    add(l,d);
    add(r+1,-d);
  }
}tree,tree2;

int pa[N+10],size[N+10],top[N+10],down[N+10];
int findset(int x){
  if(pa[x]!=x)pa[x]=findset(pa[x]);
  return pa[x];
}
void Union(int x,int y){
  if(x==y)return;
  if(size[x]>size[y])swap(x,y);
  size[y]+=size[x];
  top[y]=max(top[x],top[y]);
  down[y]=min(down[x],down[y]);
  pa[x]=y;
}

int x[N+10],y[N+10];
int n,m;
int a,b;
double c;
char opt[10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
    tree.Init();
    tree2.Init();
    scanf("%d",&n);
    Rep(i,n){
      scanf("%d%d",&x[i],&y[i]);
      pa[i]=i;
      top[i]=y[i],down[i]=y[i],size[i]=1;
    }
    scanf("%d",&m);
    For(i,m){
      scanf("%s",opt);
      if(opt[0]=='r'){
	scanf("%d%d",&a,&b);
	int fa=findset(a),fb=findset(b);
	if(fa!=fb){
	  tree.Add(down[fa]+1,top[fa],-size[fa]);
	  tree2.Add(down[fa]+1,top[fa],-1);
	  tree.Add(down[fb]+1,top[fb],-size[fb]);
	  tree2.Add(down[fb]+1,top[fb],-1);
	  Union(fa,fb);
	  fa=findset(fa);
	  tree.Add(down[fa]+1,top[fa],size[fa]);
	  tree2.Add(down[fa]+1,top[fa],1);
	}
      }else{
	scanf("%lf",&c);
	printf("%d %d\n",tree2.get(int(c)+1),tree.get(int(c)+1));
      }
    }
  }
  return 0;
}
