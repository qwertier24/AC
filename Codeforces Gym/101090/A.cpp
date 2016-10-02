#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, n) for(int i = 1; i <= n; i++)

typedef long long ll;
typedef pair<int,int> pii;


#ifdef LOCAL
#define err(x) cerr << #x << ":" << x << endl
#else
#define err(x)
#endif

struct Point
{
    ll x , y , num;
    bool operator < (const Point& P) const
    {
	return x * (P.y + 1e-5)  < P.x * (y + 1e-5);
    }
}Arr[15555];

vector<pair<int,pii> > ans;

bool zuozhuan (Point& p1 , Point& p2 , Point& p3)
{
    ll x1 = p2.x - p1.x , x2 = p3.x - p2.x , y1 = p2.y - p1.y , y2 = p3.y - p2.y;
    return x1*y2-x2*y1 > 0;
}

int st[15555] , maxst ;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n , base;
    cin >> n;
    for (int i = 0 ; i < n ; ++i) {
	cin >> Arr[i].x >> Arr[i].y;
	Arr[i].num=i+1;
    }
    int miny = 0;
    for (int i = 0 ; i < n ; ++i)
	if (Arr[i].y < Arr[miny].y)
	    miny = i;
    for (int i = 0 ; i < n ; ++i)
	if (i != miny)
	    Arr[i].x -= Arr[miny].x , Arr[i].y -= Arr[miny].y;
    base = Arr[miny].num;
    Arr[miny] = Arr[n-1];
    sort(Arr,Arr+n-1);
    for (int i = 1 ; i < n - 1 ; ++i)
	ans.push_back(make_pair(base,make_pair(Arr[i].num,Arr[i-1].num)));

    maxst = 0;
    for (int i = 0 ; i < n - 1 ; ++i) {
	while (maxst > 1 && zuozhuan(Arr[st[maxst-2]],Arr[st[maxst-1]],Arr[i])) {
	    ans.push_back(make_pair(Arr[st[maxst-2]].num,make_pair(Arr[st[maxst-1]].num,Arr[i].num)));
	    --maxst;
	}
	st[maxst++] = i;
    }
    cout << ans.size() << endl;
    for (int i = 0 ; i < ans.size() ; ++i)
	cout << ans[i].first << ' ' << ans[i].second.first << ' ' << ans[i].second.second << endl;
    return 0;
}
close