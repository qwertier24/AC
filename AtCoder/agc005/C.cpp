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

#define N 100010
int n, a[N], cnt[N];

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &n);
  int dia = 0;
  FOR (i, n) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
    dia = max(dia, a[i]);
  }
  FOR (i, n) {
    if (a[i] < (dia + 1) / 2) {
      puts("Impossible");
      return 0;
    } 
  }
  for (int i = dia; i >= (dia+1) / 2; i--) {
    if (i == dia && cnt[i] < 2) {
      puts("Impossible");
      return 0;
    }
    if (cnt[i] == 0) {
      puts("Impossible");
      return 0;
    }
    if (i == (dia+1) / 2) {
      if ((dia % 2 == 0 && cnt[i] != 1) || (dia % 2 == 1 && cnt[i] != 2)) {
        puts("Impossible");
        return 0;
      }
    }
  }
  puts("Possible");
  return 0;
}
