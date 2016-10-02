#include<bits/stdc++.h>
using namespace std;

#define lowbit(i) ((i)&(-(i)))
#define FOR(i,n,...) for (int i = 1 , ##__VA_ARGS__ ; i <= n ; ++i)
#define FSTR(i,s,...) for (int i = 0 , ##__VA_ARGS__ ; s[i] ; ++i)
#define REP(i,s,n,...) for (int i = s , ##__VA_ARGS__ ; i <= n ; ++i)

#ifdef ACMeow
#define ERR(x) cerr << #x << " = " << x << endl;
#define DEBUG_ARR2(ARR,n0,n,m0,m) {cerr << "ARR: " << #ARR << " From (" << n0 << "," << m0 << ") To (" << n << "," << m << ") :" << endl;cerr << "    "; for (int DEBUGi = m0 ; DEBUGi <= m ; ++DEBUGi) cerr << setw(4) << DEBUGi; cerr << endl;for (int DEBUGi = n0 ; DEBUGi <= n ; ++DEBUGi) {cerr << setw(4) << DEBUGi;for (int DEBUGj = m0 ; DEBUGj <= m ; ++DEBUGj) cerr << setw(4) << ARR[DEBUGi][DEBUGj]; cerr << endl;}}
#else
#define ERR(x)
#define DEBUG_ARR2(ARR,n0,n,m0,m)
#endif

typedef long long LL;

LL getint ()
{
  LL r = 0 ; char t = '\0';
  while (t < '0' || t > '9') t = getchar();
  while (t >= '0' && t <= '9') r = r * 10 + t - '0' , t = getchar();
  return r;
}
LL Pow (LL a , LL b , LL MOD)
{
  LL r = 1;
  while (b)
  {
    if (b&1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return r;
}

//

const int MAXN = 20004;

int S[MAXN] , T[MAXN] ;
int TA[MAXN] , V[MAXN] , D[MAXN] ;

int main (void)
{
  int ta , tb , x , nn , m ;
  while (~scanf("%d%d%d%d%d",&ta,&tb,&x,&nn,&m)) {
    int n = 0;
    FOR(i,nn,a,b,c) {
      cin >> a >> b >> c;
      if (a + b >= x && a + b <= x + tb)
      {
        TA[++n] = a + b;
        V[n] = b;
        D[n] = c;
      }
    }
    FOR(i,m,a,b,c) {
      cin >> a >> b >> c;
      TA[++n] = a;
      V[n] = b;
      D[n] = c;
    }
    int AAA = 0;
    vector<pair<int,int> > v;
    FOR(i,n) {
      S[i] = TA[i] + V[i];
      T[i] = S[i] + V[i] >= x && S[i] + V[i] <= x + tb ? tb + x + V[i] - (tb + x - TA[i]) % (V[i] +  V[i]) : S[i];
      if (S[i] + ta >= T[i]) {
        v.push_back(make_pair(T[i]-ta,-D[i]));
        v.push_back(make_pair(S[i],D[i]));
      }
      AAA += D[i];
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for (int i = 0 , tmp = 0 ; i < int(v.size()) ; ++i)
    {
      tmp += v[i].second;
      ans = min(ans,tmp);
    }
    cout << AAA + ans << endl;
  }
  return 0;
}
