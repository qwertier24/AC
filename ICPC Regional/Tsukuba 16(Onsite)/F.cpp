#include <bits/stdc++.h>
using namespace std;
char p[6],q[6];
int pp,qq;
int cnt;
map<string, int> HH;
vector <int> g[1010][310];
int use[1111];
int n,mi;
int mm[333][333];
int main(){
  //  freopen("in.txt","r",stdin);
  scanf("%s %s\n",p,q);
  scanf("%d\n",&n);
  HH[(string)p] = ++cnt,HH[(string)q] = ++cnt;
  pp = HH[(string)p], qq = HH[(string)q];
  for (int cc = 1; cc <= n; cc++){
    scanf("%d\n",&mi);
    for (int i = 1;i <= mi;i++){
      scanf("%s %s\n",p,q);
      int u,v;
      if (HH[(string)p] == 0)
	HH[(string)p] = ++cnt;
      if (HH[(string)q] == 0)
	HH[(string)q] = ++cnt;
      u = HH[(string)p], v = HH[(string)q];
      g[cc][u].push_back(v);
      if (u == pp && v == qq){
	use[cc] = 1;
      }
    }
  }
  int flag = 0;
  for (int cc = 1;cc <= n;cc++)
    if (use[cc]){
      for (int i = 1;i <= cnt;i++)
	for (int j = 0;j < g[cc][i].size();j++)
	  mm[i][g[cc][i][j]] = 1;
    }

  for (int k = 1;k <= cnt;k++)
    for (int i = 1;i <= cnt;i++)
      for (int j = 1;j <= cnt;j++)
	if (mm[i][k] == 1 && mm[k][j] == 1)
	  mm[i][j] = 1;

  for (int i = 1;i <= cnt;i++){
    if (mm[i][i] == 1) {flag = 1;break;}
  }
  
  
  for (int tm = 1;tm <= 300;tm++){
    if (flag) break;
    int getin = 0,nc = -1;
    for (int cc = 1;cc <= n;cc++){
      if (use[cc] == 1) continue;
      for (int i = 1;i <= cnt;i++){
	for (int j = 0;j < g[cc][i].size();j++)
	  if (mm[i][g[cc][i][j]] == 1){
	    getin = 1;nc = cc;break;
	  }
	if (getin) break;
      }
      if (getin) break;
    }
    if (getin == 0) break;
    else {
      use[nc] = 1;
      for (int i = 1;i <= cnt;i++)
	for (int j = 0;j < g[nc][i].size();j++)
	  if (mm[i][g[nc][i][j]] == 0){
	    int k = g[nc][i][j];
	    
	    for (int ii = 1;ii <= cnt;ii++)
	      for (int jj = 1;jj <= cnt;jj++){
		if (mm[ii][i] == 1)
		  mm[ii][k] = 1;
		if (mm[k][jj] == 1)
		  mm[i][jj] = 1;
		if (mm[ii][i] == 1 && mm[k][jj])
		  mm[ii][jj] = 1;
	      }
	    mm[i][k] = 1;
	    
	  }
      for (int i = 1;i <= cnt;i++)
	if (mm[i][i] == 1) {flag = 1;break;}
    }
  }
  if (flag) printf("No\n");
  else printf("Yes\n");
  return 0;
}
