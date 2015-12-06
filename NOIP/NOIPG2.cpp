#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <iostream>
#define PROB "string"
#define dbg if(0)
using namespace std;
string A,B,a[10],b[10];
int n=0;
struct Status{
	string str;
	int dist;
	Status(string a,int b):str(a),dist(b){}
	Status(){}
	bool operator<(const Status& rhs)const{
		return str<rhs.str;
	}
};
int bfs(){
	queue<Status> q;
	set<Status> vis;
	q.push(Status(A,0));
	vis.insert(Status(A,0));
	while(!q.empty()){
		Status p=q.front();
		q.pop();
		if(p.str==B)
			return p.dist;
		if(p.dist>=10)
			continue;
dbg		if(p.str=="abbaaba")
			cout<<p.str<<endl;
		for(int i=0; i<n; i++){
			Status t;
			t.dist=p.dist+1;
			t.str=p.str;
			for(int j=0; j<t.str.size(); j++)
				if(t.str.substr(j,a[i].size())==a[i]){
					t.str.erase(j,a[i].size());
					t.str.insert(j,b[i]);
					if(vis.insert(t).second)
						q.push(t);
					t.str=p.str;
				}
			if(vis.insert(t).second)
				q.push(t);
		}
	}
	return -1;
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	cin>>A>>B;
	while(cin>>a[n]>>b[n])
		n++;
	int ans=bfs();
	if(ans==-1)printf("NO ANSWER!");
	else printf("%d",ans);
	return 0;
}

