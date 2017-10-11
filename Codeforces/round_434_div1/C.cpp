#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
#define FI first
#define SE second
#define VI vector<int>
#define CLR(x) memset(x, 0, sizeof(x))
#define SZ(x) (x.size())
#ifdef QWERTIER
#define err(x) cerr<<x<<endl;
#else
#define err(x)
#endif

#define N 100010
char s[N][10];
int type[N], mark[N];
string random_file() {
  string res;
  REP (i, 6)
    res += 'a' + rand() % 26;
  return res;
}
char tmp[100];
vector<string> ans;
void print(const char* src, const char* dest) {
  sprintf(tmp, "move %s %s\n", src, dest);
  ans.push_back(tmp);
}
void print(const char* src, const int dest) {
  sprintf(tmp, "move %s %d\n", src, dest);
  ans.push_back(tmp);
}
void print(const int src, const char* dest) {
  sprintf(tmp, "move %d %s\n", src, dest);
  ans.push_back(tmp);
}
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  int e = 0;
  set<string> str;
  FOR (i, n) {
    scanf("%s%d", s[i], &type[i]);
    str.insert(s[i]);
    if (type[i] == 1)
      e++;
  }
  vector<int> toback, tofront, front, back, tofront2, toback2;
  FOR (i, n) {
    int j = atoi(s[i]);
    char tmp[20];
    sprintf(tmp, "%d", j);
    if (j > 0 && j <= n && strcmp(tmp, s[i]) == 0) {
      if (type[i] == 0) {
        if (j <= e) {
          toback.push_back(i);
        }
      } else {
        if (j > e) {
          tofront.push_back(i);
        }
      }
      mark[j] = 1;
    } else {
      if (type[i] == 0) {
        toback2.push_back(i);
      } else {
        tofront2.push_back(i);
      }
    }
  }
  FOR (i, n) {
    if (!mark[i]) {
      if (i <= e) {
        front.push_back(i);
      } else {
        back.push_back(i);
      }
    }
  }
  // printf("%d %d\n", front.size(), back.size());
  if (front.size() == 0 && back.size() == 0) {
    string temp_file = random_file();
    while (str.count(temp_file))
      temp_file = random_file();
    if (tofront.size() != 0) {
      int i = tofront.back();
      print(s[i], temp_file.c_str());
      strcpy(s[i], temp_file.c_str());
      tofront2.push_back(i);
      tofront.pop_back();
      back.push_back(atoi(s[i]));
    }
  }
  if (front.size() > 0) {
    while (tofront.size() > 0 && toback.size() > 0) {
      print(s[tofront.back()], s[front.back()]);
      print(s[toback.back()], s[tofront.back()]);
      tofront.pop_back();
      toback.pop_back();
      front.pop_back();
      front.push_back(atoi(s[toback.back()]));
    }
  }
  if (back.size() > 0) {
    while (tofront.size() > 0 && toback.size() > 0) {
      print(s[toback.back()], s[back.back()]);
      print(s[tofront.back()], s[toback.back()]);
      toback.pop_back();
      tofront.pop_back();
      front.pop_back();
      back.push_back(atoi(s[tofront.back()]));
    }
  }
  while (tofront.size() > 0) {
    print(s[tofront.back()], front.back());
    back.push_back(atoi(s[tofront.back()]));
    front.pop_back();
    tofront.pop_back();
  }
  // printf("%d\n", back.size());
  // return 0;
  while (toback.size() > 0) {
    print(s[toback.back()], back.back());
    front.push_back(atoi(s[toback.back()]));
    back.pop_back();
    toback.pop_back();
  }
  // puts("");
  for (auto i : tofront2) {
    print(s[i], front.back());
    front.pop_back();
  }
  for (auto i : toback2) {
    print(s[i], back.back());
    back.pop_back();
  }
  printf("%d\n", ans.size());
  for (auto l : ans)
    cout << l;
  return 0;
}
