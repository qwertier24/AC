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
#define FOR(i,n) for(int i = 1 ; i<=(n) ; ++i)
#define REP(i,n) for(int i=0; i<(n); i++)
#define OUT(x)  {cout<< #x << "  : " << x <<endl ;}
#define SZ(x)  (int)((x).size())
typedef long long LL ;

class TreeAndPathLength3
{
  public:
  vector <int> construct(int s)
  {
    printf("%d---------------------------\n",s);
    vector<int> ans;
    int n = 1;
    if(int(sqrt(s)) * int(sqrt(s)) == s){
      n = sqrt(s);
    }else{
      while((n+1)*(n+2) <= s)
        n++;
    }
    printf("%d\n",n);
    REP(i,n){
      ans.push_back(i);
      ans.push_back(n<<1);
      ans.push_back(n+i);
      ans.push_back(n<<1|1);
    }
    ans.push_back(n<<1);
    ans.push_back(n<<1|1);
    if(n*n!=s){
      for(int i=0; i<s-n*(n+1)+1; i++){
        if(i==0)
          ans.push_back(0);
        else
          ans.push_back((n<<1|1)+i);
        ans.push_back((n<<1|1)+i+1);
      }
    }
    REP(i,SZ(ans))printf("%d ",ans[i]);
    puts("");
    return ans;
  }
 
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {0, 1, 1, 2, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {0, 1, 1, 2, 2, 3, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { int Arg0 = 8; int Arr1[] = {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, construct(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
  TreeAndPathLength3 ___test;
  ___test.run_test(-1);
  TreeAndPathLength3 solver;
  solver.construct(101);
  return 0;
}
// END CUT HERE
 
