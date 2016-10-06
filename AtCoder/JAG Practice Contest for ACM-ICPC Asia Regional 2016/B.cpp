#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, n) for(int i = 1; i <= n; i++)

typedef long long ll;
typedef long long LL;
typedef pair<int,int> pii;


#ifdef LOCAL
#define err(x) cerr << #x << ":" << x << endl
#else
#define err(x)
#endif

char Map[233][233] ;
int len[233][233] ;

int main() {
    int h , w , sx , sy , ans1 , ans2;
    cin >> h >> w;
    memset(len,0x3f,sizeof(len));
    FOR(i,h) scanf("%s",Map[i]+1);
    FOR(i,h) FOR(j,w) if (Map[i][j] == '%')
        sx = i , sy = j;
    ans2 = 0x3f3f3f3f;

    queue<pii> Que;Que.push(make_pair(sx,sy));
    len[sx][sy] = 0;
    
    while (!Que.empty()) {
        int tmpx = Que.front().first , tmpy = Que.front().second ; Que.pop();
        if (tmpx > 1 && Map[tmpx-1][tmpy] != '#' && len[tmpx-1][tmpy] > len[tmpx][tmpy] + 1) {
            len[tmpx-1][tmpy] = len[tmpx][tmpy] + 1;
            Que.push(make_pair(tmpx-1,tmpy));
        }
        if (tmpx < h && Map[tmpx+1][tmpy] != '#' && len[tmpx+1][tmpy] > len[tmpx][tmpy] + 1) {
            len[tmpx+1][tmpy] = len[tmpx][tmpy] + 1;
            Que.push(make_pair(tmpx+1,tmpy));
        }
        if (tmpy > 1 && Map[tmpx][tmpy-1] != '#' && len[tmpx][tmpy-1] > len[tmpx][tmpy] + 1) {
            len[tmpx][tmpy-1] = len[tmpx][tmpy] + 1;
            Que.push(make_pair(tmpx,tmpy-1));
        }
        if (tmpy < w && Map[tmpx][tmpy+1] != '#' && len[tmpx][tmpy+1] > len[tmpx][tmpy] + 1) {
            len[tmpx][tmpy+1] = len[tmpx][tmpy] + 1;
            Que.push(make_pair(tmpx,tmpy+1));
        }
    }
    FOR(i,h) FOR(j,w) {
        if (Map[i][j] == '@') ans1 = len[i][j];
        if (Map[i][j] == '$') ans2 = min(ans2,len[i][j]);
    }
    cout << (ans1 < ans2 ? "Yes" : "No") << endl;
    
    return 0;
}
