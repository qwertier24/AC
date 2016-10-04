#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, n) for(int i = 1; i <= n; i++)

typedef long long ll;
typedef pair<int,int> pii;
#define first fi
#define second se

#ifdef LOCAL
#define err(x) cerr << #x << ":" << x << endl
#else
#define err(x)
#endif
int p[50500];
struct pri{
    int dis,pri;
}pr[50050];
int cnt,n,t;
int ti[50500];
int minn[50500 * 8];
int setn[50500 * 8];
void build(int o, int l, int r){
    if (l == r){
        minn[o] = (1 << 30);
        setn[o] = (1 << 30);
        return;
    }
    int mid = (l + r) >> 1;
    build(o * 2, l, mid);
    build(o * 2 + 1, mid + 1, r);
    minn[o] = (1 << 30);
    setn[o] = (1 << 30);
}
void pset(int o, int v){
    setn[o] = min(setn[o],v);
    minn[o] = min(setn[o],minn[o]);
}
void pd(int o){
    if (setn[o] == (1 << 30)) return;
    pset(o * 2, setn[o]);
    pset(o * 2 + 1, setn[o]);
    setn[o] = (1 << 30);
}
void upd(int o){
    minn[o] = min(minn[o * 2],minn[o * 2 + 1]);
}
void modify(int o, int l, int r, int ln, int rn, int v){
    if (ln <= l && r <= rn){
        pset(o, v);
        return;
    }
    pd(o);
    int mid = (l + r) >> 1;
    if (ln <= mid)
        modify(o * 2, l, mid, ln, rn, v);
    if (mid < rn)
        modify(o * 2 + 1, mid + 1, r, ln, rn, v);
    upd(o);
}
int getmin(int o, int l, int r, int p){
    if (l == r){
        return minn[o];
    }
    pd(o);
    int mid = (l + r) >> 1;
    if (p <= mid)
        return getmin(o * 2, l, mid, p);
    else return getmin(o * 2 + 1, mid + 1, r, p);
}
int check(int d){
    build(1,1,n);
    modify(1,1,n,1,1,0);
    for (int i = 1;i < n;i++){
        int cost = getmin(1,1,n,i);
        modify(1,1,n,i + 1,min(n,i + d),cost + ti[i]);
    }
    return getmin(1, 1, n, n) <= t;
}
int main() {
    freopen("journey.in","r",stdin);
    freopen("journey.out","w",stdout);
    scanf("%d%d",&n,&t);
    t -= (n - 1);
    for (int i = 1;i < n;i++)  scanf("%d",&p[i]);
    cnt = 0;
    for (int i = 1;i < n;i++){
        while (p[i] < pr[cnt].pri) cnt--;
        pr[++cnt] = (pri){i,p[i]};
    }
    for (int i = 2;i < n;i++)
        scanf("%d",&ti[i]);
    int l = 1,r = cnt,mid,ans;
    while (l <= r){
        mid = (l + r) >> 1;
        int o = check(pr[mid].dis);
        if (o)
            ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << pr[ans].pri << endl;
    return 0;
}
close