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

#define N 200010
#define M 200000


#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
LL sumv[N<<2];
int maxv[N<<2], setv[N<<2];
void Set(int o, int l,int r, int v){
    sumv[o] = (r-l+1)*(LL)v;
    maxv[o] = v;
    setv[o] = v;
}
void pushdown(int o, int l, int r){
    if(setv[o] != -1){
        Set(lc, l, mid, setv[o]);
        Set(rc, mid+1, r, setv[o]);
        setv[o] = -1;
    }
}
void maintain(int o, int l, int r){
    if(setv[o] == -1){
        sumv[o] = sumv[lc] + sumv[rc];
        maxv[o] = max(maxv[lc], maxv[rc]);
    }else{
        sumv[o] = setv[o] * LL(r - l +1);
        maxv[o] = setv[o];
    }
}

int find(int o, int l, int r, int v){
    if(maxv[o] < v)
        return r + 1;
    if(l == r)
        return l;
    pushdown(o,l,r);
    if(maxv[lc] >= v)
        return find(lc, l, mid, v);
    else
        return find(rc, mid+1 , r, v);
}

void modify(int o, int l, int r, int L, int R, int v){
    if(R<L)
        return;
    if(L<=l && r<=R){
        Set(o,l,r,v);
        return;
    }
    pushdown(o,l,r);
    if(L<=mid)
        modify(lc,l,mid,L,R,v);
    if(R>mid)
        modify(rc, mid+1, r, L,R,v);
    maintain(o,l,r);
}

int query(int o,int l,int r,int p){
    if(l==r)
        return maxv[o];
    pushdown(o,l,r);
    if(p<=mid)
        return query(lc,l,mid,p);
    else
        return query(rc,mid+1,r,p);
}

int n;
void maximize(int L, int R, int v){
    int r = find(1,1,n,v);
    modify(1,1,n,L,r-1,v);
}

int pos[M+10],a[N];
vector<int> v[N];
LL H[N];
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    scanf("%d",&n);
    FOR(i,n){
        scanf("%d",&a[i]);
        pos[a[i]] = i;
    }
    FOR(i,M)
        for(int j = i; j <= M; j+=i)
            if(pos[j])
                v[i].push_back(pos[j]);
    memset(setv, -1, sizeof(setv));
    FOR(i,n)
        modify(1,1,n,i,i,i);
    LL ans = 0;
    for(int i = M; i>=0; i--){
        H[i] = n*(LL)(n+1) - sumv[1];
        if(v[i].size() < 2)
            continue;
        sort(v[i].begin(),v[i].end());
        maximize(1, v[i][0], v[i][v[i].size()-2]);
        maximize(v[i][0]+1, v[i][1], v[i][v[i].size()-1]);
        maximize(v[i][1]+1, n, n+1);
    }
    FOR(i,M)
        ans += i * (H[i] - H[i-1]);
    cout<<ans;
    return 0;
}
