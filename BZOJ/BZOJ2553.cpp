#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>
#include <iomanip>
#define Rep(i,n) for(int i=0; i<n; i++)
using namespace std;

int n,m,asz;

#define SZ 100
#define idx(c) (c-'a')
int ch[SZ][26],sz=1,mark[SZ];
void insert(char *str){
	int u=0;
	while(*str){
		int i=idx(*str++);
		if(!ch[u][i])
			ch[u][i]=++sz;
		u=ch[u][i];
	}
	mark[u]=1;
}

int fa[SZ];
void calc_fa(){
	queue<int> q; 
	for(int i=0; i<26; i++)if(ch[0][i])
		q.push(ch[0][i]);
	while(!q.empty()){
		int r=q.front();q.pop();
		for(int c=0; c<asz; ++c){
			int &u=ch[r][c];
			if(!u){ch[r][c]=ch[fa[r]][c];continue;}
			fa[u]=ch[fa[r]][c];
			mark[u]|=mark[fa[u]];
			q.push(u);
		}
	}
}

int rc;
struct Mat{
	long double num[SZ][SZ];
	Mat(){memset(num,0,sizeof(num));}
	void init(){
		Rep(i,rc)num[i][i]=1;
	}
	Mat operator*(Mat &r){
		Mat ret;
		Rep(k,rc)Rep(j,rc)if(r[k][j]>0)
			Rep(i,rc)
				ret[i][j]+=num[i][k]*r[k][j];
		return ret;
	}
	long double* operator[](int x){return num[x];}
}a;
Mat fPow(Mat t,int p){
	Mat ret;
	ret.init();
	while(p){
		if(p&1)ret=ret*t;
		t=t*t;
		p>>=1;
	}
	return ret;
}

char str[20];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&asz);
	Rep(i,n){
		scanf("%s",str);
		insert(str);
	}
	calc_fa();
	for(int i=0; i<sz; i++)
		for(int j=0; j<asz; j++){
			if(mark[ch[i][j]]){
				a[i][0]+=1.0/asz;
				a[i][sz]+=1.0/asz;
			}else
				a[i][ch[i][j]]+=1.0/asz;
		}
	rc=sz+1;
	a[rc-1][rc-1]=1;
	a=fPow(a,m);
	cout<<fixed;
	cout<<setprecision(10)<<a[0][rc-1];
	return 0;
}

