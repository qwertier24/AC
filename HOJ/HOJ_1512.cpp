#include <stdio.h>
#include <algorithm>
#include <cstring>
#define For(i,b,e) for(int i=b; i<=e; ++i)
using namespace std;
int n,pa[100010],m;
//并查集
int findset(int u){
	if(pa[u]!=u)pa[u]=findset(pa[u]);
	return pa[u];
}
//左偏树
struct Node{
	int val,dist,left,right; //val是节点的数值，这里指战斗力，dist为节点到子树中最近可插入节点的距离
	void clr(){
		left=right=0;
	}
}monkey[100010];
//合并两棵树
int Union(int a,int b){
	if(a==0)return b;
	if(b==0)return a;
	if(monkey[a].val<monkey[b].val)
		swap(a,b);
	monkey[a].right=Union(monkey[a].right,b);
	if(monkey[monkey[a].left].dist<monkey[monkey[a].right].dist)swap(monkey[a].left,monkey[a].right);
	monkey[a].dist=monkey[monkey[a].right].dist+1;
	return a;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(monkey,0,sizeof(monkey));
		monkey[0].dist=-1;
		For(i,1,n){
			scanf("%d",&monkey[i].val);
			pa[i]=i;
		}
		scanf("%d",&m);
		For(i,1,m){
			int a,b;
			scanf("%d%d",&a,&b);
			a=findset(a);
			b=findset(b);
			if(a!=b){
				monkey[a].val/=2;
				monkey[b].val/=2;
				int la=monkey[a].left,ra=monkey[a].right,lb=monkey[b].left,rb=monkey[b].right;
				monkey[a].clr();
				monkey[b].clr();
				pa[a]=pa[b]=Union(Union(a,Union(la,ra)),Union(b,Union(lb,rb)));
				pa[pa[a]]=pa[a];
				printf("%d\n",monkey[pa[a]].val);
			}else{
				printf("-1\n");
			}
		}
	}
	return 0;
}
