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

ll pw[10] ;

struct node
{
    int A[9] ;int hs ;
    bool operator < (const node& d) const {
        return hs < d.hs;
    }
    void hash () {
        hs = 0;
        REP(i,9)
            hs = hs * 10 + A[i];
    }
    void ch (int a , int b)
    {
        hs = hs - pw[8-a]*A[a] - pw[8-b]*A[b] + pw[8-a]*A[b] + pw[8-b]*A[a];
        swap(A[a],A[b]);
    }
}s,t,tmp;


priority_queue<pair<int,int> > pq;
const int Arr[9][4] = {{1,8,3,6},                   \
                       {0,2,4,7},                   \
                       {1,3,5,8},                   \
                       {2,4,0,6},                   \
                       {3,5,1,7},                   \
                       {4,6,2,8},                   \
                       {5,7,0,3},                   \
                       {6,8,1,4},                   \
                       {0,7,2,5}};

map<node,int> hs;
int EDGE[366666][4] ;
int maxnode = 0;
bool init_visit[100] ;
void dfs1 (int a)
{
    if (a > 8) {
        tmp.hash();
        hs[tmp] = maxnode++;
    }
    else {
        REP(i,9) if (!init_visit[i]) {
            init_visit[i] = true;
            tmp.A[a] = i;
            dfs1(a+1);
            init_visit[i] = false;
        }
    }
}
void dfs2 (int a , int pos)
{
    if (a > 8) {
        tmp.hash();
        int x = hs[tmp] ;
        REP(i,4) {
            tmp.ch(pos,Arr[pos][i]);
            EDGE[x][i] = hs[tmp];
            tmp.ch(pos,Arr[pos][i]);
        }
    }
    else {
        REP(i,9) if (!init_visit[i]) {
            if (i == 0) pos = a;
            init_visit[i] = true;
            tmp.A[a] = i;
            dfs2(a+1,pos);
            init_visit[i] = false;
        }
    }
}

int m[366666] ;
bool visit[366666] ;

int main() {
    pw[0] = 1;
    FOR(i,9) pw[i] = pw[i-1] * 10;
    dfs1(0); dfs2(0,0);
    
    int Ch , Cv ;
    while (~scanf("%d%d",&Ch,&Cv) && Ch + Cv) {
        REP(i,9) scanf("%d",s.A+i);
        REP(i,9) scanf("%d",t.A+i);

        s.hash() ; t.hash();
        
        int ss = hs[s] , tt = hs[t];

        memset(m,-1,sizeof(m));
        m[ss] = 0;
        memset(visit,0,sizeof(visit));
        
        pq.push(make_pair(0,ss));
        while (!pq.empty()) {
            int x = -pq.top().first , p = pq.top().second ; pq.pop();
            if (visit[p]) continue;
            visit[p] = true;
            if (m[EDGE[p][0]] == -1 || m[EDGE[p][0]] > x + Ch) {
                pq.push(make_pair(-x-Ch,EDGE[p][0]));
                m[EDGE[p][0]] = x + Ch;
            }
            if (m[EDGE[p][1]] == -1 || m[EDGE[p][1]] > x + Ch) {
                pq.push(make_pair(-x-Ch,EDGE[p][1]));
                m[EDGE[p][1]] = x + Ch;
            }
            if (m[EDGE[p][2]] == -1 || m[EDGE[p][2]] > x + Cv) {
                pq.push(make_pair(-x-Cv,EDGE[p][2]));
                m[EDGE[p][2]] = x + Cv;
            }
            if (m[EDGE[p][3]] == -1 || m[EDGE[p][3]] > x + Cv) {
                pq.push(make_pair(-x-Cv,EDGE[p][3]));
                m[EDGE[p][3]] = x + Cv;
            }
        }

        cout << m[tt] << endl;
    }
    return 0;
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | Current Style: Cerulean.

Select Style:   Fluid Width?
 