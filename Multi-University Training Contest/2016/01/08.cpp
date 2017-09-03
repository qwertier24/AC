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

#define N 400010
#define MOD 313

namespace FFT {
int L;
struct cp{
  double r,i;
  cp(){r=i=0;}
  cp(double _r,double _i):r(_r),i(_i){}
  cp operator*(cp &t){return cp(r*t.r-i*t.i,i*t.r+t.i*r);}
  cp operator+(cp &t){return cp(r+t.r,i+t.i);}
  cp operator-(cp &t){return cp(r-t.r,i-t.i);}
};
 
const double PI=3.1415926535897932384626;
cp tmp[N];
int rev[N];
 
void fft(cp *a,int flag){
  REP(i,(1<<L))tmp[i]=a[rev[i]];
  REP(i,(1<<L))a[i]=tmp[i];
  for(int k=2; k<=(1<<L); k<<=1){
    cp wn(cos(2*PI/k),flag*sin(2*PI/k));
    for(int i=0; i<(1<<L); i+=k){
      cp w(1,0),x,y;
      for(int j=i; j<i+k/2; j++){
        x=a[j];
        y=a[j+k/2]*w;
        a[j]=x+y;
        a[j+k/2]=x-y;
        w=w*wn;
      }
    }
  }
  if(flag==-1)REP(i,(1<<L))a[i].r/=(1<<L);
}

void calc_rev() {
  REP(i,(1<<L)){
    rev[i] = 0;
    REP(j,L) {
      if((i>>j)&1)
        rev[i]|=(1<<(L-1-j));
    }
  }
}

}

FFT::cp ca[N], cb[N];
void calc(int *a, int *b, int na, int nb) {
  int la = (int)log2(na) + 2,
      lb = (int)log2(nb) + 2;
  int lm = max(la, lb);
  /*
  printf("calc:\n");
  REP (i, na) {
    printf("%d ", a[i]);
  }
  puts("");
  REP (i, nb) {
    printf("%d ", b[i]);
  }
  puts("");
  */
  FFT::L = lm;
  FFT::calc_rev();
  memset(ca, 0, sizeof(FFT::cp)*(1<<lm));
  memset(cb, 0, sizeof(FFT::cp)*(1<<lm));
  REP (i, na) {
    ca[i] = FFT::cp(a[i], 0);
  }
  REP (i, nb) {
    cb[i] = FFT::cp(b[i], 0);
  }
  FFT::fft(ca, 1);
  FFT::fft(cb, 1);
  REP (i, (1<<lm)) {
    ca[i] = ca[i] * cb[i];
  }
  FFT::fft(ca, -1);
  REP (i, max(na, nb)) {
    a[i] = int(ca[i].r+0.5);
  }
}

int a[N], f[N], g[N], h[N];
void proc(int l, int r) {
  if (l == r) 
    return;

  //printf("proc:%d %d\n", l, r);
  int mid = (l+r)>>1;
  proc(l, mid);

  /*
    f[i]
    = f[0..i-1] * a[i-j]
    f[mid+1] += g[mid+1-l] = f[i=l..mid] * a[mid+1-l];
  */
  int n1 = r - l + 1;
  memset(g, 0, sizeof(int)*n1);
  memset(h, 0, sizeof(int)*n1);
  for (int i = l; i <= mid; i++) {
    g[i-l] = f[i];
  }
  for (int i = 0; i <= r - l; i++) {
    h[i] = a[i];
  }
  int n2 = r - l + 1;
  calc(g, h, n1, n2);
  for (int i = mid+1; i <= r; i++) {
    f[i] += g[i-l];
    f[i] %= MOD;
  }
  proc(mid+1,r);
}

int x[N], y[N];
int main() {
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int n;
  while (scanf("%d", &n) && n) {
    FOR (i, n) {
      scanf("%d", &a[i]);
      a[i] %= MOD;
    }
    memset(f, 0, sizeof(f));
    f[0] = 1;
    proc(0, n);
    printf("%d\n", f[n]);
    /*
    FOR (i, n) {
      printf("%d ", f[i]);
    }
    puts("");
    */
    /*
    FOR (i, n) {
      f[i] = 0;
      FOR (j, i) {
        f[i] += f[i-j] * a[j];
      }
      printf("%d ", f[i]);
    }
    puts("");
    */
  }
  return 0;
}
