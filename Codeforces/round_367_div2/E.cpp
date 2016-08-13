#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair
#define N 1010

struct Node{
  Node *t,*b,*l,*r;
  int v;
}node[N][N];


int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, m, Q;
  scanf("%d%d%d", &n, &m, &Q);
  REP (i, n+2) {
    REP (j, m+2) {
      if (1 <= i && i <= n && 1 <= j && j <= m)
        scanf("%d", &node[i][j].v);
      node[i][j].l = &node[i][j-1];
      node[i][j].t = &node[i-1][j];
      node[i][j].b = &node[i+1][j];
      node[i][j].r = &node[i][j+1];
    }
  }
  while (Q--) {
    int x1, y1, x2, y2, h, w;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &h, &w);
    Node *cur = &node[0][1], *cur2 = &node[0][1];
    FOR (i, x1) {
      cur = cur->b;
    }
    FOR (i, y1 - 1) {
      cur = cur->r;
    }
    FOR (i, x2) {
      cur2 = cur2->b;
    }
    FOR (i, y2-1) {
      cur2 = cur2->r;
    }
    swap(cur->l->r, cur2->l->r);
    swap(cur->l, cur2->l);
    FOR (i, h-1) {
      cur = cur->b;
      cur2 = cur2->b;
      swap(cur->l->r, cur2->l->r);
      swap(cur->l, cur2->l);
    }
    swap(cur->b->t, cur2->b->t);
    swap(cur->b, cur2->b);
    FOR (i, w-1) {
      cur = cur->r;
      cur2 = cur2->r;
      swap(cur->b->t, cur2->b->t);
      swap(cur->b, cur2->b);
    }

    swap(cur->r->l, cur2->r->l);
    swap(cur->r, cur2->r);
    FOR (i, h-1) {
      cur = cur->t;
      cur2 = cur2->t;
      swap(cur->r->l, cur2->r->l);
      swap(cur->r, cur2->r);
    }

    swap(cur->t->b, cur2->t->b);
    swap(cur->t, cur2->t);
    FOR (i, w-1) {
      cur = cur->l;
      cur2 = cur2->l;
      swap(cur->t->b, cur2->t->b);
      swap(cur->t, cur2->t);
    }
  }
  FOR (i, n) {
    Node *cur = &node[i][0];
    FOR (j, m) {
      cur = cur->r;
      printf("%d ", cur->v);
    }
    puts("");
  }
  return 0;
}
