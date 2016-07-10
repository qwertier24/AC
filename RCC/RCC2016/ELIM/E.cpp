#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<iostream>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 150010
int a[N],b[N];
int root[N];

#define SZ 12000000
int lc[SZ],rc[SZ],sz;
LL sumv[SZ];
#define mid ((l+r)>>1)
void add(int &o, int p, int l, int r, int pos, int v){
    o = ++sz;
    lc[o] = lc[p];
    rc[o] = rc[p];
    sumv[o] = sumv[p] + v;
    if(l==r)
        return;
    if(pos <= mid){
        add(lc[o],lc[p],l,mid,pos,v);
    }else{
        add(rc[o], rc[p],mid+1,r,pos,v);
    }
}
LL sum(int ro, int lo, int l, int r, LL R){
    if(!ro && !lo)
        return 0;
    if(R< b[l])
        return 0;
    if(b[r]<=R){
        return sumv[ro] - sumv[lo];
    }
    return sum(lc[ro],lc[lo],l,mid,R) + sum(rc[ro],rc[lo],mid+1,r,R);
}
int m;
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    int n, Q;
    scanf("%d%d",&n,&Q);
    FOR(i,n){
        scanf("%d",&a[i]);
        b[++m] = a[i];
    }
    sort(b+1,b+m+1);
    m = unique(b+1,b+m+1)-b-1;
    FOR(i,n)
        add(root[i], root[i-1], 1,m,lower_bound(b+1,b+m+1,a[i])-b,a[i]);
    //cout<<sum(root[n],root[1],1,m,1000)<<endl;
    FOR(i,Q){
        int l,r;
        scanf("%d%d",&l,&r);
        LL S = 0;
        while(true){
            LL newS = sum(root[r],root[l-1],1,m,S+1);
            if(newS == S)
                break;
            S = newS;
        }
        cout<<S+1<<endl;
    }
    return 0;
}
