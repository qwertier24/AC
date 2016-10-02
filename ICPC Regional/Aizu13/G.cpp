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
struct node{
    int x,y,z;
}d[311111];
int cmp(const node & a,const node & b){
    if (a.z != b.z) return a.z < b.z;
    if (b.x != b.x) return a.x > b.x;
    return a.y > b.y;
}
int a,b,C,M;
int r(){
    a = 36969 * (a & M) + (a >> 16);
    b = 18000 * (b & M) + (b >> 16);
    return (C & ((a << 16) + b)) % 1000000;
}
map<int,int> lis[300010];
int len;
typedef map<int,int>::iterator poi;
int ok(int p,int x,int y){
    if (lis[p].empty()) return true;
    poi i = lis[p].lower_bound(x);
    if (i == lis[p].begin()) return false;
    --i;
    if (i->se >= y) return false;
    return true;
}
void add(int p,int x,int y){
    if (!lis[p].empty()){
        poi i = lis[p].lower_bound(x),j = i;--j;
        if (i != lis[p].end() && (i->fi == x && i->se <= y)) return;
        if (i != lis[p].begin() && (j->se == y)) return;
        j = i;
        while ((j != lis[p].end()) && (j->se >= y)) ++j;
        lis[p].erase(i,j);
    }
    lis[p][x] = y;
}
int insert(int x,int y){
    if (ok(len,x,y)){
        return len + 1;
        //add(++len,x,y);return;
    }
    int l = 0,r = len,mid,ans = 0;
    while (l < r){
        mid = (l+r) >> 1;
        if (ok(mid,x,y)) ans = max(ans,mid),l = mid+1;
        else r = mid;
    }
    if (ans + 1 <= len && !ok(ans+1,x,y))
        //add(ans+1,x,y);
        return ans + 1;
    return -1;
}
int m,n,A,B;
int inpos[303000];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d%d%d",&m,&n,&A,&B),m|n|A|B){
        for (int i = 1;i <= m;i++)
            scanf("%d%d%d",&d[i].x,&d[i].y,&d[i].z);
        a = A,b = B,C = ~(1 << 31), M = (1 << 16) - 1;
        for (int i = m + 1;i <= n + m;i++){
            d[i].x = r(),d[i].y = r(),d[i].z = r();
        }
        n = n + m;
        sort(d + 1,d + n + 1,cmp);
        for (int i = 1;i <= n;i++){
            int j = i;
            while (j < n && d[j + 1].z == d[j].z) j++;
            for (int k = i;k <= j;k++)
                inpos[k] = insert(d[k].x,d[k].y);
            for (int k = i;k <= j;k++){
                if (inpos[k] > len) len++;
                if (inpos[k] == -1) continue;
                add(inpos[k],d[k].x,d[k].y);
            }
            i = j;
        }
        printf("%d\n",len);
        for (int i = 1;i <= len;i++)
            lis[i].clear();
        len = 0;
    }
    
    return 0;
}