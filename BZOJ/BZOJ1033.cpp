#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define East 0

int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m,s,d,r2;
int gameover=0;

using namespace std;

int mark[10][10],mess[10][10];

double curBlood=4;
int rank;

inline bool check(int x,int y,int px,int py){
  return x>=0&&y>=0&&x<=n&&y<=m&&!mark[x][y]&&(x!=px||y!=py);
}

int cakeOnAnt;
int output=0;
struct Ant{
  int x,y,cakeon,age,blood,dblood,r,px,py;
  inline void init(){
    x=y=age=cakeon=0;
    px=py=-1;
    rank++;
    r=(rank-1)/6+1;
    if((rank-1)%6==0)
      curBlood*=1.1;
    blood=dblood=(int)curBlood;
    mark[0][0]=1;
  }
  void move(){
    int dir,maxMess=-1,cango=0,select[4];
    memset(select,0,sizeof(select));
    Rep(i,4)if(check(x+dx[i],y+dy[i],px,py)){      
      cango=1;
      if(maxMess<mess[x+dx[i]][y+dy[i]]){
	memset(select,0,sizeof(select));
	dir=i;
	select[i]=1;
	maxMess=mess[x+dx[i]][y+dy[i]];
      }else if(maxMess==mess[x+dx[i]][y+dy[i]]){
	dir=-1;
	select[i]=1;
      }
    }
    if(cango){
      mark[x][y]=0;

      if(dir==-1){
	dir=East;
	while(!select[dir])dir=(dir+1)%4;
      }
      if((age+1)%5==0){
	dir=(dir+3)%4;
	while(!check(x+dx[dir],y+dy[dir],px,py))dir=(dir+3)%4;
      }
      px=x,py=y;
      x+=dx[dir];
      y+=dy[dir];
      mark[x][y]=1;
    }else px=x,py=y;
    if(x==n&&y==m&&!cakeOnAnt){
      cakeOnAnt=1;
      cakeon=1;
      blood=min(dblood,blood+dblood/2);
    }
    if(x==0&&y==0&&cakeon==1)gameover=1;
  }
  inline void leaveMess(){
    if(cakeon)
      mess[x][y]+=5;
    else 
      mess[x][y]+=2;
  }
  inline bool leaveHere(){
    mark[x][y]=0;
  }
}ant[7];
int antN=0;

int dist2(int x1,int y1,int x2,int y2){
  return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
struct Fire{
  int x,y;
  int target(){
    For(i,antN){
      if(ant[i].cakeon&&dist2(x,y,ant[i].x,ant[i].y)<=r2)
	return i;
    }
    int mind2=1<<30,tar=-1;
    For(i,antN){
      if(dist2(x,y,ant[i].x,ant[i].y)<=r2&&mind2>dist2(x,y,ant[i].x,ant[i].y)){
	tar=i;
	mind2=dist2(x,y,ant[i].x,ant[i].y);
      }
    }
    return tar;
  }
  void fire(){
    int tar=target();
    if(tar==-1)return;
    int R2=dist2(x,y,ant[tar].x,ant[tar].y);
    For(i,antN){
      if(i==tar)
	ant[i].blood-=d;
      else{
	int t1=(ant[i].x-x)*(ant[tar].x-x)+(ant[i].y-y)*(ant[tar].y-y);
	int t2=(ant[i].x-x)*(ant[tar].y-y)-(ant[i].y-y)*(ant[tar].x-x);
	if(t1>=0&&t1<=R2&&4*t2*t2<=R2){
	  ant[i].blood-=d;
	}
      }
    }
  }
}fire[30];
void print_ans(){
  printf("%d\n",antN);
  For(i,antN)printf("%d %d %d %d %d\n",ant[i].age,ant[i].r,ant[i].blood,ant[i].x,ant[i].y);
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif
  int t;
  scanf("%d%d%d%d%d",&n,&m,&s,&d,&r2);
  r2*=r2;
  For(i,s){
    scanf("%d%d",&fire[i].x,&fire[i].y);
    mark[fire[i].x][fire[i].y]=1;
  }
  scanf("%d",&t);
  For(k,t){
    if(antN<6&&!mark[0][0]){
      antN++;
      ant[antN].init();
    }
    For(i,antN){
	ant[i].leaveMess();
    }// first leave the message
    
    For(i,antN){
      ant[i].move();
    }// second go!

    For(i,s)fire[i].fire();// thirdly ,fire!
    For(i,antN)if(ant[i].blood<0){
      if(ant[i].cakeon){
	cakeOnAnt=0;
	gameover=0;
      }
      mark[ant[i].x][ant[i].y]=0;
      for(int j=i+1; j<=antN; j++)
	ant[j-1]=ant[j];
      antN--;
      i--;
    }

    if(gameover){
      printf("Game over after %d seconds\n",k);
      print_ans();
      return 0;
    }
    
    Rep(i,n+1)Rep(j,m+1)
      mess[i][j]=max(0,mess[i][j]-1);
    For(i,antN)ant[i].age++;
  }
  printf("The game is going on\n");
  print_ans();
  return 0;
}
