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

int Cst[1003] , Pow[1003] , A[1003] , B[1003];
vector<int> edge[1003] ;

void gao (int p)
{
    A[p] = B[p] = -Cst[p]; B[p] += Pow[p];
    for (int i = 0 ; i < edge[p].size() ; ++i)
	gao(edge[p][i]);
    vector<pair<int,int> > tmp , tmp2;
    for (int i = 0 , v ; i < edge[p].size() ; ++i) {
	v = edge[p][i];
	if (B[v] >= 0)
	    tmp.push_back(make_pair(-A[v],-B[v]));
    }
    sort(tmp.begin(),tmp.end());
    for (int i = 0 , aa , bb ; i < tmp.size() ; ++i) {
	aa = -tmp[i].first; bb = -tmp[i].second;
	A[p] = min(A[p],B[p]+aa);
	B[p] += bb;
    }
    for (int i = 0 , v ; i < edge[p].size() ; ++i) {
	v = edge[p][i];
	if (B[v] < 0)
	    tmp2.push_back(make_pair(A[v]-B[v],B[v]));
    }
    sort(tmp2.begin(),tmp2.end());
    for (int i = 0 , aa , bb ; i < tmp2.size() ; ++i) {
	bb = tmp2[i].second; aa = tmp2[i].first+bb;
	A[p] = min(A[p],B[p]+aa);
	B[p] += bb;
    }
    B[p] -= Cst[p];
    A[p] = min(A[p],B[p]);
}

bool visit[1003] ;


int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    cin >> n;
    for (int i = 1 , k , v ; i <= n ; ++i) {
	cin >> Cst[i] >> k;
	if (k == 0) cin >> Pow[i];
	else for (int j = 1 ; j <= k ; ++j) {
		cin >> v;
		edge[i].push_back(v);
		visit[v] = true;
	}
    }

    for (int i = 1 ; i <= n ; ++i)
	if (!visit[i])
	    edge[0].push_back(i);
    Cst[0] = Pow[0] = 0;
    gao(0);
    cout << -A[0] << endl;
    
    return 0;
}
close