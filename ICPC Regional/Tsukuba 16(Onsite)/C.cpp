#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
  int x,y;
}a[100100];
int cmp(const node & a,const node & b){
  return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
int ans[200200];
int same[200200];
int main(){
  //  freopen("in.txt","r",stdin);
  scanf("%d%d",&n,&m);
  for (int i = 1;i <= m;i++)
    scanf("%d%d",&a[i].x,&a[i].y);
  sort(a + 1,a + m + 1,cmp);
  for (int i = 1;i <= n;i++)
    ans[i] = 1;
  for (int i = 1;i <= n;i++)
    same[i] = 0;
  for (int i = 1;i <= m;i++){
    int tot = ans[a[i].y] + ans[a[i].y + 1] - same[a[i].y];
    same[a[i].y] = ans[a[i].y] = ans[a[i].y + 1] = tot;
  }
  for (int i = 1;i <= n; i++)
    printf("%d ",ans[i]);
  return 0;
}
