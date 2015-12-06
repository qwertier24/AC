#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#define For(i,b,e) for(int i=(b); i<=(e); ++(i))
typedef long long LL;
using namespace std;
int n;
struct Edge{
	int v;
	long long d;
	bool operator<(const Edge& rhs)const{
		return d<rhs.d;
	}
};
struct Step{
	long long d;
	int v;
	Step operator+(const Step& rhs){
		return (Step){d+rhs.d,rhs.v};
	}
}steps[50010][20]={0};
struct Army{
	int u;
	LL remain_d;
	bool operator<(const Army& rhs)const{
		return remain_d<rhs.remain_d;
	}
};
vector<Army> army_in_cap;
vector<Edge> g[50010];
int cnt[50010],max_l,settled[50010]={0},in_province[50010];
long long max_dist;
void calc_steps(int u,int f){
	if(f==1||f==0)
		in_province[u]=u;
	else
		in_province[u]=in_province[f];
	For(i,1,max_l)
		steps[u][i]=steps[u][i-1]+steps[steps[u][i-1].v][i-1];
	For(i,0,g[u].size()-1)
		if(g[u][i].v!=f){
			int& v=g[u][i].v;
			steps[v][0].v=u;
			steps[v][0].d=g[u][i].d;
			calc_steps(v,u);
		}
}
void solve(int u){
	long long x=max_dist;
	int p=u,l=max_l;
	while(p){
		while(l>=0&&steps[p][l].d>x)
			l--;
		if(l==-1)
			break;
		x-=steps[p][l].d;
		p=steps[p][l].v;
	}
	if(p==0)
		army_in_cap.push_back((Army){in_province[u],x});
	else
		settled[p]=1;
	//printf("%d %d %I64d %d\n",u,p,x,l);
}
bool controlled(int u,int f){
	if(settled[u])return true;
	if(u!=1&&g[u].size()==1)
		return false;
	For(i,0,g[u].size()-1){
		if(g[u][i].v!=f){
			if(!controlled(g[u][i].v,u))
				return false;
		}
	}
	settled[u]=1;
	return true;
}
bool check(){
	vector<Edge> uct;
	For(i,0,g[1].size()-1)
		if(!controlled(g[1][i].v,1))
			uct.push_back(g[1][i]);
	if(!uct.size())
		return true;
	if(army_in_cap.size())
		sort(army_in_cap.begin(),army_in_cap.end());
	//printf("size:%d\n",army_in_cap.size());
	int pb=0;
	if(army_in_cap.size())
		For(pa,0,army_in_cap.size()-1){
			//printf("army:%d %I64d\n",army_in_cap[pa].u,army_in_cap[pa].remain_d);
			if(pb>=uct.size())
				break;
			if(!settled[army_in_cap[pa].u]){
				settled[army_in_cap[pa].u]=1;
				continue;
			}
			while(pb<uct.size()&&settled[uct[pb].v])
				pb++;
			if(uct[pb].d>army_in_cap[pa].remain_d)
				continue;
			else
				settled[uct[pb++].v]=1;
		}
	For(i,0,uct.size()-1)
		if(!settled[uct[i].v]){
			//printf("unsettled:%d\n",uct[i].v);
			return false;
		}
	return true;
}
int main(){
	freopen("blockade.in","r",stdin);
	freopen("blockade.out","w",stdout);
	scanf("%d",&n);
	max_l=(int)log2(n);
	For(i,1,n-1){
		int f,t,d;
		scanf("%d%d%d",&f,&t,&d);
		g[f].push_back((Edge){t,(long long)d});
		g[t].push_back((Edge){f,(long long)d});
	}
	sort(g[1].begin(),g[1].end());
	int m;
	scanf("%d",&m);
	For(i,1,m){
		int t;
		scanf("%d",&t);
		cnt[t]++;
	}
	if(m<g[1].size()){
		printf("-1");
		return 0;
	}
	calc_steps(1,0);
	/*
	For(i,1,n)
		For(j,0,max_l)
			printf("%d %d %d %I64d\n",i,j,steps[i][j].v,steps[i][j].d);
	*/
	long long l=0,r=(int)(1e14);
	while(l<r){
		LL m=(l+r)>>1;
		max_dist=m;
		army_in_cap.clear();
		memset(settled,0,sizeof(settled));
		For(i,1,n)
			For(j,1,cnt[i])
				solve(i);
		if(check())r=m;
		else l=m+1;
	}
	cout<<l;
	return 0;
}

