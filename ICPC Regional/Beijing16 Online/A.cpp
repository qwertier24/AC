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

string str;

bool Getstr ()
{
  char tmp[233] ;
  if (gets(tmp)) {
    str = tmp;
    return true;
  }
  str = "";
  return false;
}

struct node
{
  set<string> files;
  map<string,node*> tree;
  ~node ()
  {
    for (map<string,node*>::iterator it = tree.begin() ; it != tree.end() ; ++it)
      delete it -> second;
  }
}*pnt;

void init ()
{
  delete pnt;
  pnt = new node;
}

vector<string> SPlit (string s)
{
  vector<string> res;
  string tmp;
  for (int i = 0 ; i < (int)s.length() ; ++i)
    if (s[i] == '/') res.push_back(tmp) , tmp = "";
    else tmp.append(1,s[i]);
  res.push_back(tmp);
  return res;
}

void gao ()
{
  vector<string> vec = SPlit(str);
  node * p = pnt;
  for (int i = 0 ; i < (int)vec.size() - 1 ; ++i)
  {
    if (p -> tree.find(vec[i]) == p -> tree.end())
      p -> tree.insert(make_pair(vec[i],new node));
    p = p -> tree[vec[i]];
  }
  p -> files.insert(vec[vec.size()-1]);
}

void shuchu (node * p = pnt , int x = 0)
{
  for (map<string,node*>::iterator it = p -> tree.begin() ; it != p -> tree.end() ; ++it)
  {
    FOR(i,x) cout << "    ";
    cout << (it -> first) << endl;
    shuchu(it -> second,x+1);
  }
  for (set<string>::iterator it = p -> files.begin() ; it != p -> files.end() ; ++it)
  {
    FOR(i,x) cout << "    ";
    cout << (*it) << endl;
  }
}

int main (void)
{
  FOR(Cas,Cas+1) {
    init ();
    
    while (Getstr() && str != "0")
      gao();
    if (str == "") break;
    cout << "Case " << Cas << ":" << endl;
    shuchu();
  }
  return 0;
}
