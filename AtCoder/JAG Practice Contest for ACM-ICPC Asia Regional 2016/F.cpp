#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, n) for(int i = 1; i <= n; i++)

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second

#ifdef LOCAL
#define err(x) cerr << #x << ":" << x << endl
#else
#define err(x)
#endif
pii a[100100];
long long sum[100100];
long long maxn[1001000],minn[1001000],addv[1001000],addc[1001000];
int c[1001000];
int n,L;
int cmp(const pii & a, const pii & b){
    return a.fi - a.se > b.fi - b.se;
}
void upd(int o){
    maxn[o] = max(maxn[o * 2], maxn[o * 2 + 1]);
    minn[o] = min(minn[o * 2], minn[o * 2 + 1]);
}
void setc(int o, int d){
    minn[o] += d;
    addc[o] += d;
}
void setv(int o, int d){
    maxn[o] += d;
    minn[o] += d;
    addv[o] += d;
}
void pd(int o){
    if (addc[o]){
        setc(o * 2, addc[o]), setc(o * 2 + 1, addc[o]);
        addc[o] = 0;
    }
    if (addv[o]){
        setv(o * 2, addv[o]), setv(o * 2 + 1, addv[o]);
        addv[o] = 0;
    }
}
void modify(int o, int l, int r, int ln, int rn, int d, int flag){
    if (ln <= l && r <= rn){
        if (flag){
            setc(o, d);
        }else {
            setv(o,d);
        }
        return ;
    }
    pd(o);
    int mid = (l + r) >> 1;
    if (ln <= mid)
        modify(o * 2, l, mid, ln, rn, d, flag);
    if (mid < rn)
        modify(o * 2 + 1, mid + 1, r, ln, rn, d, flag);
    upd(o);
    
}
int find(int o, int l, int r, int bound){
    if (l == r){
        if (maxn[o] >= bound)
            return l;
        else return (1 << 30);
    }
    pd(o);
    int mid = (l + r) >> 1;
    if (maxn[o * 2] >= bound)
        return min(mid,find(o * 2, l, mid, bound));
    else return find(o * 2 + 1, mid + 1, r, bound);
}
long long check(int o, int l, int r, int ln, int rn){
    if (ln <= l && r <= rn){
        return minn[o];
    }
    pd(o);
    int mid = (l + r) >> 1;
    long long ans = (1LL << 60);
    if (ln <= mid)
        ans = min(ans, check(o * 2, l, mid, ln, rn));
    if (mid < rn)
        ans = min(ans, check(o * 2 + 1, mid + 1, r, ln, rn));
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].fi, &a[i].se);
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i].fi - a[i].se;
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 1; i < n; i++)
        modify(1, 1, n - 1, i, n - 1, max(a[i + 1].fi - a[i + 1].se, 0), 0);
    for (int i = 1; i < n; i++)
        modify(1, 1, n - 1, i, n - 1, -c[i], 1);
    int ans = (1 << 30);

    for (int i = 1; i <= n; i++)
        if (a[i].fi >= L) ans = 1;
    
    int pos = find(1, 1, n - 1, L - a[1].fi);
    if (pos != (1 << 30) && check(1, 1, n - 1, 1, pos) > 0)
        ans = min(ans, pos + 1);

    for (int i = 2; i <= n; i++){
        modify(1, 1, n - 1, i - 1, n - 1, min(a[i].se - a[i].fi, 0), 0);
        modify(1, 1, n - 1, i - 1, n - 1, max(a[i - 1].fi - a[i - 1].se, 0), 0);
        pos = find(1, 1, n - 1, L - a[i].fi);
        if (pos != (1 << 30) && check(1, 1, n - 1, 1, pos) > 0)
            ans = min(ans, pos + 1);
    }
    if (ans == (1 << 30))
        printf("-1\n");
    else
        printf("%d\n",ans);
    return 0;
}
