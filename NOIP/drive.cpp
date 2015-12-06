#include <stdio.h>
#include <algorithm>
#include <set>
#include <cmath>
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
struct STEP{
	long long da,db;
	int v;
	STEP operator+(const STEP& t){
		return (STEP){da+t.da,db+t.db,t.v};
	}
}steps[200010][20];
struct City{
	int ord,h,nt,nnt,ns,nns,cost;
	bool operator<(const City& rhs)const{
		return h<rhs.h;
	}
}city[100010]={0};
int h[100010],n;
set<City> st;
inline int dist(const City& a,const City& b){
	if(a.ord==0||b.ord==0)
		return 0;
	return abs(a.h-b.h);
}
STEP solve(int s,int x0){
	STEP ret;
	ret.da=ret.db=ret.v=0;
	int p=s,l=(int)(log2(n));
	long long x=x0,sa=0,sb=0;
	//
	while(p){
		while(l>=0&&steps[p][l].da+steps[p][l].db>x)
			l--;
		if(l==-1){
			if(steps[p][0].da>x)
				break;
			else
				l=0;
		}
		ret.da+=steps[p][l].da;
		x-=steps[p][l].da;
		if(steps[p][l].db>x)
			break;
		ret.db+=steps[p][l].db;
		x-=steps[p][l].db;
		//printf("  %d %d %lld %lld\n",s,p,ret.da,ret.db);
		p=steps[p][l].v;
	}
	return ret;
}
int main(){
	freopen("drive.in","r",stdin);
	freopen("drive.out","w",stdout);
	scanf("%d",&n);
	For(i,1,n){scanf("%d",&h[i]);city[i].h=h[i];city[i].ord=i;}
	city[n-1].nt=n;
	st.insert(city[n]);
	if(n>1)st.insert(city[n-1]);
	for(int i=n-2; i>=1; i--){
		set<City>::iterator left,right=st.upper_bound(city[i]);
		left=right;
		if(left==st.begin()){
			//printf("%d left==st.begin()\n",i);
			city[i].nt=right->ord;
			++right;
			if(right!=st.end())
				city[i].nnt=right->ord;
		}
		else if(right==st.end()){
			city[i].nt=(--left)->ord;
			if(left!=st.begin()){
				city[i].nnt=(--right)->ord;
			}
		}
		else{
			--left;
			if(dist(*left,city[i])<=dist(*right,city[i])){
				city[i].nt=left->ord;
				if(left==st.begin())
					city[i].nnt=right->ord;
				else{
					--left;
					if(dist(*left,city[i])<=dist(*right,city[i]))
						city[i].nnt=left->ord;
					else
						city[i].nnt=right->ord;
				}
			}
			else{
				city[i].nt=right->ord;
				++right;
				if(right==st.end())
					city[i].nnt=left->ord;
				else{
					if(dist(*left,city[i])<=dist(*right,city[i]))
						city[i].nnt=left->ord;
					else
						city[i].nnt=right->ord;
				}
			}
		}
		city[i].ns=city[i].nnt;
		city[i].nns=city[city[i].ns].nt;
		city[i].cost=dist(city[i],city[city[i].ns])+dist(city[city[i].ns],city[city[i].nns]);
		//printf("i:%d ns:%d nns:%d\n",i,city[i].ns,city[i].nns);
		st.insert(city[i]);
	}
	For(i,1,n){
		steps[i][0].da=dist(city[i],city[city[i].ns]);
		steps[i][0].db=dist(city[city[i].ns],city[city[i].nns]);
		steps[i][0].v=city[i].nns;
	}
	for(int i=1; (1<<i)<=n; i++)
		for(int j=1; j<=n; j++){
			steps[j][i]=steps[j][i-1]+steps[steps[j][i-1].v][i-1];
			//printf("%d %d %d %lld %lld\n",i,j,steps[j][i].v,steps[j][i].da,steps[j][i].db);
		}
	long long x0,aa=0,ab=0,ah=-(1ll<<60);
	int ans;
	scanf("%lld",&x0);
	For(i,1,n){
		int p=i,l=(int)(log2(n));
		STEP t=solve(i,x0);
		long long x=x0,sa=t.da,sb=t.db;
		//printf("i:%d da:%lld db:%lld\n",i,t.da,t.db);
		double s1=sa*ab,s2=sb*aa;
		if(sa||sb)
		if(s1<s2||(s1==s2&&h[i]>ah)){
			aa=sa;
			ab=sb;
			ah=h[i];
			ans=i;
		}
	}
	printf("%d\n",ans);
	int m,s;
	scanf("%d",&m);
	For(i,1,m){
		scanf("%d %lld",&s,&x0);
		STEP t=solve(s,x0);
		printf("%lld %lld\n",t.da,t.db);
	}
	return 0;
}
