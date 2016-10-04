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

#define N 30
#define M 10
#define double long double
const int m = 7;

char cmd[100][1010];
int cmdn;

vector<int> adj[N];
void addEdge(int u, int v) {
    adj[u].push_back(v);
}

int tot[m];

int countSpace(char *s) {
    int ret = 0;
    while (*s == ' ') {
        ret++;
        s++;
    }
    return ret;
}

int variable[27];
void proc(char *s, int *var, int &lVar, int &rVar, int &rVal) {
    //printf(s);
    while (*s == ' ')
        s++;
    int curVar;
    char tmpVar;
    sscanf(s, "for %c", &tmpVar);
    lVar = tmpVar - 'a';
    
    if (s[0] == 'l' && s[1] == 'a' && s[2] == 'g') {
        lVar = -1;
        return;
    }
    while (*s != '(')
        s++;
    s++;
    if (isalpha(*s)) {
        rVar = *s - 'a';
    } else {
        rVal = *s - '0';
    }
    //printf("proc:%d,%s", num, s);
    return;
}

int lVar[40], rVar[40], vis[40], rVal[40];
void dfs(int u, int *var) {
    if (!vis[u]) {
        if (u) {
            proc(cmd[u], var, lVar[u], rVar[u], rVal[u]);
        } else {
            lVar[u] = 26;
            rVal[u] = 1;
        }
        /*
        printf(cmd[u]);
        printf("%d %d %d %d\n", u, lVar[u], rVal[u], rVar[u]);
        */
    }
    vis[u] = 1;
    if (lVar[u] == -1) {
        tot[var['n' - 'a']]++;
    } else {
        REP (j, (rVal[u]!=-1?rVal[u]:var[rVar[u]])) {
            var[lVar[u]] = j;
            for (int i = 0; i < adj[u].size(); i++)
                dfs(adj[u][i], var);
        }
    }
}

double mat[m+10][m+10];
void gauss() {
    REP (i, m) {
        REP (j, m + 1) {
            //printf("%f%s", mat[i][j], j == m?"\n":" ");
        }
    }
    REP (i, m) {
        int k = i;
        for (int j = i + 1; j < i; j++)
            if (fabs(mat[j][i]) > fabs(mat[k][i]))
                k = j;
        if (k != i)
            for (int j = i; j <= m; j++)
                swap(mat[i][j], mat[k][j]);
        for (int j = i + 1; j < m; j++) {
            for (int k = m; k >= i; k--)
                mat[j][k] -= mat[j][i] / mat[i][i] * mat[i][k];
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = i + 1; j < m; j++)
            mat[i][m] -= mat[i][j] * mat[j][m];
        mat[i][m] /= mat[i][i];
    }
}

int node[m];
int main() {
    freopen("fygon.in", "r", stdin);
    freopen("fygon.out", "w", stdout);
    node[0] = 0;
    cmdn++;
    memset(rVal, -1, sizeof(rVal));
    memset(lVar, -1, sizeof(lVar));
    while (fgets(cmd[cmdn], sizeof(cmd[cmdn]), stdin) != NULL) {
        int curDep = countSpace(cmd[cmdn]) / 4 + 1;
        node[curDep] = cmdn;
        addEdge(node[curDep - 1], node[curDep]);
        cmdn++;
    }
    REP (i, m) {
        variable['n' - 'a'] = i;
        dfs(0, variable);
        //printf("%d\n", tot[i]);
    }
    REP (i, m) {
        REP (j, m) {
            mat[i][j] = j ? mat[i][j-1]*i : 1;
        }
        mat[i][m] = tot[i];
    }
    gauss();
    int flag = 0;
    REP (i, m) {
        ll tmp;
        //printf("\n:%f\n", (float)mat[i][m]);
        
        if (mat[i][m] < 0)
            tmp = ll(mat[i][m]*5040 - 0.5);
        else
            tmp = ll(mat[i][m]*5040 + 0.5);
        ll g = __gcd(tmp, 5040ll);
        if (g < 0)
            g *= -1;
        ll a = tmp / g, b = 5040 / g;
        if (tmp != 0) {
            if (flag) {
                if (a > 0)
                    printf("+");
            } else {
                flag = 1;
            }
            printf("%I64d/%I64d", a, b);
            REP (j, i)
                printf("*n");
        }
    }
    return 0;
}
close