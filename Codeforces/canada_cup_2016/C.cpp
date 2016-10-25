#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))  // Leading zeros
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#ifdef QWERTIER
#define err(x) cerr << #x << " : " << x << endl
#else
#define err(x)
#endif

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 30
char s[N];
const int n = 13, m = 27;
char ans[2][30];
void push(int p, char c) {
  //printf("%d:%c\n", p, c);
  if (ans[0][p])
    ans[1][p] = c;
  else
    ans[0][p] = c;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%s", s);
  REP (i, m) {
    REP (j, i) {
      if (s[i] == s[j]) {
        if (i == j+ 1) {
          puts("Impossible");
          return 0;
        }
        int mi = n - (i-j+1)/2;
        //printf("%d\n", mi);
        int pmi = mi, dmi = 1;
        for (int k = j; k < i; k++) {
          if (pmi == n) {
            pmi = n - 1;
            dmi = -1;
          }
          push(pmi, s[k]);
          pmi+=dmi;
        }
        int L = j - 1, R = i + 1, Ln = j, Rn = m - i - 1;
        //printf("%d %d\n", Ln, Rn);
        char* Ls = s, *Rs = s+m-1;
        if (Ln > Rn) {
          for (int k = 0; k < (Ln-Rn)/2; k++) {
            push(k, *Ls++);
            push(k, *Ls++);
          }
          for (int k = (Ln-Rn)/2; k < (Ln-Rn)/2+Rn; k++) {
            push(k, *Ls++);
            push(k, *Rs--);
          }
          if ((Ln-Rn)&1) {
            push(mi, *Ls++);
          }
        } else {
          for (int k = 0; k < (Rn-Ln)/2; k++) {
            push(k, *Rs--);
            push(k, *Rs--);
          }
          for (int k = (Rn-Ln)/2; k < (Rn-Ln)/2+Ln; k++) {
            push(k, *Ls++);
            push(k, *Rs--);
          }
          if ((Rn-Ln)&1) {
            push(mi, *Rs--);
          }
        }
      }
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 13; j++) {
      putchar(ans[i][j]);
    }
    puts("");
  }
  return 0;
}
