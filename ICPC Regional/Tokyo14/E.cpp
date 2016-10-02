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


/*
  N = 0
  E = 1
  S = 2
  W = 3
*/

struct Point
{
    int x , y , f;
    Point (int xx , int yy , int ff) : x(xx) , y(yy) , f(ff) {}
    bool operator < (const Point& P) const
    {
	if (x < P.x) return true;
	if (x > P.x) return false;
	if (y < P.y) return true;
	if (y > P.y) return false;
	return f < P.f;
    }
};
set<Point> meow[52][52][4][11][4];
bool MAP[52][52][4] , ANS[52][52];
const int nxt[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
char tmpC[233];

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    
    int n , x0 , y0 , t;
    cin >> n >> x0 >> y0 >> t;
    for (int i = 1 , xs , ys , xe , ye; i <= n ; ++i) {
	cin >> xs >> ys >> xe >> ye;
	if (xe < xs) swap(xs,xe);
	if (ye < ys) swap(ys,ye);
	for (int j = xs ; j < xe ; ++j)
	    MAP[j][ys][1] = true;
	for (int j = xs + 1 ; j <= xe ; ++j)
	    MAP[j][ys][3] = true;
	for (int j = ys ; j < ye ; ++j)
	    MAP[xs][j][0] = true;
	for (int j = ys + 1 ; j <= ye ; ++j)
	    MAP[xs][j][2] = true;
    }
    for (int i = 0 ; i <= 50 ; ++i)
	for (int j = 0 ; j <= 50 ; ++j)
	    for (int k = 0 ; k < 4 ; ++k)
		if (MAP[i][j][k])
		    for (int p = 0 ; p < 4 ; ++p)
			if (MAP[i-nxt[p][0]][j-nxt[p][1]][p])
			    meow[i][j][k][0][p].insert(Point(i,j,k));
    for (int i = 0 ; i <= 50 ; ++i)
	for (int j = 0 ; j <= 50 ; ++j)
	    for (int k = 0 ; k < 4 ; ++k)
		if (MAP[i][j][k])
		    for (int a = 0 ; a < 4 ; ++a)
			if (a != k+2 && a != k-2 && MAP[i+nxt[k][0]][j+nxt[k][1]][a])
			    meow[i][j][k][1][k].insert(Point(i+nxt[k][0],j+nxt[k][1],a));
    for (int x = 2 ; x <= 10 ; ++x)
	for (int i = 0 ; i <= 50 ; ++i)
	    for (int j = 0 ; j <= 50 ; ++j)
		for (int k = 0 ; k < 4 ; ++k)
		    if (MAP[i][j][k]) {
			for (int p = 0 ; p < 4 ; ++p)
			    for (int a = 0 ; a < 4 ; ++a)
				if (k != a + 2 && k != a - 2) {
				    set<Point>::iterator bg = meow[i+nxt[k][0]][j+nxt[k][1]][a][x-1][p].begin() , ed = meow[i+nxt[k][0]][j+nxt[k][1]][a][x-1][p].end();
				    for (set<Point>::iterator it = bg ; it != ed ; ++it)
					meow[i][j][k][x][p].insert(*it);
				}
		    }

    set<Point> S[2];
    for (int k = 0 ; k < 4 ; ++k)
	S[0].insert(Point(x0,y0,k));
    for (int tim = 0 ; tim < t ; ++tim) {
	S[(tim+1)&1].clear();
	int len , fac;
	cin >> len >> tmpC;
	if (tmpC[0] == 'N') fac = 0;
	else if (tmpC[0] == 'E') fac = 1;
	else if (tmpC[0] == 'S') fac = 2;
	else fac = 3;
	for (set<Point>::iterator it = S[tim&1].begin() ; it != S[tim&1].end() ; ++it) {
	    for (int p = 0 ; p < 4 ; ++p) {
		set<Point>::iterator bg = meow[it->x][it->y][it->f][len][p].begin() , ed = meow[it->x][it->y][it->f][len][p].end();
		for (set<Point>::iterator it2 = bg ; it2 != ed ; ++it2)
		    if (p == fac || it2 -> f == fac)
			S[(tim+1)&1].insert(*it2);
	    }
	}
    }


    for (set<Point>::iterator it = S[t&1].begin() ; it != S[t&1].end() ; ++it)
	ANS[it->x][it->y] = true;
    for (int x = 0 ; x <= 50 ; ++x)
	for (int y = 0 ; y <= 50 ; ++y)
	    if (ANS[x][y]) cout << x << ' ' << y << endl;

    return 0;
}
close