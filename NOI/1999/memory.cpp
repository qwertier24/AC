#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;

int n;

#define SZ 3000000
#define mid ((l+r)>>1)
int sumv[SZ],lc[SZ],rc[SZ],setv[SZ],maxs[SZ],maxl[SZ],maxr[SZ],sz,root;
void Set(int &o,int l,int r,int v){
  if(!o)o=++sz;
  //printf("set:%d %d %d %d\n",o,l,r,v);
  setv[o]=v;
  maxs[o]=maxl[o]=maxr[o]=sumv[o]=(r-l+1)*v;
}
void pushdown(int o,int l,int r){
  if(setv[o]!=-1){
    Set(lc[o],l,mid,setv[o]);
    Set(rc[o],mid+1,r,setv[o]);
    setv[o]=-1;
  }
}
void maintain(int o,int l,int r){
  if(setv[o]==-1){
    sumv[o]=sumv[lc[o]]+sumv[rc[o]];
    maxs[o]=max(maxr[lc[o]]+maxl[rc[o]],max(maxs[lc[o]],maxs[rc[o]]));
    maxl[o]=max(maxl[lc[o]],sumv[lc[o]]==mid-l+1?mid-l+1+maxl[rc[o]]:0);
    maxr[o]=max(maxr[rc[o]],sumv[rc[o]]==r-mid?r-mid+maxr[lc[o]]:0);
  }
}
void update(int L,int R,int v,int &o=root,int l=0,int r=n-1){
  if(L<=l && r<=R){
    Set(o,l,r,v);
    return;
  }
  pushdown(o,l,r);
  if(L<=mid)update(L,R,v,lc[o],l,mid);
  if(R>mid)update(L,R,v,rc[o],mid+1,r);
  maintain(o,l,r);
}
int find(int sz,int &o=root,int l=0,int r=n-1){
  if(setv[o]==1)return l;
  if(maxs[lc[o]]>=sz)return find(sz,lc[o],l,mid);
  //printf("l:%d r:%d maxr[lc[o]]:%d\n",l,r,maxs[o]);
  if(maxr[lc[o]]+maxl[rc[o]]>=sz)return mid-maxr[lc[o]]+1;
  return find(sz,rc[o],mid+1,r);
}

struct DEL{
  int t,L,R;
  const bool operator<(const DEL& r)const{return t>r.t;}
  DEL(int _t,int _L,int _R):t(_t),L(_L),R(_R){}
};
priority_queue<DEL> del;

struct REQ{
  int st,sz,t;
  REQ(int _st,int _sz,int _t):st(_st),sz(_sz),t(_t){}
};
queue<REQ> wait;

int main(){
  FILE* fin=fopen("memory.in","r"),*fout=fopen("memory.out","w");
  int t,sz,st,curt,ans1=-(1<<30),ans2=0;
  fscanf(fin,"%d",&n);
  Set(root,0,n-1,1);
  while(true){
    fscanf(fin,"%d%d%d",&st,&sz,&t);
    if(!st && !sz && !t)break;
    while(!del.empty() && del.top().t<st){
      update(del.top().L,del.top().R,1);
      curt=del.top().t;
      del.pop();
      if(!del.empty() && del.top().t==curt)continue;
      while(!wait.empty() && maxs[1]>=wait.front().sz){
        int L=find(wait.front().sz),R=L+wait.front().sz-1;
        update(L,R,0);
        del.push(DEL(curt+wait.front().t,L,R));
        ans1=max(ans1,curt+wait.front().t);
        wait.pop();
      }
    }
    if(maxs[1]>=sz){
      int L=find(sz),R=L+sz-1;
      update(L,R,0);
      del.push(DEL(st+t-1,L,R));
      ans1=max(ans1,st+t-1);
    }else{
      wait.push(REQ(st,sz,t));
      ans2++;
    }
  }
  while(!del.empty()){
    update(del.top().L,del.top().R,1);
    curt=del.top().t;
    del.pop();
    if(!del.empty() && del.top().t==curt)continue;
    while(!wait.empty() && maxs[root]>=wait.front().sz){
      int L=find(wait.front().sz),R=L+wait.front().sz-1;
      update(L,R,0);
      del.push(DEL(curt+wait.front().t,L,R));
      ans1=max(ans1,curt+wait.front().t);
      wait.pop();
    }
  }
  fprintf(fout,"%d\n%d",ans1+1,ans2);
  return 0;
}
