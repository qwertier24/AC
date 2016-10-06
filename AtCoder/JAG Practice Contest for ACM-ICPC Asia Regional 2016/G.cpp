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


#define N 100010

int st[N], tp;

struct Point {
    int x, y;
    const bool operator<(const Point &rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
    Point operator-(Point rhs) {
        Point ret;
        ret.x = x - rhs.x;
        ret.y = y - rhs.y;
        return ret;
    }
}p[N];



ll Cross(Point p1, Point p2) {
    return p1.x * (ll)p2.y - p1.y * (ll)p2.x;
}

void proc(Point *p, int n, ll *S) {
    ll cur;

    cur = 0;
    tp = 0;
    FOR (i, n) {
        while (tp >= 2 && Cross(p[i] - p[st[tp]], p[st[tp]] - p[st[tp-1]]) >= 0) {
            cur -= Cross(p[st[tp-1]] - p[1], p[st[tp]] - p[1]);
            tp--;
        }
        st[++tp] = i;
        if (tp >= 2) {
            cur += Cross(p[st[tp-1]] - p[1], p[st[tp]] - p[1]);
        }
        S[i] += cur;
    }

    cur = 0;
    tp = 0;
    FOR (i, n) {
        while (tp >= 2 && Cross(p[i] - p[st[tp]], p[i] - p[st[tp-1]]) <= 0) {
            cur -= Cross(p[st[tp]] - p[1], p[st[tp-1]] - p[1]);
            tp--;
        }
        st[++tp] = i;
        if (tp >= 2) {
            cur += Cross(p[st[tp]] - p[1], p[st[tp-1]] - p[1]);
        }
        S[i] += cur;
    }
}


int n;
ll L[N], R[N];
int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);
    FOR (i, n) {
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    
    sort(p+1, p+n+1);

    proc(p, n, L);
    
    reverse(p + 1, p + n + 1);
    proc(p, n, R);
    reverse(p + 1, p + n + 1);
    reverse(R + 1, R + n + 1);

    ll ans = R[1];
    FOR (i, n) {
        //printf("%d %d %lld %lld\n", p[i].x, p[i].y, L[i], R[i]);
        if (p[i].x != p[i-1].x) {
            ans = min(ans, L[i-1] + R[i]);
        }
    }

    if (ans & 1) {
        printf("%lld", ans / 2 + 1);
    } else {
        printf("%lld", ans / 2);
    }
    
    return 0;
}
