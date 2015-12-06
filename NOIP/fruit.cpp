#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "fruit"
#define dbg if(0)
using namespace std;
struct Node{
	int l,r,val;
	bool operator<(const Node& rhs)const{
		return val<rhs.val;
	}
	bool operator<=(const Node& rhs)const{
		return val<=rhs.val;
	}
	bool operator>(const Node& rhs)const{
		return val>rhs.val;
	}
	bool operator>=(const Node& rhs)const{
		return val>=rhs.val;
	}
}node[10010]={0};
int size=0;
void Insert(int v){
	node[++size].val=v;
	int cur=size,p;
	while(cur>1){
		p=cur/2;
		if(node[p].val>node[cur].val){
			swap(node[p],node[cur]);
			cur=p;
		}else break;
	}
}
void Pop(){
	swap(node[1],node[size]);
	size--;
	int cur=1,c;
	while(cur<<1<=size){
		int lc=cur<<1,rc=cur<<1|1;
dbg		printf("%d\n",cur);
		if(rc<=size){
			if(node[lc]>=node[cur]&&node[rc]>=node[cur])break;
			if(node[lc]<node[rc]&&node[lc]<node[cur]){
				swap(node[cur],node[lc]);
				cur=lc;
			}else if(node[rc]<node[cur]){
				swap(node[cur],node[rc]);
				cur=rc;
			}
		}else if(node[lc].val<node[cur].val){
			swap(node[lc],node[cur]);
			cur=cur<<1;
		}else break;
	}
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int t;
		scanf("%d",&t);
		Insert(t);
	}
	int ans=0;
	while(size>1){
		int a=node[1].val;
		Pop();
		int b=node[1].val;
		Pop();
		ans+=a+b;
		Insert(a+b);
	}
	printf("%d",ans);
	return 0;
}

