#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<map>
#define PROB "recording"
#define N 150
#define For(i,n) for(int i=1; i<=n; i++)

using namespace std;


int n;
pair<int,int> line[N+10];
map<int,int> mp;
int d[N*2+10][N*2+10];
int main(){
  freopen(PROB".in","r",stdin);
  freopen(PROB".out","w",stdout);
  scanf("%d",&n);
  For(i,n){
    scanf("%d%d",&line[i].first,&line[i].second);
    mp[line[i].first];
    mp[line[i].second];
  }
  sort(line+1,line+n+1);
  int t=0;
  for(map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it)
    it->second=++t;
  For(i,n)line[i].first=mp[line[i].first],line[i].second=mp[line[i].second];
  For(i,n)
    for(int j=t; j>=1; j--)
      for(int k=t; k>=1; k--){
	d[j][k]=max(d[j][k],
		    max(j>=line[i].second?d[line[i].first][k]+1:0,
			k>=line[i].second?d[j][line[i].first]+1:0
			)
		    );
	//printf("%d %d %d %d\n",i,j,k,d[i][j][k]);
      }
  printf("%d\n",d[t][t]);
  return 0;
}
