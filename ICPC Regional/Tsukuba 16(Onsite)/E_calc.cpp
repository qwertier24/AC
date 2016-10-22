#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair

typedef pair<int, bool> pib;
pib calc(char *s, int st, int ed) {
  if (st > ed) {
    return mp(0, false);
  }
  pib ret;
  if (s[st] == '+') {
    return mp(0, false);
  }

  int par = 0;
  for (int i = st; i <= ed; i++) {
    if (s[i] == '(')
      par--;
    else if(s[i] == ')')
      par++;
    if (par > 0)
      return mp(0, false);
  }
  if (par != 0)
    return mp(0, false);

  for (int i = st; i <= ed; i++) {
    if (s[i] == '(')
      par--;
    else if(s[i] == ')')
      par++;
    if (par != 0)
      continue;
    if (s[i] == '+') {
      pib lret = calc(s, st, i-1), rret = calc(s, i+1, ed);
      return mp(lret.fi + rret.fi, lret.se & rret.se);
    }
  }
  for (int i = ed; i >= st; i--) {
    if (s[i] == '(')
      par--;
    else if(s[i] == ')')
      par++;
    if (par != 0)
      continue;
    if (s[i] == '-' && (s[i-1] == ')' || s[i-1] == '0' || s[i-1]=='1')) {
      pib lret = calc(s, st, i-1), rret = calc(s, i+1, ed);
      return mp(lret.fi - rret.fi, lret.se & rret.se);
    }
  }
  if (s[st] == '-') {
    ret = calc(s, st+1, ed);
    return mp(-ret.fi, ret.se);
  }
  for (int i = st; i <= ed; i++) {
    if (s[i] == '(')
      par--;
    else if(s[i] == ')')
      par++;
    if (par != 0)
      continue;
    if (s[i] == '*') {
      pib lret = calc(s, st, i-1), rret = calc(s, i+1, ed);
      return mp(lret.fi * rret.fi, lret.se & rret.se);
    }
  }
  if (s[st] != '(' || s[ed] != ')') {
    for (int i = st; i <= ed; i++) {
      if (!isdigit(s[i]))
	return mp(0, false);
    }
    if (s[st] == '0' && st != ed) {
	return mp(0, false);
    }
    for (int i = st; i <= ed; i++) {
      ret.fi = ret.fi * 2 + s[i] - '0';
    }
    ret.se = true;
    return ret;
  } else {
    return calc(s, st+1, ed-1);
  }
}




bool check (char s[] , int n) {
  int cnt = 0 , pos;
  for (int i = 0 ; i < n ; ++i) if (s[i] == '=') ++cnt;
  if (cnt != 1) return false;
  for (int i = 0 ; i < n ; ++i) if (s[i] == '=') pos = i;
  s[pos] = 0;
  pib a = calc(s,0,pos-1) , b = calc(s,pos+1,n-1);
  if (a.second == false || b.second == false) return false;
  //if (a.first == b.first) {cerr << s << ' ' << s+pos+1 << endl;}
  return a.first == b.first;
}

const char chr[] = {'0','1','+','-','*','(',')','='};
char str[233] , tmpstr[233];
bool visit[233] ;
int hsh[233] , cnthsh = 0 , len;

int gao[233] ;

int dfs (int d) {
  if (d < cnthsh) {
    int r = 0;
    for (int i = 0 ; i < 8 ; ++i)
      if (!visit[i]) {
	visit[i] = true;
	gao[d] = i;
	r += dfs(d+1);
	visit[i] = false;
      }
    return r;
  }
  for (int i = 0 ; i < len ; ++i)
    if (str[i] >= 'a' && str[i] < 'a'+8)
      tmpstr[i] = chr[gao[str[i]-'a']];
    else tmpstr[i] = str[i];
  return check(tmpstr,len);
}

int main (void) {
  //printf("%d\n", calc("((30))", 0, 5).se);
  scanf("%s",str);
  len = strlen(str);
  for (int i = 0 ; str[i] ; ++i) {
    if (((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) && hsh[str[i]] == 0) {
      hsh[str[i]] = 'a' + (cnthsh++);
    }
  }
  if (cnthsh > 8) cout << 0 << endl;
  else {
    for (int i = 0 ; str[i] ; ++i)
      if (hsh[str[i]]) str[i] = hsh[str[i]];
    cout << dfs(0) << endl;
  }

  return 0;
}
