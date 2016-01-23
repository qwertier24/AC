// BEGIN CUT HERE

#include <conio.h>
#include <sstream>
/*
*/
// END CUT HERE
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std ;

#define FOR(i,n) for(int i=1 ; i<=(n) ; ++i)
#define REP(i,n) for(int i=0; i<(n); ++i)
#define OUT(x)  {cout<< #x << "  : " << x <<endl ;}
#define SZ(x)  (int)((x).size())
typedef long long LL ;
typedef pair<int,int> pii;
#define MP make_pair
#define fi first
#define se second

#define N 1010
int cnt[N][N], s[N][N];
class BagAndCards
{
public:
#define MOD 1000000007
  void add(int &x,int d){
    x+=d;
    x%=MOD;
  }
  int getHash(int n, int m, int x, int a, int b, int c, string isGood)
  {
    memset(cnt,0,sizeof(cnt));
    memset(s,0,sizeof(s));
    REP(i,n)REP(j,m){
      cnt[i][j] = x;
      x = ((x * (LL) a + b) ^ c ) % MOD;
      //printf("%d %d %d\n",i,j,cnt[i][j]);
    }
    REP(i,n)REP(j,m){
      REP(k,m){
        if(isGood[j+k] == 'Y')
          add(s[i][j], cnt[i][k]);
      }
    }
    int ans=0;
    REP(i,n)REP(j,i){
      int tmp = 0;
      REP(k,m)
        add(tmp, s[i][k]*(LL)cnt[j][k]%MOD);
      ans ^= tmp;
      //printf(" %d %d %d\n",i,j,tmp);
    }
    return ans;
  }
 
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 1; int Arg3 = 1; int Arg4 = 0; int Arg5 = 0; string Arg6 = "NNYYNYN"; int Arg7 = 9; verify_case(0, Arg7, getHash(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arg5 = 2; string Arg6 = "NNYYNYNYN"; int Arg7 = 1532; verify_case(1, Arg7, getHash(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 111; int Arg3 = 222; int Arg4 = 333; int Arg5 = 444; string Arg6 = "NNNNNYYYNNNYYYYYYNNYYYYNNNNYNNYYYNNNYYN" ; int Arg7 = 450750683; verify_case(2, Arg7, getHash(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; int Arg4 = 0; int Arg5 = 0; string Arg6 = "NNY"; int Arg7 = 1; verify_case(3, Arg7, getHash(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
  BagAndCards ___test;
  ___test.run_test(-1);
  return 0;
}
// END CUT HERE
 
