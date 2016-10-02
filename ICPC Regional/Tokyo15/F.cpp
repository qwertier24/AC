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

int tmpL[303] , tmpN[303][303] , tmpRst[303];
int L[303] , N[303][303] , PR[200005][2];
bool visit[303] ;
int p , r;

bool check(int t)
{
    int x = 1;
    FOR(i,r) tmpL[i] = L[i];
    memset(visit,0,sizeof(visit));
    memset(tmpN,0,sizeof(tmpN));
    memset(tmpRst,0,sizeof(tmpRst));
    FOR(i,p) FOR(j,r) if (N[i][j] == tmpN[i][j]) ++tmpRst[i];
    FOR(i,t)
    {
	int P = PR[i][0], R = PR[i][1];
	if (visit[P]) continue;
	tmpL[R]--;
	tmpN[P][R]++;
	if (tmpN[P][R] >= N[P][R]) ++tmpRst[P];
	if (tmpRst[P] >= r)
	{
	    ++x;
	    FOR(k,r) tmpL[k] += tmpN[P][k] , tmpN[P][k] = 0;
	    visit[P] = true;
	}
    }
    for (; x <= p ;)
    {
	bool brk = true;
	FOR(i,p) if (!visit[i])
	{
	    bool flag = true;
	    for (int k = 1 ; flag && k <= r ; ++k)
		flag = N[i][k] - tmpN[i][k] <= tmpL[k];
	    if (flag)
	    {
		visit[i] = true;
		FOR(k,r) tmpL[k] += tmpN[i][k] , tmpN[i][k] = 0;
		brk = false;
		++x;
	    }
	}
	if (brk) break;
    }
    return x > p;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    int t;
    cin >> p >> r >> t;
    FOR(i,r) scanf("%d",L+i);
    FOR(i,p) FOR(j,r) scanf("%d",N[i]+j);
    FOR(i,t) scanf("%d%d",PR[i],PR[i]+1);
    if (check(t)) {cout << -1 << endl; return 0;}
    int low = 1 , high = t + 1 , mid;
    while (low < high)
    {
	mid = low + high >> 1;
	if (check(mid)) low = mid + 1;
	else high = mid;
    }
    cout << low << endl;
    return 0;
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | Current Style: Cerulean.

Select Style:   Fluid Width?
 