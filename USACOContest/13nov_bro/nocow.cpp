#include<stdio.h>
#include<algorithm>
#include<map>
#include<string>
#include<iostream>
#define dbg if(0)
#define PROB "nocow"
#define For(i,n) for(int i=1; i<=n; i++)
using namespace std;

struct Cow{
	int type[40];
	string t[40];
}cow[110];

map<string,int> mp[40];
int type_n,n,k,rank[40]={0},total[40]={0};
bool check(int* pos){
	for(int i=1; i<=n; i++){
		bool flag=true;
		for(int j=1; j<=type_n; j++)
			if(cow[i].type[j]!=pos[j])
				flag=false;
		if(flag)return false;
	}
	return true;
}
bool cmp(Cow& a,int* pos){
	int i;
	for(i=1; i<=type_n&&a.type[i]==pos[i]; i++){}
	return a.type[i]<=pos[i];
}
int cnt(int* pos){
	int ret=0;
	For(i,n)
		if(cmp(cow[i],pos))
			ret++;
	return ret;
}				
void Plus(int* pos){
	pos[type_n]++;
	int p=type_n;
	while(pos[p]>=rank[p]){
		pos[p-1]++;
		pos[p]=0;
		p--;
	}
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d",&n,&k);
	string s;
	For(i,n){
		type_n=0;
		while(cow[i].t[type_n]!="cow."){
			cin>>cow[i].t[++type_n];
		}
		type_n-=5;
		for(int j=5; j<=4+type_n; j++){
			mp[j-4][cow[i].t[j]];
		}
	}
	for(int i=type_n; i>=1; i--){
		total[i]=max(1,total[i+1]*rank[i+1]);
		for(map<string,int>::iterator it=mp[i].begin(); it!=mp[i].end(); ++it){
			it->second=rank[i];
			rank[i]++;
		}
	}
	For(i,n)
		for(int j=5; j<=4+type_n; j++){
			cow[i].type[j-4]=mp[j-4][cow[i].t[j]];
			//printf("%d %d %d\n",i,j-4,cow[i].type[j-4]);
		}
	
	int rem=k-1,p=1;
	int pos[40]={0};
	while(rem){
		while(pos[p]<rank[p]&&rem>=0){
			rem-=total[p];
			pos[p]++;
		}
		rem+=total[p];
		pos[p]--;
		p++;
	}
	int c=cnt(pos);
	for(int i=1; i<=c; i++){
		Plus(pos);
		while(!check(pos)){
			Plus(pos);
dbg			for(int i=1; i<=type_n; i++)
dbg				printf("%d ",pos[i]);
dbg			printf("\n");
		}
	}
	
	For(i,type_n-1){
		for(map<string,int>::iterator it=mp[i].begin(); it!=mp[i].end(); ++it)
			if(it->second==pos[i]){
				printf("%s ",(it->first).c_str());
				break;
			}
	}
	for(map<string,int>::iterator it=mp[type_n].begin(); it!=mp[type_n].end(); ++it)
		if(it->second==pos[type_n]){
			printf("%s",(it->first).c_str());
			break;
		}
	return 0;
}

