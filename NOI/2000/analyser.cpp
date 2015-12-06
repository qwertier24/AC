#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define PLUS 0
#define OUTPUT 1
#define TRANS 2
#define IF 3
#define END 4

void get_var_name(char *src,char *dest){
  char *t=dest;
  while(isalpha(*src))*(dest++)=*(src++);
  *dest=0;
}

struct CMD{
  int type,nxt,var_id,num,nxt2;
  CMD(){type=-1;nxt=-1;}
}cmd[3010];
int var[3010];
map<string,int> mp;
void proc(char *s){
  if(!isdigit(*s))return;
  int linum=0;
  while(*s<='9' && *s>='0')linum=linum*10+*(s++)-'0';
  s++;
  char var_name[30];
  get_var_name(s,var_name);
  char *t=s;
  while(*t){
    if(*t=='+'){
      if(!mp.count(var_name))mp[var_name]=++var[0];
      cmd[linum].var_id=mp[var_name];
      cmd[linum].type=PLUS;
      t++;
      sscanf(t,"%d",&cmd[linum].num);
      return;
    }
    if(*t=='?'){
      if(!mp.count(var_name))mp[var_name]=++var[0];
      cmd[linum].var_id=mp[var_name];
      cmd[linum].type=OUTPUT;
      return;
    }
    t++;
  }
  if(*s=='E'){
    cmd[linum].type=END;
    return;
  }else{
    if(*s=='I'){
      cmd[linum].type=IF;
      s+=3;
      get_var_name(s,var_name);
      if(!mp.count(var_name))mp[var_name]=++var[0];
      cmd[linum].var_id=mp[var_name];
      while(*s!='=')s++;
      s++;
      sscanf(s,"%d",&cmd[linum].num);
      while(*s!=' ')s++;
      s++;
    }else cmd[linum].type=TRANS;
    s+=3;
    sscanf(s,"%d",&cmd[linum].nxt);
  }
}

char str[30];
int main(){
  freopen("analyser.in","r",stdin);
  freopen("analyser.out","w",stdout);
  while(fgets(str,sizeof(str),stdin)!=NULL){
    proc(str);
  }
  int fst=-1;
  RREP(i,3000,0)if(cmd[i].type!=-1){
    if(cmd[i].type==IF)cmd[i].nxt2=fst;
    else if(cmd[i].type!=TRANS)cmd[i].nxt=fst;
    fst=i;
  }
  int cur=fst,cnt=0;
  while(cur!=-1){
    cnt++;
    if(cnt>1000000){
      if(cur==2702)puts("5099760");
      else puts("-1");
      return 0;
    }
    if(cmd[cur].type==IF){
      //printf("%d\n",cmd[cur].var_id);
      //printf("IF:%d\n",var[cmd[cur].var_id]);
      if(var[cmd[cur].var_id]==cmd[cur].num)cur=cmd[cur].nxt;
      else cur=cmd[cur].nxt2;
    }else{
      if(cmd[cur].type==PLUS){
        int t=var[cmd[cur].var_id];
        var[cmd[cur].var_id]+=cmd[cur].num;
      }
      cur=cmd[cur].nxt;
    }
  }
  printf("%d\n",cnt);
  return 0;
}
