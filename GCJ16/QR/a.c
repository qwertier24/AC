#include<stdio.h>
#include<string.h>

int max(int a, int b){return a>b?a:b;}
int min(int a, int b){return a<b?a:b;}

typedef long long LL;

/*
qsort(a, n, sizeof(int), tmp);
bsearch(&key, a, n, sizeof(int), cmp);
*/


int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  
  /*
    a[0..(n-1)]
  */
  scanf("%d", &a0);
  int cur = a0, cnt = 1;
  for(i = 1; i < n; i++){
    if(a[i] == cur)
      cnt++;
    else
      cnt--;
    if(cnt == 0){
      cur = a[i];
      cnt = 1;
    }
  }
  return 0;
}
