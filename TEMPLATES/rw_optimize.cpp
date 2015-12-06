#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;

void readint(char *s,int &x){
  x=0;
  while(*s){
    x=x*10+*s-'0';
    s++;
  }
}
int dig[20],len;
void writeint(int x){
  len=0;
  while(x){
    dig[++len]=x%10;
    x/=10;
  }
  for(int i=len; i; --i)
    putchar(dig[i]+'0');
}
void readstr(char *s){
  len=0;
  char c=getchar();
  while(c!='+'&&c!='?'&&!isdigit(c)&&!isalpha(c)){
    c=getchar();
  }
  while(c=='+'||c=='?'||isdigit(c)||isalpha(c)){
    s[len++]=c;
    c=getchar();
  }
  s[len]=0;
}
void writestr(char *s){
  while(*s)putchar(*s++);
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  
  return 0;
}
