#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>
#define PROB "running1"
 
using namespace std;
 
int val[100010]={0},len=0;
int get_prefix(int p){
	int ret=0;
	for(; p; p-=(p&(-p)))
		ret+=val[p];
	return ret;
}
void add_prefix(int p){
	for(; p<=len; p+=(p&(-p)))
		val[p]++;
}
 
typedef pair<int,int> Cow;
#define speed first
#define mod second
Cow cow[100010];
inline bool by_speed(const Cow& a,const Cow& b){
	return a.speed<b.speed;
}
inline bool by_mod(const Cow& a,const Cow& b){
	return a.mod<b.mod;
}
 
 
int main(){
	FILE* fin=fopen(PROB".in","r");
	FILE* fout=fopen(PROB".out","w");
	int n,C,ms=0;
	long long L;
	fscanf(fin,"%d%lld%d",&n,&L,&C);
	for(int i=1; i<=n; i++){
		fscanf(fin,"%d",&cow[i].speed);
		ms=max(ms,cow[i].speed);
	}
 
	for(int i=1; i<=n; i++)
		cow[i].mod=cow[i].speed*L%ms;
	sort(cow+1,cow+n+1,by_mod);
	for(int i=1; i<=n; i++){
		int l=i,r=i;
		len++;
		while(r<n&&cow[r+1].mod==cow[i].mod)
			r++;
		for(int j=l; j<=r; j++)
			cow[j].mod=len;
		i=r;
	}
	
	sort(cow+1,cow+n+1,by_speed);
	long long sum=0,ans=0;
	for(int i=1; i<=n; i++){
		long long floor=cow[i].speed*L/ms;
		//cout<<i<<' '<<floor<<' '<<cow[i].mod<<endl;
		ans+=floor*(i-1)-sum-(i-1)+get_prefix(cow[i].mod);
		add_prefix(cow[i].mod);
		sum+=floor;
	}
	fprintf(fout,"%lld",ans);
	return 0;
}
